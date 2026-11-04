#iostream is needed
#include <iostream>
#include "Calculator.hpp"

int main() {
    std::cout << "=== C++ Application Starting ===" << std::endl;

    Calculator calc;
    double a = 10.5;
    double b = 2.5;

    std::cout << "Operand A: " << a << ", Operand B: " << b << std::endl;
    std::cout << "Addition: " << calc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(a, b) << std::endl;

    try {
        std::cout << "Division: " << calc.divide(a, b) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== C++ Application Finished Successfully ===" << std::endl;
    return 0;
}
