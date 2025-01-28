#include "operators.h"
#include "../Literal/literal.h"

namespace ExpressionEvaluator {
    // Factory method that returns a pointer to a operator based on the token
    Operator* Operator::createOperator(const std::string& token) {
        if (token == "+") return new AddOperator();
        if (token == "-") return new SubtractOperator();
        if (token == "*") return new MultiplyOperator();
        if (token == "/") return new DivideOperator();
        if (token == "<") return new LessOperator();
        if (token == ">") return new GreaterOperator();
        if (token == "<=") return new  LessEqualOperator();
        if (token == ">=") return new  GreaterEqualOperator();
        if (token == "||") return new  OrOperator();
        if (token == "&&") return new  AndOperator();
        if (token == "==") return new  EqualOperator();
        if (token == "!=") return new  NotEqualOperator();
        if (token == "-") return new NegateOperator();
        throw "Unkown operator"; // An unkown operator, throw error
    }

    // Arithmetic operators
    Expression* AddOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new IntLiteral (left.evaluateInt() + right.evaluateInt());
    }

    Expression* SubtractOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new IntLiteral (left.evaluateInt() - right.evaluateInt());
    }

    Expression* MultiplyOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new IntLiteral (left.evaluateInt() * right.evaluateInt());
    }

    Expression* DivideOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        int divisor = right.evaluateInt();
        if (divisor == 0) { // Division by zero
            throw "Division by zero";
        }
        return new IntLiteral (left.evaluateInt() / divisor);
    }

    // Comparison operators
    Expression* LessOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateInt() < right.evaluateInt());
    }

    Expression* GreaterOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateInt() > right.evaluateInt());
    }

    Expression* LessEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateInt() <= right.evaluateInt());
    }

    Expression* GreaterEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateInt() >= right.evaluateInt());
    }

    // Logical operators
    Expression* OrOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateBool() || right.evaluateBool());
    }

    Expression* AndOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return new BoolLiteral (left.evaluateBool() && right.evaluateBool());
    }

    Expression* EqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        // For boolean expressions
        if (left.isBoolean() && right.isBoolean()) {
            return new BoolLiteral (left.evaluateBool() == right.evaluateBool());
        }
        // For integer expressions
        return new BoolLiteral (left.evaluateInt() == right.evaluateInt());
    }

    Expression* NotEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        // For boolean expressions
        if (left.isBoolean() && right.isBoolean()) {
            return new BoolLiteral (left.evaluateBool() != right.evaluateBool());
        }
        // For integer expressions
        return new BoolLiteral (left.evaluateInt() != right.evaluateInt());
    }

    // Unary operator
    Expression* NegateOperator::apply(const Expression& expr) const {
        if (expr.isBoolean()) {
            throw "Cannot negate a boolean expression";
        }
        return new IntLiteral(-expr.evaluateInt());
    }
}
