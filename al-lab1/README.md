# Отчет по лабораторной работе

## Титульный лист

**Студент:** Ожогин Михаил Александрович  
**Группа:** ИУ8-24  
**Преподаватель:** Барыкин Дмитрий Васильевич  

## Цель работы

Изучить основы программирования на языке C++, работу с классами, методы доступа к полям класса, функции-члены, ввод данных из файла, вывод данных в консоль и файл.

## Условие задачи

Реализовать класс "Ангар" с параметрами ширины и длины. Поля класса должны иметь статус доступа private. Класс должен содержать конструктор, функцию для определения площади помещения, методы доступа к полям, функцию для печати параметров. Необходимо напечатать параметры ангаров и площадь склада, состоящего из этих ангаров.

## Текст программы с комментариями
Программа реализована в двух файлах: заголовочный файл **hangar.h**, включающий класс "Ангар" и описание функций для него, и главный файл **main.cpp**, содержащий функции для выполнения работы.  
  
[**hangar.h:**](https://github.com/Rigrey/al-lab1/blob/main/include/hangar.h#L1)
```cpp
#ifndef HANGAR_H
#define HANGAR_H

#include <iostream>
#include <fstream>

class Hangar {
  friend std::ostream& operator<<(std::ostream&, const Hangar&);
  friend std::istream& operator>>(std::istream&, Hangar&);
private:
  size_t _width; // Width of the hangar
  size_t _length; // Length of the hangar
  size_t _area; // Area of the hangar
public:
  Hangar(const Hangar&);
  Hangar(const size_t& _w = 0, const size_t& _l = 0);
  void set(size_t&, size_t&);
  size_t area();
  void print();
};

/**
 * @brief Constructor for the Hangar class.
 *
 * @param hangar The Hangar object to be copied.
 */
Hangar::Hangar(const Hangar& hangar) {
  this->_width = hangar._width; // Copy old _width to new hangar _width
  this->_length = hangar._length; // Copy old _length to new hangar _length
  this->_area = hangar._area; // Copy old _area to new hangar _area
}

/**
 * @brief Constructor for Hangar class.
 *
 * @param _w The _width of the hangar
 * @param _l The _length of the hangar
 */
Hangar::Hangar(const size_t& _w, const size_t& _l) {
  this->_width = _w; // Initialize _width to _w
  this->_length = _l; // Initialize _length to _l
  this->_area = _w * _l; // Initialize _area to _w * _l
}

/**
 * @brief Set the dimensions of the hangar.
 *
 * @param _w The _width of the hangar
 * @param _l The _length of the hangar
 */
void Hangar::set(size_t& _w, size_t& _l) {
  this->_width = _w; // Initialize _width to w
  this->_length = _l; // Initialize _length to l
  this->_area = _w * _l; // Initialize _area to _w * _l
}

/**
 * @return The _area of the hangar.
 */
size_t Hangar::area() {
  return this->_area;
}

/**
 * @brief Overload for the << operator to print the details of the hangar.
 * 
 * @param os The output stream.
 * @param hangar The Hangar object to be printed.
 *
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Hangar& hangar) {
  // Print _width
  os << "Width: " << hangar._width << " meters\n";
  // Print _length
  os << "Length: " << hangar._length << " meters\n";
  // Print _area
  os << "Area: " << hangar._area << " square meters\n";
  return os;
}

/**
 * @brief Overload for the >> operator to read the dimensions of the hangar.
 *
 * @param is The input stream.
 * @param hangar The Hangar object to be read from the input stream.
 *
 * @return The input stream.

*/
std::istream& operator>>(std::istream& is, Hangar& hangar) {
  // Get _width from istream
  is >> hangar._width;
  // Get _length from istream
  is >> hangar._length;
  // Caluculate _area of hangar
  hangar._area = hangar._width * hangar._length;
  return is;
}

/**
 * @brief Append the message to the output file and print it to the console.
 * 
 * @param message The message to be appended to the output file and printed to the console.
 */
void customOutput(const std::string& message) {
  // Open the output file in append mode
  std::ofstream file("output.txt", std::ios_base::app);
  // Print the message to the console
  std::cout << message;
  // Append the message to the output file
  file << message;
  // Close the output file
  file.close();
}

/**
 * @brief Append the hangar to the output file and print it to the console.
 * 
 * @param hangar The hangar to be appended to the output file and printed to the console.
 */
void customOutput(const Hangar& hangar) {
  // Open the output file in append mode
  std::ofstream file("output.txt", std::ios_base::app);
  // Print the message to the console
  std::cout << hangar;
  // Append the message to the output file
  file << hangar;
  // Close the output file
  file.close();
}

#endif // HANGAR_H

```
  
[**main.cpp:**](https://github.com/Rigrey/al-lab1/blob/main/dir/main.cpp#L1)
```cpp
#include "../include/hangar.h"
#include <vector>

// Function to create dynamic array of hangars, display their details and calculate total area
void laba_dyn_array() {
  // Initialize variables
  std::ifstream input("input.txt");
  size_t n = 0; // Number of hangars
  size_t total_area = 0; // Total area of all hangars

  input >> n; // Get number of hangars from input file

  Hangar *hangars[n]; // Dynamic array to store hangars

  // Initialize dynamic array with Hangar objects in for-loop
  for (size_t i = 0; i < n; ++i) { 
    Hangar temp;
    input >> temp; // Get data from input file to temp Hangar object
    hangars[i] = new Hangar(temp); // Create new Hangar object and copy data from temp Hangar object
  }

  // Calculate total area and print details of each hangar
  for (size_t i = 0; i < n; ++i) {
    total_area += hangars[i]->area();
    customOutput("\nDetails of hangar " + std::to_string(i + 1) + ": \n");
    customOutput(*hangars[i]);
    customOutput("\n");
  }
  customOutput("Total area of all hangars: " + std::to_string(total_area) + " square meters\n\n"); // Output message

  // Free memory allocated for hangar objects
  for (size_t i = 0; i < n; ++i) {
    delete hangars[i];
  }
}

// Function to create vector of hangars, display their details and calculate total area
void laba_vector() {
  // Initialize variables
  std::ifstream input("input.txt");
  size_t n = 0; // Number of hangars
  size_t total_area = 0; // Total area of all hangars
  std::vector<Hangar> hangars; // Vector to store Hangar objects

  input >> n; // Get number of hangars from input file

  // Initialize vector with Hangar objects in for-loop
  for (size_t i = 0; i < n; ++i) {
    Hangar temp;
    input >> temp;
    Hangar tem1p(12,34);
    hangars.push_back(temp);
  }

  // Calculate total area and print details of each hangar
  for (size_t i = 0; i < n; ++i) {
    total_area += hangars[i].area();
    customOutput("\nDetails of hangar " + std::to_string(i + 1) + ": \n");
    customOutput(hangars[i]);
    customOutput("\n");
  }

  customOutput("Total area of all hangars: " + std::to_string(total_area) + " square meters\n\n");
}

int main() {
  std::ios_base::sync_with_stdio(false); // Disable synchronization with C I/O (Speed up work of cin and cout)
  std::ofstream output("output.txt"); // Open output file to clear it from last run
  output.close(); // Close output file after clearing it

  customOutput("Here is the implemention of Hangar class(V20) with vector \n");
  laba_vector();

  customOutput("Here is the implemention of Hangar class(V20) with dynamic array \n");
  laba_dyn_array();
  return 0;
}


```
## Ручной расчет контрольного примера

В файле [**input.txt**](https://github.com/Rigrey/al-lab1/blob/main/input.txt#L1) содержится данная информация, где первая строка - количество ангаров, первое число каждой последующей строки - ширина, другое - длина:
```
3
10 20
50 90
400 42
```

Используем формулу для расчета площади ангара: Площадь = Ширина * Длина  

Тогда для каждого ангара будет:  
1) Площадь = 10 \* 20 = 200  
2) Площадь = 50 \* 90 = 4500  
3) Площадь = 400 \* 42 = 16800  

Получаем, что площадь всего склада будет равна 200 + 4500 + 16800 = 21500 квадратных метров.  

## Результаты решения контрольного примера программой

При вводе данных из файла [**input.txt**](https://github.com/Rigrey/al-lab1/blob/main/input.txt#L1) с указанным содержанием и запуске программы ожидается вывод на экран:  

```
Here is the implemention of Hangar class(V20) with vector 

Details of hangar 1: 
Width: 10 meters
Length: 20 meters
Area: 200 square meters


Details of hangar 2: 
Width: 50 meters
Length: 90 meters
Area: 4500 square meters


Details of hangar 3: 
Width: 400 meters
Length: 42 meters
Area: 16800 square meters

Total area of all hangars: 21500 square meters

Here is the implemention of Hangar class(V20) with dynamic array 

Details of hangar 1: 
Width: 10 meters
Length: 20 meters
Area: 200 square meters


Details of hangar 2: 
Width: 50 meters
Length: 90 meters
Area: 4500 square meters


Details of hangar 3: 
Width: 400 meters
Length: 42 meters
Area: 16800 square meters

Total area of all hangars: 21500 square meters

```

Также результат будет записан в файл [**output.txt**](https://github.com/Rigrey/al-lab1/blob/main/output.txt#L1). Его содержимое эквивалентно выводу на экран.

## Выводы по работе

В ходе лабораторной работы был разработан класс "Ангар" с необходимыми методами для расчета площади склада и вывода параметров. Были изучены основы работы с классами в C++, а также ввод и вывод данных из файлов.
