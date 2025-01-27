#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "../Expression/expression.h"

namespace ExpressionEvaluator {
    class Parser {
    private:
        std::vector<std::string> tokens;
        int current;

        bool isEnd() const;
        std::string peek() const;
        std::string consume();

        // Parsing methods for different expression levels
        Expression* parseExpression();
        Expression* parseOrExpression();
        Expression* parseAndExpression();
        Expression* parseEqualityExpression();
        Expression* parseRelationalExpression();
        Expression* parseAdditiveExpression();
        Expression* parseMultiplicativeExpression();
        Expression* parseUnaryExpression();
        Expression* parsePrimaryExpression();

    public:
        Parser(const std::string& input);
        ~Parser();

        Expression* parse();
    };
}

#endif 