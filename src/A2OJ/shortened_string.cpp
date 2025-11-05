#include <iostream>
#include <string>

// fn to shorten the string
std::string shorten_string(const std::string& str) {
  std::string result;
  int n = str.length();
  for (int i = 0; i < n; i++) {
    int count = 1;
    while (i + 1 < n && str[i] == str[i + 1]) {
      count++;
      i++;
    }
    result += str[i];
    if (count > 1) {
      result += std::to_string(count);
    }   
  }
  return result;
}

int main() {
  std::cout << "Shortened String\n";
  std::string str;
  std::cout << "Enter the string: ";
  std::cin >> str;
  std::string shortened = shorten_string(str);
  std::cout << "Shortened string: " << shortened << std::endl;
  return 0;
}