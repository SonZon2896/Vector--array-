#pragma once
#include <iostream>

template <typename T>
class vector
{
private:
    T* array;
    size_t size;

public:
    vector();
    vector(size_t);
    vector(size_t, T);

    int Size();

    T& operator[](size_t);
    T operator=(vector<T>);
    
    void PrintArray();

    void append();
    T append(T);
    T append(size_t, T);
    T pop();
    T pop(size_t);
    void resize(size_t);

    ~vector();
};


#define IsVectorCppNotWorking
#ifdef IsVectorCppNotWorking
#include "../cpp/vector.cpp"
#endif