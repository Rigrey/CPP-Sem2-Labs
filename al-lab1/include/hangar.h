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
