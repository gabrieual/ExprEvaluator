#include <iostream>
#include <sstream>
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
            // Parse the expression
            ExpressionEvaluator::Parser parser(line);
            auto expression = parser.parse();

            // Evaluate and print the result
            if (expression->isBoolean()) {
                std::cout << (expression->evaluateBool() ? "true" : "false") << std::endl;
            } else {
                std::cout << expression->evaluateInt() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "error" << std::endl;
        }
    }

    return 0;
}