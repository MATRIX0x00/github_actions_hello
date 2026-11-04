#include <iostream>
#include "Calculator.hpp"

int main() {
    std::cout << "=== C++ Enhanced Scientific Application Starting (v2.1) ===" << std::endl;

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
        
        // Scientific demonstrations
        std::cout << "Sine (0.0 rad): " << calc.sin(0.0) << std::endl;
        std::cout << "Cosine (0.0 rad): " << calc.cos(0.0) << std::endl;
        std::cout << "Natural Log (e): " << calc.log(2.718281828459045) << std::endl;
        std::cout << "Log Base 10 (100.0): " << calc.log10(100.0) << std::endl;
        std::cout << "Exponential (1.0): " << calc.exp(1.0) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "=== C++ Application Finished Successfully ===" << std::endl;
    return 0;
}
