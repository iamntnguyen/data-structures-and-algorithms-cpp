#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

// O (nlogn)
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

void merge(std::vector<int>& vec, int left, int right) {
  int mid = (left + right) / 2;
  int indexLeft = mid - left + 1;
  int indexRight = right - mid;
  std::vector<int> leftVec(indexLeft);
  std::vector<int> rightVec(indexRight);
  for (int i = 0; i < indexLeft; i++) {
    leftVec[i] = vec[left + i];
  }
  for (int j = 0; j < indexRight; j++) {
    rightVec[j] = vec[mid + 1 + j];
  }
  int i = 0, j = 0, k = left;
  while (i < indexLeft && j < indexRight) {
    if (leftVec[i] <= rightVec[j]) {
      vec[k] = leftVec[i];
      i++;
    } else {
      vec[k] = rightVec[j];
      j++;
    }
    k++;
  }
}

void merge_sort(std::vector<int>& vec, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, right);
  }
}
int main() {
  srand(time(0));
  int n = 10;
  std::vector<int> data = generate_random_vector(n);

  std::cout << "before sort: ";
  print_vector(data);

  merge_sort(data, 0, n - 1);

  std::cout << "after sort: ";
  print_vector(data);
}