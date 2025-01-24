#include "operators.h"
#include "../Literal/literal.h"


namespace ExpressionEvaluator {
    // Operator Factory Method, recive the token 
    std::unique_ptr<Operator> Operator::createOperator(const std::string& token) {
        if (token == "+") return std::make_unique<AddOperator>();
        if (token == "-") return std::make_unique<SubtractOperator>();
        if (token == "*") return std::make_unique<MultiplyOperator>();
        if (token == "/") return std::make_unique<DivideOperator>();
        if (token == "<") return std::make_unique<LessOperator>();
        if (token == ">") return std::make_unique<GreaterOperator>();
        if (token == "<=") return std::make_unique<LessEqualOperator>();
        if (token == ">=") return std::make_unique<GreaterEqualOperator>();
        if (token == "||") return std::make_unique<OrOperator>();
        if (token == "&&") return std::make_unique<AndOperator>();
        if (token == "==") return std::make_unique<EqualOperator>();
        if (token == "!=") return std::make_unique<NotEqualOperator>();
        if (token == "-") return std::make_unique<NegateOperator>();
        throw "Unkown operator"; // An unkown operator, throw error
    }

    // Arithmetic operators
    std::unique_ptr<Expression> AddOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<IntLiteral>(left.evaluateInt() + right.evaluateInt());
    }

    std::unique_ptr<Expression> SubtractOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<IntLiteral>(left.evaluateInt() - right.evaluateInt());
    }

    std::unique_ptr<Expression> MultiplyOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<IntLiteral>(left.evaluateInt() * right.evaluateInt());
    }

    std::unique_ptr<Expression> DivideOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        int divisor = right.evaluateInt();
        if (divisor == 0) { // Division by zero
            throw "Division by zero";
        }
        return std::make_unique<IntLiteral>(left.evaluateInt() / divisor);
    }

    // Comparison operators
    std::unique_ptr<Expression> LessOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateInt() < right.evaluateInt());
    }

    std::unique_ptr<Expression> GreaterOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateInt() > right.evaluateInt());
    }

    std::unique_ptr<Expression> LessEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateInt() <= right.evaluateInt());
    }

    std::unique_ptr<Expression> GreaterEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateInt() >= right.evaluateInt());
    }

    // Logical operators
    std::unique_ptr<Expression> OrOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateBool() || right.evaluateBool());
    }

    std::unique_ptr<Expression> AndOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        return std::make_unique<BoolLiteral>(left.evaluateBool() && right.evaluateBool());
    }

    std::unique_ptr<Expression> EqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        // For boolean expressions
        if (left.isBoolean() && right.isBoolean()) {
            return std::make_unique<BoolLiteral>(left.evaluateBool() == right.evaluateBool());
        }
        // For integer expressions
        return std::make_unique<BoolLiteral>(left.evaluateInt() == right.evaluateInt());
    }

    std::unique_ptr<Expression> NotEqualOperator::apply(
        const Expression& left, 
        const Expression& right
    ) const {
        // For boolean expressions
        if (left.isBoolean() && right.isBoolean()) {
            return std::make_unique<BoolLiteral>(left.evaluateBool() != right.evaluateBool());
        }
        // For integer expressions
        return std::make_unique<BoolLiteral>(left.evaluateInt() != right.evaluateInt());
    }

    // Unary operator
    std::unique_ptr<Expression> NegateOperator::apply(const Expression& expr) const {
        return std::make_unique<IntLiteral>(-expr.evaluateInt());
    }
}