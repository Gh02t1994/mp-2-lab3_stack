#ifndef T_ARITHMETIC_EXPRESSION
#define T_ARITHMETIC_EXPRESSION

#include <iostream>
#include <map>
#include <vector>
#include "tstack.h"

using namespace std;

class TArithmeticExpression
{
  private:
    string infix;
    string postfix;
    vector<char> lexem;
    map<char, int> priority;
    map<char, double> operands;

    void Parse();
    void ToPostfix();
  public:
    TArithmeticExpression(string infx);

    vector<char> GetOperands() const;

    double Calculate(const map<char, double>& values);
};

#endif
