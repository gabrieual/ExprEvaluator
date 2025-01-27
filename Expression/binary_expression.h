#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

#include "expression.h"
#include "../Operators/operators.h"

namespace ExpressionEvaluator {
    class BinaryExpression : public Expression {
    private:
        Expression* left;
        Expression* right;
        BinaryOperator* op;

    public:
        BinaryExpression(
            Expression* leftExpr, 
            BinaryOperator* oper, 
            Expression* rightExpr
        );
        BinaryExpression(const BinaryExpression& copied);
        ~BinaryExpression() override;

        bool isBoolean() const override;
        int evaluateInt() const override;
        bool evaluateBool() const override;

        Expression* clone() const override;
    };
}

#endif