#include "Calculator.hpp"
#include <cmath>

double Calculator::add(double a, double b) const {
    return a + b;
}

double Calculator::subtract(double a, double b) const {
    return a - b;
}

double Calculator::multiply(double a, double b) const {
    return a * b;
}

double Calculator::divide(double a, double b) const {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

double Calculator::power(double base, double exponent) const {
    return std::pow(base, exponent);
}

double Calculator::squareRoot(double value) const {
    if (value < 0.0) {
        throw std::invalid_argument("Square root of negative number is not allowed.");
    }
    return std::sqrt(value);
}

double Calculator::modulo(double a, double b) const {
    if (b == 0.0) {
        throw std::invalid_argument("Modulo by zero is not allowed.");
    }
    return std::fmod(a, b);
}

double Calculator::percentage(double value, double percent) const {
    return (value * percent) / 100.0;
}

double Calculator::absolute(double value) const {
    return std::abs(value);
}

unsigned long long Calculator::factorial(int n) const {
    if (n < 0) {
        throw std::invalid_argument("Factorial of negative number is not allowed.");
    }
    if (n > 20) {
        throw std::overflow_error("Factorial input too large (max 20 for unsigned long long).");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= static_cast<unsigned long long>(i);
    }
    return result;
}

double Calculator::sin(double radians) const {
    return std::sin(radians);
}

double Calculator::cos(double radians) const {
    return std::cos(radians);
}

double Calculator::tan(double radians) const {
    return std::tan(radians);
}

double Calculator::log(double value) const {
    if (value <= 0.0) {
        throw std::invalid_argument("Logarithm of zero or negative number is not allowed.");
    }
    return std::log(value);
}

double Calculator::log10(double value) const {
    if (value <= 0.0) {
        throw std::invalid_argument("Logarithm base 10 of zero or negative number is not allowed.");
    }
    return std::log10(value);
}

double Calculator::exp(double value) const {
    return std::exp(value);
}
