#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include "../Expression/expression.h"

namespace ExpressionEvaluator {
    class Operator { // Abstract base class for unary and binary operators classes
    public:
        virtual ~Operator() = default;
        virtual bool isBinary() const = 0;
        virtual Operator* clone() const = 0;
        static Operator* createOperator(const std::string& token);
    };

    class UnaryOperator : public Operator {
    public:
        bool isBinary() const override { return false; }
        virtual Expression* apply(const Expression& expr) const = 0;
    };

    class BinaryOperator : public Operator {
    public:
        bool isBinary() const override { return true; }
        virtual Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const = 0;
    };

    // Arithmetic Operators
    class AddOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new AddOperator(*this);
        }
    };

    class SubtractOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new SubtractOperator(*this);
        }
    };

    class MultiplyOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new MultiplyOperator(*this);
        }
    };

    class DivideOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new DivideOperator(*this);
        }
    };

    // Comparison Operators
    class LessOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new LessOperator(*this);
        }
    };

    class GreaterOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new GreaterOperator(*this);
        }
    };

    class LessEqualOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new LessEqualOperator(*this);
        }
    };

    class GreaterEqualOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new GreaterEqualOperator(*this);
        }
    };

    // Logical Operators
    class OrOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        virtual Operator* clone() const override {
            return new OrOperator(*this);
        };
    };

    class AndOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new AndOperator(*this);
        }
    };

    class EqualOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new EqualOperator(*this);
        }
    };

    class NotEqualOperator : public BinaryOperator {
    public:
        Expression* apply(
            const Expression& left, 
            const Expression& right
        ) const override;

        Operator* clone() const override {
            return new NotEqualOperator(*this);
        }
    };

    class NegateOperator : public UnaryOperator {
    public:
        Expression* apply(const Expression& expr) const override;
    

    Operator* clone() const override {
            return new NegateOperator(*this);
        }
    };
};

#endif  