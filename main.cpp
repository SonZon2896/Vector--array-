#include "headers/vector.h"
#include <iostream>
#include <vector>

int main()
{
    size_t size;
    int value;
    std::cin >> size >> value;
    vector<int> array(size, value);
    array.PrintArray();
    for (int i = 0; i < array.Size(); i++)
        std::cin >> array[i];
    array.PrintArray();

    array.append(2, 4);
    array.PrintArray();
    array.pop(3);
    array.PrintArray();
    array.resize(10);
    array.PrintArray();

    return 0;
}