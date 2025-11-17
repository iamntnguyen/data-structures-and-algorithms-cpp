#include <iostream>

bool isPalindrome(int x) {
  if (x < 0) return false;
  int original = x;
  int reversed = 0;

  // ex: 121
  // loop 1: digit = 1, reversed = 0 * 10 + 1 = 1, x = 12
  // loop 2: digit = 2, reversed = 1 * 10 + 2 = 12, x = 1
  // loop 3: digit = 1, reversed = 12 * 10 + 1 = 121, x = 0
  // => reversed = 121 == original = 121
  while (x != 0) {
    int digit = x % 10;
    reversed = reversed * 10 + digit;
    x /= 10;
  }
  return original == reversed;
}

int main() {
  int number = 122;
  if (isPalindrome(number)) {
    std::cout << number << " is a palindrome." << std::endl;
  } else {
    std::cout << number << " is not a palindrome." << std::endl;
  }
  return 0;
}