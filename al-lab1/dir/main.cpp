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
