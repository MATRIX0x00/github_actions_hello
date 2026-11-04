#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <stdexcept>

class Calculator {
public:
    double add(double a, double b) const;
    double subtract(double a, double b) const;
    double multiply(double a, double b) const;
    double divide(double a, double b) const;
    double power(double base, double exponent) const;
    double squareRoot(double value) const;
    double modulo(double a, double b) const;
    double percentage(double value, double percent) const;
    double absolute(double value) const;
    unsigned long long factorial(int n) const;

    // Scientific functions
    double sin(double radians) const;
    double cos(double radians) const;
    double tan(double radians) const;
    double log(double value) const;
    double log10(double value) const;
    double exp(double value) const;
};

#endif // CALCULATOR_HPP
