#include "binary_expression.h"

namespace ExpressionEvaluator {
    BinaryExpression::BinaryExpression(
        Expression* leftExpr, 
        BinaryOperator* oper, 
        Expression* rightExpr) : 
        left(leftExpr), 
        right(rightExpr), 
        op(oper) 
    {}

    BinaryExpression::BinaryExpression(const BinaryExpression& copied) :
        left(copied.left->clone()),
        right(copied.right->clone()),
        op(dynamic_cast<BinaryOperator*>(copied.op->clone()))
    {}

    BinaryExpression::~BinaryExpression() {
        delete left;
        delete right;
        delete op;
    }

    bool BinaryExpression::isBoolean() const {
        // Determine if the result is a boolean based on the operator
        return op->apply(*left, *right)->isBoolean();
    }

    int BinaryExpression::evaluateInt() const {
        if (isBoolean()) {
            throw "Tried evaluate boolean expression as integer";
        }
        return op->apply(*left, *right)->evaluateInt();
    }

    bool BinaryExpression::evaluateBool() const {
        if (!isBoolean()) {
            throw "Tried evaluate integer expression as boolean";
        }
        return op->apply(*left, *right)->evaluateBool();
    }
    
    Expression* BinaryExpression::clone() const {
        return new BinaryExpression(*this);
    }
}