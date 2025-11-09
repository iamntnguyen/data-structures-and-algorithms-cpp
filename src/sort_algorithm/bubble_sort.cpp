#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<int> generate_random_vector(int n) {
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    int num = rand() % (100 - 1 + 1) + 1;
    vec.push_back(num);
  }
  return vec;
}

void print_vector(std::vector<int>& vec) {
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << "\n";
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubble_sort(std::vector<int>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        swap(vec[j], vec[j + 1]);
      }
    }
  }
}

int main() {
  srand(time(0));
  int vec = 10;
  std::vector<int> data = generate_random_vector(vec);

  std::cout << "before sort: ";
  print_vector(data);

  bubble_sort(data);

  std::cout << "after sort: ";
  print_vector(data);

  return 0;
}