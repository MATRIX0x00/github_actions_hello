#include <iostream>
#include "Calculator.hpp"

int main() {
    std::cout << "=== C++ Enhanced Application Starting (v2.0) ===" << std::endl;

    Calculator calc;
    double a = 9.0;
    double b = 2.0;

    std::cout << "Operand A: " << a << ", Operand B: " << b << std::endl;
    std::cout << "Addition: " << calc.add(a, b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(a, b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(a, b) << std::endl;

    try {
        std::cout << "Division: " << calc.divide(a, b) << std::endl;
        std::cout << "Power (A ^ B): " << calc.power(a, b) << std::endl;
        std::cout << "Square Root (A): " << calc.squareRoot(a) << std::endl;
        std::cout << "Modulo (A % B): " << calc.modulo(a, b) << std::endl;
        std::cout << "Percentage (50% of A): " << calc.percentage(a, 50.0) << std::endl;
        std::cout << "Absolute (-15.5): " << calc.absolute(-15.5) << std::endl;
        std::cout << "Factorial (5!): " << calc.factorial(5) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== C++ Application Finished Successfully ===" << std::endl;
    return 0;
}
