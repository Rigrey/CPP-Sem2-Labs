#include <iostream>
#include "../include/MyUnique.hpp"

// Пример класса для тестирования
class MyPoint {
    int x, y;
public:
    MyPoint(int x, int y) : x(x), y(y) {
        std::cout << "MyPoint(int x, int y): x=" << x << " y=" << y << std::endl;
    }
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    // Создаем объект типа MyUnique, указывая на объект MyPoint
    MyUnique<MyPoint> ptr = Make_MyUnique<MyPoint>(5, 10);

    // Используем перегруженные операторы
    ptr->print();
    std::cout << "x = " << ptr.get() << std::endl;

    // Перемещение объекта
    MyUnique<MyPoint> ptr2 = std::move(ptr);
    ptr2->print();
    std::cout << "x = " << ptr2.get() << std::endl;

    // Проверка перемещения
    if (ptr.get() == nullptr) {
        std::cout << "ptr is now nullptr after move" << std::endl;
    }

    return 0;
}
