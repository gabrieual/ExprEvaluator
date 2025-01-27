#ifndef LITERAL_H
#define LITERAL_H

#include "../Expression/expression.h"
#include <string>

namespace ExpressionEvaluator {
    class IntLiteral : public Expression {
    private:
        int value;

    public:
        explicit IntLiteral(int val); // explicit to not implict convert a type  
        explicit IntLiteral(const std::string& token); 
        ~IntLiteral() override = default; // Destructor
        IntLiteral(const IntLiteral& copied); // Copy constructor
        
        bool isBoolean() const override { return false; }
        int evaluateInt() const override { return value; }
        bool evaluateBool() const override { 
            throw "Cannot evaluate integer as boolean"; 
        }

        Expression* clone() const override { // Clone method
            return new IntLiteral(*this);
        }
    };

    class BoolLiteral : public Expression {
    private:
        bool value;

    public:
        explicit BoolLiteral(bool val);
        explicit BoolLiteral(const std::string& token);

        BoolLiteral(const BoolLiteral& copied); // Copy
        ~BoolLiteral() override = default;

        bool isBoolean() const override { return true; }
        int evaluateInt() const override { 
            throw "Cannot evaluate boolean as integer"; 
        }
        bool evaluateBool() const override { return value; }

        Expression* clone() const override { // Clone method
            return new BoolLiteral(*this);
        }

    };
}

#endif 