#include <iostream>
#include "../include/triangle.hpp"

int main() {
  try {
    Triangle validTriangle(3, 4, 5);
    validTriangle.print();
  } catch (const TriangleException& ex) {
    std::cout << "Exception caught: " << ex.what() << std::endl;
    ex.print();
  }

  try {
    Triangle invalidTriangle(1, 2, 4);
    invalidTriangle.print();
  } catch (const TriangleException& ex) {
    std::cout << "Exception caught: " << ex.what() << std::endl;
    ex.print();
  }

  return 0;
}
