#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <stdexcept>

/**
 * @brief Шаблонный класс списка.
 * @tparam T Тип элементов списка.
 */
template <typename T>
class List 
{
private:
    T* data; ///< Указатель на массив данных.
    size_t size; ///< Текущее количество элементов в списке.
    size_t capacity; ///< Максимальная вместимость списка.

    /**
     * @brief Изменяет размер внутреннего массива.
     * @param new_capacity Новый размер массива.
     */
    void resize(size_t new_capacity);

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    List();

    /**
     * @brief Деструктор.
     */
    ~List();

    /**
     * @brief Конструктор копирования.
     * @param other Другой список для копирования.
     */
    List(const List& other);

    /**
     * @brief Конструктор с initializer_list<T>.
     * @param init Список значений для инициализации.
     */
    List(std::initializer_list<T> init);

    /**
     * @brief Оператор присваивания (копирование).
     * @param other Другой список для копирования.
     * @return Ссылка на текущий объект.
     */
    List& operator=(const List& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Другой список для перемещения.
     */
    List(List&& other) noexcept;

    /**
     * @brief Оператор присваивания (перемещение).
     * @param other Другой список для перемещения.
     * @return Ссылка на текущий объект.
     */
    List& operator=(List&& other) noexcept;

    /**
     * @brief Добавляет элемент в список.
     * @param value Значение элемента.
     */
    void add(const T& value);

    /**
     * @brief Удаляет элемент по индексу.
     * @param index Индекс элемента.
     * @throws std::out_of_range Если индекс за пределами диапазона.
     */
    void remove(size_t index);

    /**
     * @brief Возвращает текущий размер списка.
     * @return Текущий размер списка.
     */
    size_t getSize() const;

    /**
     * @brief Возвращает элемент по индексу.
     * @param index Индекс элемента.
     * @return Элемент списка.
     * @throws std::out_of_range Если индекс за пределами диапазона.
     */
    T get(size_t index) const;

    /**
     * @brief Преобразует список в строку.
     * @return Строковое представление списка.
     */
    std::string toString() const;

    /**
     * @brief Передаёт строковое представление списка в поток вывода.
     * @param os Поток вывода.
     */
    void print(std::ostream& os) const;

    /**
     * @brief Читает элементы списка из потока ввода.
     * @param is Поток ввода.
     */
    void inputElements(std::istream& is);

    /**
     * @brief Удаляет элемент по индексу, указанному пользователем.
     * @param is Поток ввода.
     */
    void removeElementByUser(std::istream& is);
};

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
List<T>::List(std::initializer_list<T> init) : size(init.size()), capacity(init.size()) 
{
    data = new T[capacity];
    size_t i = 0;
    for (const T& value : init) 
    {
        data[i++] = value;
    }
}

template <typename T>
List<T>& List<T>::operator=(const List& other) 
{
    if (this != &other) 
    {
        List<T> temp(other);
        std::swap(data, temp.data);
        std::swap(size, temp.size);
        std::swap(capacity, temp.capacity);
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
    if (this != &other) 
    {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

template <typename T>
void List<T>::resize(size_t new_capacity) 
{
    List<T> temp;
    temp.capacity = new_capacity;
    temp.size = size;
    temp.data = new T[new_capacity];

    for (size_t i = 0; i < size; ++i) 
    {
        temp.data[i] = data[i];
    }

    std::swap(*this, temp);
}

template <typename T>
void List<T>::add(const T& value) 
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
        throw std::out_of_range("Индекс за пределами диапазона");
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
        throw std::out_of_range("Индекс за пределами диапазона");
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
void List<T>::print(std::ostream& os) const 
{
    os << toString() << "\n";
}

template <typename T>
void List<T>::inputElements(std::istream& is) 
{
    size_t n;
    is >> n;
    for (size_t i = 0; i < n; ++i) 
    {
        T value;
        is >> value;
        add(value);
    }
}

template <typename T>
void List<T>::removeElementByUser(std::istream& is) 
{
    size_t index;
    is >> index;
    remove(index);
}
