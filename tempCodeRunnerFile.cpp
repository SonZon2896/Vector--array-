#include <iostream>

struct Point
{
    int x, y;
    Point() {std::cout << "constructor" << std::endl;}
    ~Point() {std::cout << "destructor" << std::endl;}
};

int main()
{
    Point *a = new Point();
    delete a;
}