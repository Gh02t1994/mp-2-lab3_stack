#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Stack
{
  private:
    T* pMem = nullptr;
    int sz;
    int top;

  public:
    Stack(size_t n = 1): pMem(new T[n]), sz(n), top(-1)
    {
    }

    ~Stack()
    {
      delete[] pMem;
    }

    Stack(const Stack& s)
    {
      sz = s.sz;
      pMem = new T[sz];
      top = s.top;

      for (int i = 0; i <= top; i++)
        pMem[i] = s.pMem[i];
    }

    Stack(Stack&& s) noexcept
    {
      sz = s.sz;
      pMem = s.pMem;
      top = s.top;

      s.sz = 0;
      s.pMem = nullptr;
      s.top = -1;
    }

    bool IsEmpty() //Stack<T>:: - нужно если описание будет в дургом месте и начинается с template<class T>
    {
      return top < 0;
    }

    bool IsFull()
    {
      return top >= sz - 1;
    }

    void push(const T& val)
    {
      if (!IsFull())
      {
        pMem[++top] = val;
      }
      else
      {
        throw out_of_range("Full stack");
      }
    }

    T get()
    {
      if (!IsEmpty())
      {
        return pMem[top];
      }
      else
      {
        throw out_of_range("Empty stack");
      }
    }

    void pop()
    {
      if (!IsEmpty())
      {
          --top;
      }
      else
      {
          throw out_of_range("Empty stack");
      }
    }
};

#endif
