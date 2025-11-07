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

void interchange_sort(std::vector<int>& vec) {
  int n = vec.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vec[i] > vec[j]) {
        swap(vec[i], vec[j]);
      }
    }
  }
}

void print_vector(const std::vector<int>& vec) {
  for (int num : vec) std::cout << num << " ";
  std::cout << "\n";
}

int main() {
  srand(time(0));
  std::cout << "Interchange Sort\n";

  int n = 10;
  std::vector<int> data = generate_random_vector(n);

  std::cout << "Before sort: ";
  print_vector(data);

  interchange_sort(data);

  std::cout << "After sort:  ";
  print_vector(data);
}
