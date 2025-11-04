#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// random number
std::vector<int> generate_random_vector(int n) {
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    int num = rand() % (100 - 1 + 1) + 1;
    vec.push_back(num);
  }
  return vec;
}
// array
bool binary_search_one(int a[], int n, int x) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (a[mid] == x) {
      return true;
    } else if (a[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;  // left > right
}

// vector
bool binary_search_tow(const std::vector<int>& vec, int x) {
  int left = 0;
  int right = vec.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    if (vec[mid] == x) {
      return true;
    } else if (vec[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

int main() {
  srand(time(0));
  std::cout << "Binary Search\n";
  int ways;
  std::cout << "Enter number ways: ";
  std::cin >> ways;
  switch (ways) {
    case 1: {
      int n = 7;
      int x = 4;
      int a[n] = {1, 2, 3, 4, 5, 6, 7};

      if (binary_search_one(a, n, x)) {
        std::cout << "Found";
      } else {
        std::cout << "Not found";
      }
      break;
    }
    case 2: {
      int quantity = 10;
      int x = 25;
      std::vector<int> data = generate_random_vector(quantity);
      std::sort(data.begin(), data.end());

      std::cout << "Vector: ";
      for (int num : data) std::cout << num << " ";
      std::cout << "\n";

      if (binary_search_tow(data, x)) {
        std::cout << "Found\n";
      } else {
        std::cout << "Not found\n";
      }
      break;
    }
  }
}