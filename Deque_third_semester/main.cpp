#include <iostream>
#include "..\Solver\List.h"

int main() 
{
    List<int> list; 
    int choice;

    while (true) 
    {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить элементы\n";
        std::cout << "2. Удалить элемент\n";
        std::cout << "3. Показать список\n";
        std::cout << "4. Выйти\n";
        std::cin >> choice;

        switch (choice) 
        {
            case 1:
                list.inputElements();
                break;
            case 2:
                list.removeElementByUser();
                break;
            case 3:
                list.print();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Неверный выбор\n";
        }
    }

    return 0;
}
