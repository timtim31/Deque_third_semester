#include "list.h"

template <typename T>
List<T>::List() : data(nullptr), size(0), capacity(0) {}

template <typename T>
List<T>::~List() 
{
    delete[] data;
}

template <typename T>
List<T>::List(const List& other) : size(other.size), capacity(other.capacity) 
{
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) 
    {
        data[i] = other.data[i];
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& other) 
{
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) 
    {
        data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
List<T>::List(List&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) 
{
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
List<T>& List<T>::operator=(List&& other) noexcept 
{
    if (this == &other) return *this;
    delete[] data;
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}

template <typename T>
void List<T>::resize(size_t new_capacity) 
{
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) 
    {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
void List<T>::add(T value) 
{
    if (size == capacity) 
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template <typename T>
void List<T>::remove(size_t index) 
{
    if (index >= size) 
    {
        std::cerr << "Индекс за пределами границы\n";
        return;
    }
    for (size_t i = index; i < size - 1; ++i) 
    {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
size_t List<T>::getSize() const 
{
    return size;
}

template <typename T>
T List<T>::get(size_t index) const 
{
    if (index >= size) 
    {
        std::cerr << "Индекс за пределами границы\n";
        return T(); // Возвращает значение по умолчанию
    }
    return data[index];
}

template <typename T>
std::string List<T>::toString() const 
{
    std::ostringstream oss;
    for (size_t i = 0; i < size; ++i) 
    {
        oss << data[i] << (i < size - 1 ? " " : "");
    }
    return oss.str();
}

template <typename T>
void List<T>::print() const 
{
    std::cout << toString() << "\n";
}

template <typename T>
void List<T>::inputElements() 
{
    std::cout << "Введите количество элементов: ";
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) 
    {
        std::cout << "Введите элемент " << i + 1 << ": ";
        T value;
        std::cin >> value;
        add(value);
    }
}

template <typename T>
void List<T>::removeElementByUser() 
{
    std::cout << "Введите индекс элемента для удаления: ";
    size_t index;
    std::cin >> index;
    remove(index);
}
