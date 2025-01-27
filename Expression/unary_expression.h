#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H

#include "expression.h"
#include "../Operators/operators.h"

namespace ExpressionEvaluator {
    class UnaryExpression : public Expression {
    private:
        Expression* expr;
        UnaryOperator* op;

    public:
        UnaryExpression(
            UnaryOperator* oper, 
            Expression* expression
        );

        UnaryExpression(const UnaryExpression& copied); // Copy
        ~UnaryExpression() override;

        bool isBoolean() const override;
        int evaluateInt() const override;
        bool evaluateBool() const override;

        Expression* clone() const override;
    };
}

#endif