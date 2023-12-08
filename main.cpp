#include "cpp/myvector.hpp"
#include <iostream>
// #include <vector>
#include <string>

struct Point
{
    int x, y;
    Point() = default;
    Point(int x, int y) : x{x}, y{y} {}
    Point &operator=(const Point& second)
    {
        this->x = second.x;
        this->y = second.y;
        return *this;
    }
};

std::ostream &operator<<(std::ostream &os, const Point& point)
{
    return os << '{' << point.x << ' ' << point.y << '}';
}

int main()
{
    myvector<Point> vec(5);
    vec.reserve(15);
    for (size_t i = 0; i < 5; ++i)
    {
        vec.emplace_back(i, i + 1);
        std::cout << vec << std::endl;
    }
    std::cout << std::endl;
    vec.emplace_back(2, 5);
    std::cout << vec << std::endl;
    vec.append(2, (void *)(new Point(10, 20)));
    std::cout << vec << std::endl;
    vec.append(4, {20, 10});
    std::cout << vec << std::endl;
    vec.push_back();
    std::cout << vec << std::endl;

    return 0;
}