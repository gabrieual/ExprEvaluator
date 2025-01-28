#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

namespace ExpressionEvaluator {
    class Expression { // Abstract base class for all expressions
    public:
        virtual ~Expression() = default;
        
        // Pure virtual method to evaluate the expression
        virtual bool isBoolean() const = 0;
        virtual int evaluateInt() const = 0;
        virtual bool evaluateBool() const = 0;
        
        // Factory method for creating expressions
        static Expression* createExpression(const std::string& token);

        virtual Expression* clone() const = 0; // Virtual clone method
    };
}

#endif

