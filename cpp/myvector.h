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

    T &operator[](int);
    T &operator[](size_t);
    auto operator[](std::pair<size_t, size_t>);
    auto operator=(myvector<T>);

    void reserve(size_t);
    T &append(size_t, void *);
    T &append(size_t, T);
    T &append(size_t);
    template <typename... Args>
    T &emplace_back(Args &&...args);
    T &push_back(T);
    T &push_back();
    T pop(size_t);
    T pop();

    ~myvector();
};