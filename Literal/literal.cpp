#include "literal.h"
#include <stdexcept>

namespace ExpressionEvaluator {
    // Integer literals
    IntLiteral::IntLiteral(int val) : value(val) {}

    IntLiteral::IntLiteral(const std::string& token) {
        try {
            value = std::stoi(token);
        } catch (const std::invalid_argument& e) {
            throw "Invalid integer literal";
        }
    }

    IntLiteral::IntLiteral(const IntLiteral& copied) : value(copied.value) {}

    // Booleans literals
    BoolLiteral::BoolLiteral(bool val) : value(val) {}

    BoolLiteral::BoolLiteral(const std::string& token) {
        if (token == "true") {
            value = true;
        } else if (token == "false") {
            value = false;
        } else {
            throw "Invalid boolean literal";
        }
    }

    BoolLiteral::BoolLiteral(const BoolLiteral& copied) : value(copied.value) {}
}