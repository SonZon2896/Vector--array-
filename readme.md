# MyVector

## Возможности

### **Инициализация**

- только с указанием класса

```c++
myvector<int> myvec;
```

- с указанием размера

```c++
myvector<int> myvec(5);
```

- с указанием размера и стандартным заполнением, при этом не обязательно указывать класс

```c++
myvector myvec(5, 2);
```

### **работа с индексами**

- можно указать типы size_t и int, при этом отрицательные числа и числа, не подходящие по размеру, не будут вызывать ошибку, т.к. индексы идут циклично, как в python

```c++
myvec[-1] // обращение к последнему элементу вектора
```

### **работа с размером**

- `.reserve(size_t)` резервирует память, для оптимизации работы с добавлением элементов в вектор

```c++
myvector<int> myvec;
myvec.reserve(100); // можно добавить 100 элементов и не бояться за затраты компьютера
```

- `append(size_t index, class T value)` основная функция для добавления элемента в массив

```c++
myvec.append(2, 5); // добавление int 5 по индексу 2
```

- `append(size_t) index` - частный случаи выше описанной функции

```c++
myvec.append(3); // по 3 индексу будет элемет 'Point{0, 0}'
```

- `push_back(class T value)`, `push_back()` - добавляет элемент в конец вектора

```c++
myvector myvec<int>;

myvec.push_back(5); // добавит в конец вектора int 5
myvec.push_back(); // добавит в конец вектора int 0
```

- `emplace_back(Args args)` `emplace(size_t index, Args args)` - добавляет элемент по индексу или в конец массива по аргументам конструктора (Args), также вызывает оператор `new`

```c++
struct Point
{
    int x = 0, y = 0;
    Point() = default;
    Point(int x, int y) : x{x}, y{y} {}
};
myvector<Point> myvec_point;

myvec_point.emplace(2, 4, 4) // добавит по 2 индексу Point{4, 4}

myvec_point.emplace_back(2, 2) // добавит в конец Point{2, 2}
```

- `pop()`, `pop(size_t index)` - удаление последнего элемента или по индексу

```c++
myvector<int> myvec(5, 2);

myvec.pop(); // удалит последний элемент

myvec.pop(2); // удалит элемент по индексу 2
```

## Все реализованные функции на данный момент
* все функции протестированы в main.cpp
```c++
template <typename T>
class myvector
{
private:
    T *array;
    size_t size;
    size_t reserved_size;

public:
    myvector(size_t, T);
    myvector(int, T);
    myvector(size_t);
    myvector(int);
    myvector();

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
```

[**Гайд как сделать свой вектор**](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
