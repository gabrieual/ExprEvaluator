#include "parser.h"
#include "../Literal/literal.h"
#include "../Expression/binary_expression.h"
#include "../Expression/unary_expression.h"
#include "../Operators/operators.h"

namespace ExpressionEvaluator {
    Parser::Parser(const std::string& input) : current(0) {
        int start = 0;
        
        for (int i = 0; i <= input.size(); ++i) {
            if (i == input.size() || input[i] == ' ') {
                if (i > start) {
                    tokens.push_back(input.substr(start, i - start));
                }
                start = i + 1;
            }
        }
    }

    Parser::~Parser(){}

    bool Parser::isEnd() const {
        return current >= tokens.size();
    }

    std::string Parser::peek() const {
        if (isEnd()) {
            throw "Unexpected end of input";
        }
        return tokens[current];
    }

    std::string Parser::consume() {
        if (isEnd()) { // Unexpected end of input, throw error
            throw "Unexpected end of input";
        }
        return tokens[current++];
    }

    Expression* Parser::parse() {
        Expression* expr = parseExpression();
        if (!isEnd()) { // Unexpeected tokens at end of expression
            delete expr;
            throw "Unexpeected tokens at end of expression";
        }
        return expr;
    }

    // recursive descent parser
    Expression* Parser::parseExpression() {
        return parseOrExpression();
    }

    Expression* Parser::parseOrExpression() {
        Expression* expr = parseAndExpression();
        
        while (!isEnd() && peek() == "||") {
            consume(); // consume "||"
            Operator* op = Operator::createOperator("||");
            Expression* right = parseAndExpression();
            Expression* newExpr = new BinaryExpression(
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );
            
            expr = newExpr;

        }
        return expr;
    }

    Expression* Parser::parseAndExpression() {
        Expression* expr = parseEqualityExpression();
        
        while (!isEnd() && peek() == "&&") {
            consume(); // consume "&&"
            Operator* op = Operator::createOperator("&&");
            Expression* right = parseAndExpression();
            Expression* newExpr = new BinaryExpression(
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );

            expr = newExpr;

        }
        return expr;
    }

    Expression* Parser::parseEqualityExpression() {
        Expression* expr = parseRelationalExpression();
        
        while (!isEnd() && (peek() == "==" || peek() == "!=")) {
            std::string opToken = consume();
            Operator* op = Operator::createOperator(opToken);
            Expression* right = parseRelationalExpression();
            Expression* newExpr = new BinaryExpression (
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );

            expr = newExpr;

        }
        return expr;
    }

    Expression* Parser::parseRelationalExpression() {
        Expression* expr = parseAdditiveExpression();
        
        while (!isEnd() && (peek() == "<" || peek() == ">" || peek() == "<=" || peek() == ">=")) {
            std::string opToken = consume();
            Operator* op = Operator::createOperator(opToken);
            Expression* right = parseAdditiveExpression();
            Expression* newExpr = new BinaryExpression (
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );

            expr = newExpr;

        }
        return expr;
    }

    Expression* Parser::parseAdditiveExpression() {
        Expression* expr = parseMultiplicativeExpression();
        
        while (!isEnd() && (peek() == "+" || peek() == "-")) {
            std::string opToken = consume();
            Operator* op = Operator::createOperator(opToken);
            Expression* right = parseMultiplicativeExpression();
            Expression* newExpr = new BinaryExpression (
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );

            expr = newExpr;

        }
        return expr;
    }

    Expression* Parser::parseMultiplicativeExpression() {
        Expression* expr = parseUnaryExpression();
        
        while (!isEnd() && (peek() == "*" || peek() == "/")) {
            std::string opToken = consume();
            Operator* op = Operator::createOperator(opToken);
            Expression* right = parseUnaryExpression();
            Expression* newExpr = new BinaryExpression (
                expr, 
                dynamic_cast<BinaryOperator*>(op), 
                right
            );

            expr = newExpr;
        }
        
        return expr;
    }

    Expression* Parser::parseUnaryExpression() {
        if (!isEnd() && peek() == "-") {
            consume(); // consume "-"
            Expression* expr = parseUnaryExpression(); // recursive call to handle nested "-"
            Expression* negatedExpr = new BinaryExpression( // expression will be (0 + -expression)
                new IntLiteral(0), 
                dynamic_cast<BinaryOperator*>(Operator::createOperator("+")),  // Convert to addition
                new BinaryExpression(
                    new IntLiteral(0),
                    dynamic_cast<BinaryOperator*>(Operator::createOperator("-")),
                    expr
                )
            );
            return negatedExpr;
        }
        return parsePrimaryExpression();
    }

    Expression* Parser::parsePrimaryExpression() {
        if (!isEnd() && peek() == "(") {
            consume(); // consume "("
            Expression* expr = parseExpression();
            if (isEnd() || consume() != ")") { // closing parenthesis missing
                throw "Expected closing parenthesis";
            }
            return expr;
        }

        if (!isEnd()) {
            std::string token = consume();
            try {
                return new IntLiteral(token);
            } catch (const char*) {
                try {
                    return new BoolLiteral(token);
                } catch (const std::runtime_error&) { // Unexpected token, throw error
                    throw "Unexpected token";
                }
            }
        }

        throw "Unexpected end of input";
    }
}