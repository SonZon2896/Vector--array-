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
    // vec.reserve(15);
    for (size_t i = 0; i < 5; ++i)
    {
        vec[i] = {i, i + 1};
        std::cout << "vec[i] = {i, i + 1}\t" << vec << std::endl;
    }
    std::cout << "Size()\t\t\t" << vec.Size() << std::endl;
    std::cout << std::endl;
    vec.emplace_back(0, 10);
    std::cout << "emplace_back(0, 10)\t" << vec << std::endl;
    vec.emplace(3, 10, 20);
    std::cout << "emplace(3, 10, 20)\t" << vec << std::endl;
    vec.append(2);
    std::cout << "append(2)\t\t" << vec << std::endl;
    vec.append(4, {20, 30});
    std::cout << "append(4, {20, 30})\t" << vec << std::endl;
    vec.push_back({30, 40});
    std::cout << "push_back({30, 40})\t" << vec << std::endl;
    vec.push_back();
    std::cout << "push_back()\t\t" << vec << std::endl;
    vec.pop(2);
    std::cout << "pop(2)\t\t\t" << vec << std::endl;
    vec.pop();
    std::cout << "pop()\t\t\t" << vec << std::endl;
    vec.reserve(5);
    vec.reserve(20);
    std::cout << "vec[2]\t\t\t" << vec[2] << std::endl; 
    std::cout << "vec[-1]\t\t\t" << vec[-1] << std::endl; 
    std::cout << "vec.Size()\t\t" << vec.Size() << std::endl;

    return 0;
}