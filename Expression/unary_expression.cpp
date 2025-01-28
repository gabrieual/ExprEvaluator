#include "unary_expression.h"

namespace ExpressionEvaluator {
    UnaryExpression::UnaryExpression(
        UnaryOperator* oper, 
        Expression* expression) : 
        expr(expression), 
        op(oper) 
    {}

    UnaryExpression::UnaryExpression(const UnaryExpression& copied) :
        expr(copied.expr->clone()),
        op(dynamic_cast<UnaryOperator*>(copied.op->clone()))
    {}

    UnaryExpression::~UnaryExpression() {
        delete expr;
        delete op;
    }

    bool UnaryExpression::isBoolean() const {
        return expr->isBoolean();
    }

    int UnaryExpression::evaluateInt() const {
        if (expr->isBoolean()) {
            throw "Tried evaluate boolean expression as integer";
        }
        return op->apply(*expr)->evaluateInt();
    }

    bool UnaryExpression::evaluateBool() const {
        if (!expr->isBoolean()) {
            throw "Tried evaluate integer expression as boolean";
        }
        return expr->evaluateBool();
    }

    Expression* UnaryExpression::clone() const {
        return new UnaryExpression(*this);
    }
}