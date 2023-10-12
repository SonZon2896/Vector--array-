#ifndef IsVectorCppNotWorking
#include "../headers/vector.h"
#endif

template<typename T>
vector<T>::vector()
{
    size = 0;
    array = new T(this->size);
}

template<typename T>
vector<T>::vector(size_t size)
{
    this->size = size;
    array = new T(this->size);
}

template<typename T>
vector<T>::vector(size_t size, T value)
{
    this->size = size;
    array = new T(this->size);
    for (int i = 0; i < size; i++)
        array[i] = value;
}

template<typename T>
int vector<T>::Size()
{
    return size;
}

template<typename T>
T& vector<T>::operator[](size_t ind)
{
    if (ind >= size)
        throw std::runtime_error("you have gone beyond the array boundaries");
    return array[ind];
}

template <typename T>
T vector<T>::operator=(vector<T> second)
{
    delete[] array;
    size = second.size();
    array = new T(size);
    for (int i = 0; i < size; i++)
        array[i] = second[i];
    return *this;
}

template<typename T>
void vector<T>::PrintArray()
{
    std::cout << '[';
    for (int i = 0; i < size; i++)
        std::cout << array[i] << (i != size - 1 ? ", " : "]");
    std::cout << std::endl;
}

template<typename T>
void vector<T>::append()
{
    T* temp = new T(size + 1);
    for (int i = 0; i < size; i++)
        temp[i] = array[i];
    delete[] array;
    array = temp;
}

template<typename T>
T vector<T>::append(T value)
{
    T* temp = new T(size + 1);
    for (int i = 0; i < size; i++)
        temp[i] = array[i];
    temp[size] = value;
    delete[] array;
    array = temp;
    size++;
    return value;
}

template<typename T>
T vector<T>::append(size_t ind, T value)
{
    if (ind > size)
        throw std::runtime_error("you have gone beyond the array boundaries");
    T* temp = new T(size + 1);
    for (int i = 0; i < ind; i++)
        temp[i] = array[i];
    temp[ind] = value;
    for (int i = ind + 1; i < size + 1; i++)
        temp[i] = array[i-1];
    delete[] array;
    array = temp;
    size++;
    return value;
}

template <typename T>
T vector<T>::pop()
{
    if (size < 1)
        throw std::runtime_error("you have gone beyond the array boundaries");
    T* temp = new T(size - 1);
    for (int i = 0; i < size - 1; i++)
        temp[i] = array[i];
    int returned = array[size - 1];
    delete[] array;
    array = temp;
    size--;
    return returned;
}

template <typename T>
T vector<T>::pop(size_t ind)
{
    if (ind >= size)
        throw std::runtime_error("you have gone beyond the array boundaries");
    T* temp = new T(size - 1);
    for (int i = 0; i < ind; i++)
        temp[i] = array[i];
    for (int i = ind + 1; i < size; i++)
        temp[i-1] = array[i];
    int returned = array[ind];
    delete[] array;
    array = temp;
    size--;
    return returned;
}

template<typename T>
void vector<T>::resize(size_t newsize)
{
    T* temp = new T(newsize);
    for (int i = 0; i < std::min(size, newsize); i++)
        temp[i] = array[i];
    delete[] array;
    array = temp;
    size = newsize;
}

template <typename T>
vector<T>::~vector()
{
    delete[] array;
}
