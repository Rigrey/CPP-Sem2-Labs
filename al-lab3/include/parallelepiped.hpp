#ifndef PARALLELEPIPED_HPP_
#define PARALLELEPIPED_HPP_

#include "rectangle.hpp"

class Parallelepiped : public Rectangle {
  public:
  Parallelepiped(const size_t& _l, const size_t& _w, const size_t& _h);

  size_t volume();
  void print() override;
  void print_subdata();

  protected:
  size_t _height = 0;
};

Parallelepiped::Parallelepiped(const size_t& _l, const size_t& _w, const size_t& _h) : Rectangle(_l, _w), _height(_h) {};

size_t Parallelepiped::volume() {
  return Rectangle::area() * _height;
}

void Parallelepiped::print() {
  Rectangle::print();
  std::cout << ", Height: " << _height;
}

void Parallelepiped::print_subdata() {
  std::cout << "Area of the base: " << this->area();
  std::cout << ", Volume: " << this->volume();
}

#endif // PARALLELEPIPED_HPP_
