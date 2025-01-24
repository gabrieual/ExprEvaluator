#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <memory>
#include "../Expression/expression.h"

namespace ExpressionEvaluator {
    class Operator {
    public:
        virtual ~Operator() = default;
        virtual bool isBinary() const = 0;
        
        static std::unique_ptr<Operator> createOperator(const std::string& token);
    };

    class UnaryOperator : public Operator {
    public:
        bool isBinary() const override { return false; }
        virtual std::unique_ptr<Expression> apply(const Expression& expr) const = 0;
    };

    class BinaryOperator : public Operator {
    public:
        bool isBinary() const override { return true; }
        virtual std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const = 0;
    };

    // Arithmetic Operators
    class AddOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class SubtractOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class MultiplyOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class DivideOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    // Comparison Operators
    class LessOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class GreaterOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class LessEqualOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class GreaterEqualOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    // Logical Operators
    class OrOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class AndOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class EqualOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class NotEqualOperator : public BinaryOperator {
    public:
        std::unique_ptr<Expression> apply(
            const Expression& left, 
            const Expression& right
        ) const override;
    };

    class NegateOperator : public UnaryOperator {
    public:
        std::unique_ptr<Expression> apply(const Expression& expr) const override;
    };
}

#endif