#ifndef MYSHARED_HPP_
#define MYSHARED_HPP_

#include <iostream>
#include <utility> // для std::move и std::forward

template<class T>
class MyShared {
    T *p = nullptr;
    int *ref_count = nullptr;

public:
    // Конструктор с "сырым" указателем
    explicit MyShared(T *ptr = nullptr) : p(ptr), ref_count(new int(1)) {}

    // Конструктор копирования
    MyShared(const MyShared &other) : p(other.p), ref_count(other.ref_count) {
        ++(*ref_count);
    }

    // Оператор присваивания с копированием
    MyShared& operator=(const MyShared &other) {
        if (this != &other) {
            cleanup();
            p = other.p;
            ref_count = other.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // Конструктор перемещения
    MyShared(MyShared &&other) noexcept : p(other.p), ref_count(other.ref_count) {
        other.p = nullptr;
        other.ref_count = nullptr;
    }

    // Оператор присваивания с перемещением
    MyShared& operator=(MyShared &&other) noexcept {
        if (this != &other) {
            cleanup();
            p = other.p;
            ref_count = other.ref_count;
            other.p = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // Деструктор
    ~MyShared() {
        cleanup();
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

private:
    void cleanup() {
        if (ref_count) {
            --(*ref_count);
            if (*ref_count == 0) {
                delete p;
                delete ref_count;
            }
        }
    }
};

// Функция создания объекта типа MyShared
template<typename T, typename... Args>
MyShared<T> Make_MyShared(Args&&... args) {
    return MyShared<T>(new T(std::forward<Args>(args)...));
}

#endif // MYSHARED_HPP_
