#include <iostream>
#include <string>
#include "Parser/parser.h"
#include "Expression/expression.h"

int main() {
    int cases;
    std::cin >> cases;
    std::cin.ignore();

    for (int i = 0; i < cases; ++i) {
        std::string line;
        std::getline(std::cin, line);

        try {
            ExpressionEvaluator::Expression* expression = nullptr;
            
            // Parse the expression
            ExpressionEvaluator::Parser parser(line);
            expression = parser.parse();

            // Evaluate and print the result
            if (expression->isBoolean()) {
                std::cout << (expression->evaluateBool() ? "true" : "false") << std::endl;
            } else {
                std::cout << expression->evaluateInt() << std::endl;
            }
            
            delete expression;

        } catch (const char* error) {
            std::cout << "error" << std::endl;
        }
    }

    return 0;
}