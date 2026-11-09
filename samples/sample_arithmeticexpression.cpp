#include <iostream>
#include <map>
#include "tarithmeticexpression.h"

int main()
{
    TArithmeticExpression expression("a+b*c");
    const std::map<char, double> values = {
        {'a', 2.0},
        {'b', 3.0},
        {'c', 4.0}
    };

    std::cout << "Значение выражения a+b*c: " << expression.Calculate(values) << '\n';

    return 0;
}
