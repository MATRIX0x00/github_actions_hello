#include <iostream>
#include <cassert>
#include <cmath>
#include "Calculator.hpp"

void test_add() {
    Calculator calc;
    assert(calc.add(2.0, 3.0) == 5.0);
    assert(calc.add(-1.0, 1.0) == 0.0);
    std::cout << "test_add passed!" << std::endl;
}

void test_subtract() {
    Calculator calc;
    assert(calc.subtract(5.0, 3.0) == 2.0);
    assert(calc.subtract(0.0, 5.0) == -5.0);
    std::cout << "test_subtract passed!" << std::endl;
}

void test_multiply() {
    Calculator calc;
    assert(calc.multiply(4.0, 2.5) == 10.0);
    assert(calc.multiply(-2.0, 3.0) == -6.0);
    std::cout << "test_multiply passed!" << std::endl;
}

void test_divide() {
    Calculator calc;
    assert(calc.divide(10.0, 2.0) == 5.0);
    
    bool exceptionThrown = false;
    try {
        calc.divide(5.0, 0.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "test_divide passed!" << std::endl;
}

void test_advanced() {
    Calculator calc;
    assert(calc.power(2.0, 3.0) == 8.0);
    assert(calc.squareRoot(16.0) == 4.0);

    bool exceptionThrown = false;
    try {
        calc.squareRoot(-4.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "test_advanced passed!" << std::endl;
}

void test_extra_features() {
    Calculator calc;
    assert(calc.modulo(9.0, 4.0) == 1.0);
    assert(calc.percentage(200.0, 15.0) == 30.0);
    assert(calc.absolute(-42.5) == 42.5);
    assert(calc.factorial(5) == 120);

    bool exceptionThrown = false;
    try {
        calc.modulo(5.0, 0.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        calc.factorial(-1);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "test_extra_features passed!" << std::endl;
}

void test_scientific() {
    Calculator calc;
    assert(std::abs(calc.sin(0.0) - 0.0) < 1e-9);
    assert(std::abs(calc.cos(0.0) - 1.0) < 1e-9);
    assert(std::abs(calc.log(1.0) - 0.0) < 1e-9);
    assert(std::abs(calc.log10(100.0) - 2.0) < 1e-9);
    assert(std::abs(calc.exp(0.0) - 1.0) < 1e-9);

    bool exceptionThrown = false;
    try {
        calc.log(0.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);

    exceptionThrown = false;
    try {
        calc.log10(-5.0);
    } catch (const std::invalid_argument&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "test_scientific passed!" << std::endl;
}

int main() {
    std::cout << "Running Enhanced Calculator Unit Tests v2.1..." << std::endl;
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    test_advanced();
    test_extra_features();
    test_scientific();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
