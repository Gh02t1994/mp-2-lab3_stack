#include <iostream>
#include "tstack.h"

int main()
{
    Stack<int> values(3);

    values.push(10);
    values.push(20);
    values.push(30);

    std::cout << "Верхний элемент стека: " << values.get() << '\n';

    values.pop();
    std::cout << "После удаления верхнего элемента: " << values.get() << '\n';

    return 0;
}
