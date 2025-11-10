// do phuc tap O(sqrt(n))
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

std::vector<int> generate_random_vector(int& n) {
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

int jump_search(std::vector<int>& vec, int target) {
  int n = vec.size();
  int step = sqrt(n);
  int prev = 0;

  while (vec[std::min(step, n) - 1] < target) {
    prev = step;
    step += sqrt(n);
    if (prev >= n) {
      return -1;
    }
  }

  for (int i = prev; i < std::min(step, n); i++) {
    if (vec[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  srand(time(0));
  int n = 10;
  std::vector<int> data = generate_random_vector(n);
  std::sort(data.begin(), data.end());
  std::cout << "Data: ";
  print_vector(data);
  int target = data[n / 2];
  std::cout << "Target: " << target << "\n";
  int result = jump_search(data, target);
  if (result != -1) {
    std::cout << "Element found at index: " << result << "\n";
  } else {
    std::cout << "Element not found\n";
  }
  return 0;
}
