#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<int> generate_random_vector(int n) {
  std::vector<int> vec;
  for (int i = 0; i <= n; i++) {
    int num = rand() % (100 - 1 + 1) + 1;
    vec.push_back(num);
  }
  return vec;
}

bool interpolation_search(const std::vector<int>& vec, int target) {
  int left = 0;
  int right = vec.size() - 1;

  while (left <= right && target >= vec[left] && target <= vec[right]) {
    if (left == right) {
      if (vec[left] == target) return true;
      return false;
    }
    int pos = left + ((target - vec[left]) * (right - left)) / (vec[right] - vec[left]);

    if (vec[pos] == target) return true;
    if (vec[pos] < target)
      left = pos + 1;
    else
      right = pos - 1;
  }
  return false;
}

int main() {
  std::cout << "Interpolation Search";
  int n = 10;
  int x = 25;
  std::vector<int> data = generate_random_vector(n);
  std::sort(data.begin(), data.end());

  std::cout << "vector";
  for (int num : data) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  if (interpolation_search(data, x)) {
    std::cout << "found";
  } else {
    std::cout << "not found";
  }
}