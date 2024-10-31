#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include <cstddef>
#include <iostream>

class Rectangle {
  public:
  Rectangle(const size_t& _l, const size_t& _w);

  virtual size_t area();
  virtual void print();
  void print_subdata();

  protected:
  size_t _length = 0;
  size_t _width = 0;
};

Rectangle::Rectangle(const size_t& _l, const size_t& _w) : _length(_l), _width(_w) {};

size_t Rectangle::area() {
  return _length * _width;
}

void Rectangle::print() {
  std::cout << "Length: " << _length << ", Width: " << _width;
}

void Rectangle::print_subdata() {
  std::cout << "Area of the base: " << this->area();
}

#endif // RECTANGLE_HPP_
