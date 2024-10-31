#ifndef MYUNIQUE_HPP_
#define MYUNIQUE_HPP_

#include <iostream>
#include <utility> // для std::move и std::forward

template<class T>
class MyUnique {
    T *p = nullptr;

public:
    // Конструктор с "сырым" указателем
    explicit MyUnique(T *ptr = nullptr) : p(ptr) {}

    // Деструктор
    ~MyUnique() {
        delete p;
    }

    // Удаляем конструктор копирования
    MyUnique(const MyUnique&) = delete;

    // Удаляем оператор присваивания копированием
    MyUnique& operator=(const MyUnique&) = delete;

    // Конструктор перемещения
    MyUnique(MyUnique&& other) noexcept : p(other.p) {
        other.p = nullptr;
    }

    // Оператор присваивания с перемещением
    MyUnique& operator=(MyUnique&& other) noexcept {
        if (this != &other) {
            delete p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }

    // Метод получения "сырого" указателя
    T* get() const {
        return p;
    }

    // Перегрузка оператора *
    T& operator*() const {
        return *p;
    }

    // Перегрузка оператора ->
    T* operator->() const {
        return p;
    }
};

// Функция создания объекта типа MyUnique
template<typename T, typename... Args>
MyUnique<T> Make_MyUnique(Args&&... args) {
    return MyUnique<T>(new T(std::forward<Args>(args)...));
}

#endif // MYUNIQUE_HPP_
