#ifndef VEHICLE_HPP_
#define VEHICLE_HPP_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

class Vehicle {
 public:
  Vehicle();
  Vehicle(const std::string&, const float*, const size_t&, const float&);
  Vehicle(const Vehicle&);
  std::string get_model() const {return _model;};

 private:
  std::string _model;
  float _fuel_consumption[3];
  size_t _max_speed;
  float _engine_power;

  friend std::ostream& operator<<(std::ostream&, const Vehicle&);
  friend std::istream& operator>>(std::istream&, Vehicle&);
  friend bool operator<(const Vehicle&, const Vehicle&);
  friend bool operator==(const Vehicle&, const Vehicle&);
};

Vehicle::Vehicle() 
                : _model(""), 
                  _fuel_consumption{0, 0, 0}, 
                  _max_speed(0), 
                  _engine_power(0){};
Vehicle::Vehicle(const std::string& m, const float* f, const size_t& ma, const float& e)
                : _model(m),
                  _fuel_consumption{f[0], f[1], f[2]},
                  _max_speed(ma),
                  _engine_power(e){};
Vehicle::Vehicle(const Vehicle& rhs)
                : _model(rhs._model),
                  _fuel_consumption{rhs._fuel_consumption[0], rhs._fuel_consumption[1],
                                    rhs._fuel_consumption[2]},
                  _max_speed(rhs._max_speed),
                  _engine_power(rhs._engine_power){};

  std::ostream& operator<<(std::ostream& os, const Vehicle& rhs) {
  os << "Vehicle Parameters:\n";
  os << "Model: " << rhs._model << std::endl;
  os << "Fuel consumption at the highway: " << rhs._fuel_consumption[0]
     << ", in the city: " << rhs._fuel_consumption[1]
     << ", mixed: " << rhs._fuel_consumption[2] << std::endl;
  os << "Max speed: " << rhs._max_speed << std::endl;
  os << "Engine power: " << rhs._engine_power << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Vehicle& rhs) {
  is >> std::ws;
  std::getline(is, rhs._model);
  for (int i = 0; i < 3; ++i) {
    is >> rhs._fuel_consumption[i];
  }
  is >> rhs._max_speed;
  is >> rhs._engine_power;
  return is;
}

template <class T1>
void CustomOutput(T1& obj) {
  std::ofstream output("output.txt", std::ios::app);
  output << obj << std::endl;
  std::cout << obj << std::endl;
  output.close();
}

bool operator<(const Vehicle& lhs, const Vehicle& rhs) {
  std::string lowl = lhs._model;
  std::string lowr = rhs._model;
  std::transform(lowl.begin(), lowl.end(), lowl.begin(),
                 [](unsigned char c) { return tolower(c); });
  std::transform(lowr.begin(), lowr.end(), lowr.begin(),
                 [](unsigned char c) { return tolower(c); });
  return lowl < lowr;
}

bool operator==(const Vehicle& lhs, const Vehicle& rhs) {
  return lhs._model == rhs._model;  // I got taks to do compare by model
}

#endif  // VEHICLE_HPP_
