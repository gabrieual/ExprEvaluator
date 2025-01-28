#include "expression.h"
#include "../Literal/literal.h"

namespace ExpressionEvaluator
{
    // Static factory method to create expressions from tokens
    Expression*
    Expression::createExpression(const std::string &token){
        try{ // First try to create an bool literal
            return new BoolLiteral(token);
        }
        catch (const char*){
            try{ // If not an boolean, try int literal
                return new IntLiteral(token);
            }
            catch (const char*){ // If neither, throw an error
                throw "Unkown literal";
            }
        }
    }
}
