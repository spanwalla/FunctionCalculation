#include <iostream>
#include "src/FunctionCalculation.h"
#include "src/QuadraticFunction.h"
#include "src/AbsFunction.h"
#include "src/CosineFunction.h"

int main() {
    // QuadraticFunction q(1, 2, 1);
    AbsFunction q(1, -5.3);
    // CosineFunction q(4, 2.1, -4, 49);
    FunctionCalculation calc(&q, 1, 10, 0.5);
    auto result = calc.ValuesAt(10, 6);
    for (const auto& p : result)
        std::cout << "(" << p.first << ", " << p.second << ") ";
    std::cout << '\n';

    std::cout << calc << std::endl;
    try {
        calc.saveCsv("csv", true);
    } catch(const std::runtime_error& e) {
        std::cout << "Error writing file: " << e.what() << std::endl;
    }
    return 0;
}
