#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// random number vector
std::vector<int> generate_random_vector(int n) {
  std::vector<int> vec;
  for (int i = 0; i < n; i++) {
    int num = rand() % (100 - 1 + 1) + 1;
    vec.push_back(num);
  }
  return vec;
}

// linear search
bool linear_search(const std::vector<int>& vec, int x) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == x) {
      return true;
    }
  }
  return false;
}

// linear search for array
bool linear_search_array(int a[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      return true;
    }
  }
  return false;
}

int main() {
  srand(time(0));
  std::cout << "Linear Search\n";
  int ways;
  std::cout << "Enter number ways: ";
  std::cin >> ways;

  switch (ways) {
    case 1: {
      int n = 7;
      int x = 4;
      int a[n] = {1, 2, 3, 4, 5, 6, 7};
      if (linear_search_array(a, n, x)) {
        std::cout << x << " found in the array.\n";
      } else {
        std::cout << x << " not found in the array.\n";
      }
      break;
    }
    case 2: {
      int n = 10;
      std::vector<int> vec = generate_random_vector(n);
      int x = 25;
      if (linear_search(vec, x)) {
        std::cout << x << " found in the vector.\n";
      } else {
        std::cout << x << " not found in the vector.\n";
      }
      break;
    }
  }
}