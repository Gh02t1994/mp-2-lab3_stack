#include "tarithmeticexpression.h"

#include <gtest.h>

TEST(TArithmeticExpression, get_operands)
{
    TArithmeticExpression expr("a+b*c");

    vector<char> expected = {'a', 'b', 'c'};

    EXPECT_EQ(expr.GetOperands(), expected);
}

TEST(TArithmeticExpression, calculate_addition)
{
    TArithmeticExpression expr("a+b");

    map<char, double> values = {
        {'a', 2},
        {'b', 3}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 5);
}

TEST(TArithmeticExpression, calculate_subtraction)
{
    TArithmeticExpression expr("a-b");

    map<char, double> values = {
        {'a', 10},
        {'b', 4}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 6);
}

TEST(TArithmeticExpression, calculate_multiplication)
{
    TArithmeticExpression expr("a*b");

    map<char, double> values = {
        {'a', 4},
        {'b', 5}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 20);
}

TEST(TArithmeticExpression, calculate_division)
{
    TArithmeticExpression expr("a/b");

    map<char, double> values = {
        {'a', 10},
        {'b', 2}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 5);
}

TEST(TArithmeticExpression, multiplication_priority)
{
    TArithmeticExpression expr("a+b*c");

    map<char, double> values = {
        {'a', 2},
        {'b', 3},
        {'c', 4}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 14);
}

TEST(TArithmeticExpression, brackets_priority)
{
    TArithmeticExpression expr("(a+b)*c");

    map<char, double> values = {
        {'a', 2},
        {'b', 3},
        {'c', 4}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 20);
}

TEST(TArithmeticExpression, complex_expression)
{
    TArithmeticExpression expr("a+b*c-d");

    map<char, double> values = {
        {'a', 10},
        {'b', 2},
        {'c', 3},
        {'d', 4}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 12);
}

TEST(TArithmeticExpression, subtraction_order)
{
    TArithmeticExpression expr("a-b-c");

    map<char, double> values = {
        {'a', 10},
        {'b', 3},
        {'c', 2}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 5);
}

TEST(TArithmeticExpression, division_order)
{
    TArithmeticExpression expr("a/b/c");

    map<char, double> values = {
        {'a', 24},
        {'b', 4},
        {'c', 2}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values), 3);
}

TEST(TArithmeticExpression, division_by_zero)
{
    TArithmeticExpression expr("a/b");

    map<char, double> values = {
        {'a', 10},
        {'b', 0}
    };

    EXPECT_THROW(expr.Calculate(values), runtime_error);
}

TEST(TArithmeticExpression, calculate_multiple_times)
{
    TArithmeticExpression expr("a+b");

    map<char, double> values1 = {
        {'a', 2},
        {'b', 3}
    };

    map<char, double> values2 = {
        {'a', 10},
        {'b', 20}
    };

    EXPECT_DOUBLE_EQ(expr.Calculate(values1), 5);
    EXPECT_DOUBLE_EQ(expr.Calculate(values2), 30);
}
