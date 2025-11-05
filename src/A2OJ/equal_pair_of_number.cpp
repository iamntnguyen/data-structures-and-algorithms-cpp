#include <iostream>
#include <vector>

// fn to find equal pair of number
void find_equal_pair(const std::vector<int>& vec) {
  int dem = 0;
  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (vec[i] == vec[j]) {
        std::cout << "Equal pair found: (" << vec[i] << ", " << vec[j] << ")\n";
        dem++;
      }
    }
  }
  std::cout << "Total equal pairs: " << dem << std::endl;
}

int main() {
  std::cout << "Equal Pair of Number\n";
  int n;
  std::cout << "Enter the size of the array: ";
  std::cin >> n;
  std::vector<int> vec(n);
  std::cout << "Enter the elements of the array:\n";
  for (int i = 0; i < n; i++) {
    std::cin >> vec[i];
  }
  find_equal_pair(vec);
  return 0;
}