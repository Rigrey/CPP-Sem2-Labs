#include "../include/parallelepiped.hpp"

int main() {
  Rectangle rec(105, 13);
  Rectangle* pointer = &rec;

  std::cout << "Example of correct method-usage through pointer" << std::endl;
  pointer->print();
  std::cout << std::endl;
  pointer->print_subdata();
  std::cout << std::endl;

  Parallelepiped pip(120, 27, 18);
  pointer = &pip;
  
  std::cout << std::endl << "Example of dynamic polymorphism: " << std::endl;
  pointer->print();
  std::cout << std::endl;

  std::cout << std::endl << "Example of static polymorphism: " << std::endl;
  pointer->print_subdata();
  std::cout << std::endl;
}