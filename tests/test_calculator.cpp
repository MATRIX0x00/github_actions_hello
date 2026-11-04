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

int main() {
    std::cout << "Running Calculator Unit Tests..." << std::endl;
    test_add();
    test_subtract();
    test_multiply();
    test_divide();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
