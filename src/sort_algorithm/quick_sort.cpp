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

void quick_sort(std::vector<int>& vec, int left, int right) {
  int i = left, j = right;
  int mid = vec[(left + right) / 2];

  while (i <= j) {
    while (vec[i] < mid) i++;
    while (vec[j] > mid) j--;
    if (i <= j) {
      std::swap(vec[i], vec[j]);
      i++;
      j--;
    }
  }

  if (left < j) quick_sort(vec, left, j);
  if (i < right) quick_sort(vec, i, right);
}

int main() {
  int vec = 10;
  std::vector<int> data = generate_random_vector(vec);

  std::cout << "before sort: ";
  print_vector(data);

  quick_sort(data, 0, data.size() - 1);

  std::cout << "after sort: ";
  print_vector(data);

  return 0;
}