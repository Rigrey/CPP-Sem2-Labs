#include "../include/vehicle.hpp"
#include <vector>

int main() {
  std::ofstream clear("output.txt");
  clear.close();
  std::ifstream input("input.txt");

  std::list<Vehicle> task_list;

  for (size_t i = 0; i < 5; ++i) {
    Vehicle intolist;
    input >> intolist;
    task_list.push_back(intolist);
  }
  
  CustomOutput("List before Sorting: ");
  for (const auto& el : task_list) {
    CustomOutput(el);
  }
  CustomOutput("List after Sorting: ");
  task_list.sort();
  for (auto el : task_list) {
    CustomOutput(el);
  }
  
  CustomOutput("Vector copied from List: ");
  std::vector<Vehicle> result;
  std::copy(task_list.begin(), task_list.end(), std::back_inserter(result));
  for (const auto& el : result) {
    CustomOutput(el);
  }
}
