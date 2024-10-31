#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include <exception>

class TriangleException : public std::invalid_argument {
public:
  explicit TriangleException(const double&, const double&, const double&);
  void print() const;
private:
  double _a;
  double _b;
  double _c;
};

class Triangle {
public:
  explicit Triangle(const double&, const double&, const double&);
  void print() const;
  bool isValid() const;
private:
  double _a;
  double _b;
  double _c;
};

TriangleException::TriangleException(const double& a, const double& b, const double& c)
              : std::invalid_argument("Triangle doesn't exists"), _a(a), _b(b), _c(c) {}

void TriangleException::print() const {
  std::cout << "Triangle sides: " << _a << ", "
                                  << _b << ", "
                                  << _c << std::endl;
}

Triangle::Triangle(const double& a, const double& b, const double& c) : _a(a), _b(b), _c(c) {
  if(!isValid()) {
    throw TriangleException(_a, _b, _c);
  }
}

void Triangle::print() const {
  std::cout << "Triangle sides: " << _a << ", "
                                  << _b << ", "
                                  << _c << std::endl;
}

bool Triangle::isValid() const {
  if((_a + _b > _c) && (_a + _c > _b) && (_b + _c > _a)) {
    return true;
  }
  return false;
}

#endif // TRIANGLE_HPP_
