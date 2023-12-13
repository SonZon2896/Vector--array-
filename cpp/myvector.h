#pragma once
#include <iostream>

template <typename T>
class myvector
{
private:
    T *array;
    size_t size;
    size_t reserved_size;

public:
    myvector();
    myvector(size_t);
    myvector(size_t, T);

    size_t Size() const;

    T &operator[](int) const;
    T &operator[](size_t) const;

    myvector<T>& reserve(size_t);
    T &append(size_t, T);
    T &append(size_t);
    template<typename... Args>
    T &emplace(size_t, Args &&...);
    template <typename... Args>
    T &emplace_back(Args &&...);
    T &push_back(T);
    T &push_back();
    T pop(size_t);
    T pop();

    ~myvector();
};