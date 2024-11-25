#pragma once
#include <string>
#include <iostream>
#include <list.tpp>
#include <sstream>

template <typename T>
class List 
{
private:
    T* data; // Указатель на массив данных
    size_t size; // Количество элементов
    size_t capacity; // Максимальная вместимость

    void resize(size_t new_capacity); // Метод изменения размера

public:
    List();
    ~List();
    List(const List& other);
    List& operator=(const List& other);
    List(List&& other) noexcept;
    List& operator=(List&& other) noexcept;

    void add(T value); // Добавление элемента
    void remove(size_t index); // Удаление элемента
    size_t getSize() const; // Получение текущего размера
    T get(size_t index) const; // Получение элемента по индексу
    std::string toString() const; // Преобразование в строку
    void print() const; // Вывод списка
    void inputElements(); // Пользовательский ввод
    void removeElementByUser(); // Пользовательское удаление
};

