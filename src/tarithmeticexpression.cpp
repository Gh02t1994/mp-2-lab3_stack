#include "tarithmeticexpression.h"

void TArithmeticExpression::Parse()
{
    for (char c : infix)
        lexem.push_back(c);
}

void TArithmeticExpression::ToPostfix()
{
    Parse();
    char StackItem;
    Stack<char> st(lexem.size());

    for (char item : lexem)
    {
        switch (item)
        {
            case '(':
                st.push(item);
                break;

            case ')':
                StackItem = st.get(); // хотя в методичке написано top() - в .h такого нет
                st.pop();

                while (StackItem != '(')
                {
                    postfix += StackItem;
                    StackItem = st.get();
                    st.pop();
                }

                break;

            case '+': case '-': case '*': case '/':
                while (!st.IsEmpty())
                {
                    StackItem = st.get();
                    st.pop();

                    if (priority[item] <= priority[StackItem])
                        postfix += StackItem;
                    else
                    {
                        st.push(StackItem);
                        break;
                    }
                }

                st.push(item);
                break;

            default:
                operands.insert({item, 0.0});
                postfix += item;
        }
    }

    while (!st.IsEmpty())
    {
        StackItem = st.get();
        st.pop();
        postfix += StackItem;
    }
}

TArithmeticExpression::TArithmeticExpression(string infx)
{
    infix = infx;
    priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    ToPostfix();
}

vector<char> TArithmeticExpression::GetOperands() const
{
    vector<char> tmp;

    for (const auto& item : operands)
        tmp.push_back(item.first);
    
    return tmp;
}

double TArithmeticExpression::Calculate(const map<char, double>& values)
{
    try
    {
        for (auto& val : values)
            operands.at(val.first) = val.second;

        Stack<double> st(postfix.size());
        double left, right;

        for (char lexem : postfix)
        {
            switch (lexem)
            {
                case '+':
                    right = st.get(); st.pop();
                    left = st.get(); st.pop();
                    st.push(left + right);
                    break;
                
                case '-':
                    right = st.get(); st.pop();
                    left = st.get(); st.pop();
                    st.push(left - right);
                    break;

                case '*':
                    right = st.get(); st.pop();
                    left = st.get(); st.pop();
                    st.push(left * right);
                    break;

                case '/':
                    right = st.get(); st.pop();
                    if (right == 0)
                        throw runtime_error("Division by zero");
                    
                    left = st.get(); st.pop();
                    st.push(left / right);
                    break;
                
                default:
                    st.push(operands[lexem]);
            }
        }

        return st.get();
    }
    catch (const exception& e)
    {
        cerr << "Calculation error" << endl;
        throw;
    }
}
