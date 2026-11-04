#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <stdexcept>

class Calculator {
public:
    double add(double a, double b) const;
    double subtract(double a, double b) const;
    double multiply(double a, double b) const;
    double divide(double a, double b) const;
};

#endif // CALCULATOR_HPP
