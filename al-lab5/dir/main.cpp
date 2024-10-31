#include <set>
#include <unordered_set>

#include "../include/vehicle.hpp"

namespace std {
    template <>
    struct hash<Vehicle> {
        size_t operator()(const Vehicle& v) const {
            return std::hash<std::string>()(v.get_model());
        }
    };
}

int main() {
  std::ofstream clear("output.txt");
  clear.close();
  std::ifstream is("input.txt");

  std::set<Vehicle> task_set;
  std::unordered_set<Vehicle> task_unordered_set;

  while (is) {
    if (is.eof()) {
      break;
    }
    Vehicle a;
    is >> a;
    task_set.insert(a);
    task_unordered_set.insert(a);
  }

  CustomOutput("\tSet container for custom Vehicle class: ");
  for (const auto& el : task_set) {
    CustomOutput(el);
  }
  
  CustomOutput("\n\tUnordered Set container for custom Vehicle class: ");
  for (const auto& el : task_unordered_set) {
    CustomOutput(el);
  }
}
