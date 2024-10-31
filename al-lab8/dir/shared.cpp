#include <iostream>
#include "../include/MyShared.hpp"

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
    // Создаем объект типа MyShared, указывая на объект MyPoint
    MyShared<MyPoint> ptr1 = Make_MyShared<MyPoint>(5, 10);

    // Используем перегруженные операторы
    ptr1->print();
    std::cout << "ptr1 x = " << ptr1.get() << std::endl;

    // Копируем указатель
    MyShared<MyPoint> ptr2 = ptr1;
    ptr2->print();
    std::cout << "ptr2 x = " << ptr2.get() << std::endl;

    // Проверка копирования
    if (ptr1.get() == ptr2.get()) {
        std::cout << "ptr1 and ptr2 point to the same object" << std::endl;
    }

    // Перемещение указателя
    MyShared<MyPoint> ptr3 = std::move(ptr1);
    ptr3->print();
    std::cout << "ptr3 x = " << ptr3.get() << std::endl;

    // Проверка перемещения
    if (ptr1.get() == nullptr) {
        std::cout << "ptr1 is now nullptr after move" << std::endl;
    }

    return 0;
}
