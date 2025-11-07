#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<int> generate_random_vector(int n) {
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    int num = rand() % 100 + 1;
    vec.push_back(num);
  }
  return vec;
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void selection_sort(std::vector<int>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    int min_i = i;
    for (int j = i + 1; j < n; j++) {
      if (vec[j] < vec[min_i]) {
        min_i = j;
      }
    }
    swap(vec[i], vec[min_i]);
  }
}

void print_vector(const std::vector<int>& vec) {
  for (int value : vec) {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

int main() {
  srand(time(0));
  std::cout << "Selection Sort Demo 🌀\n\n";

  int n = 10;
  std::vector<int> data = generate_random_vector(n);

  std::cout << "Before sort: ";
  print_vector(data);

  selection_sort(data);

  std::cout << "After sort:  ";
  print_vector(data);
}
