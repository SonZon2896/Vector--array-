#include "myvector.h"

template <typename T>
myvector<T>::myvector()
{
    reserved_size = 0;
    size = 0;
    array = new T[0];
}

template <typename T>
myvector<T>::myvector(size_t size)
{
    reserved_size = 0;
    this->size = size;
    array = new T[size];
}

template <typename T>
myvector<T>::myvector(size_t size, T value)
{
    reserved_size = 0;
    this->size = size;
    array = new T[size];
    for (size_t i = 0; i < size; ++i)
        array[i] = value;
}

template <typename T>
size_t myvector<T>::Size() const
{
    return size;
}

template <typename T>
T &myvector<T>::operator[](int index)
{
    if (index < 0)
        return array[(int)size + index % (int)size];
    return array[index % (int)size];
}

template <typename T>
T &myvector<T>::operator[](size_t index)
{
    return array[index % size];
}

template <typename T>
myvector<T>& myvector<T>::reserve(size_t size)
{
    if (reserved_size >= size)
    {
        return *this;
    }
    reserved_size = size;
    T* temp = array;
    array = new T[reserved_size];
    for (size_t i = 0; i < this->size; ++i)
        array[i] = temp[i];
    delete temp;
    return *this;
}

template <typename T>
T &myvector<T>::append(size_t index, T value)
{
    if (index > size)
        throw std::runtime_error("going beyond borders");
    if (++size > reserved_size)
    {
        reserved_size = 0;
        auto temp = array;
        array = new T[size];
        for (size_t i = 0; i < index; ++i)
            array[i] = temp[i];
        for (size_t i = index; i < size - 1; ++i)
            array[i + 1] = temp[i];
        delete[] temp;
    }
    else
        for (size_t i = size - 1; i > index; --i)
            array[i] = array[i - 1];
    return array[index] = value;
}

template <typename T>
template <typename... Args>
T &myvector<T>::emplace(size_t index, Args&&... args)
{
    return append(index, *(new T(std::forward<Args>(args)...)));
}

template <typename T>
T &myvector<T>::append(size_t index)
{
    return append(index, T());
}

template <typename T>
T &myvector<T>::push_back(T value)
{
    return append(size, value);
}

template <typename T>
template <typename... Args>
T &myvector<T>::emplace_back(Args &&...args)
{
    return append(size, *(new T(std::forward<Args>(args)...)));
}

template <typename T>
T &myvector<T>::push_back()
{
    return append(size, T());
}

template <typename T>
T myvector<T>::pop(size_t index)
{
    if (index >= size)
        throw std::runtime_error("going beyond borders");
    reserved_size = std::max(reserved_size, size--);
    T returned = array[index];
    for (size_t i = index; i < size; ++i)
        array[i] = array[i + 1];
    return returned;
}

template <typename T>
T myvector<T>::pop()
{
    return pop(size - 1);
}

template <typename T>
myvector<T>::~myvector()
{
    delete[] array;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, myvector<T> &vec)
{
    for (size_t i = 0; i < vec.Size(); ++i)
        os << vec[i] << ' ';
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, myvector<T> &vec)
{
    for (size_t i = 0; i < vec.Size(); ++i)
        is >> vec[i];
    return is;
}