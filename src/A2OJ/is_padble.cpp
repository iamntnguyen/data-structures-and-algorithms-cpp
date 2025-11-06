#include <algorithm>
#include <iostream>

bool is_padble(const std::string& str) {
  int n = str.length();
  if (n % 2 != 0) {
    return false;
  }

  for (int i = 0; i < n / 2; i++) {
    if (str[i] != str[n - i - 1]) {
      return false;
    }
  }
  return str.find('0') != std::string::npos && str.find('1') != std::string::npos;
}

int main() {
  std::string s;
  std::cout << "enter string: ";
  std::cin >> s;
  int max_len = 0;
  int count = 0;
  std::string substring;

  for (int len = s.length(); len >= 2; len -= 2) {
    for (int i = 0; i <= (int)s.length() - len; ++i) {
      substring = s.substr(i, len);
      if (is_padble(substring)) {
        if (len > max_len) {
          max_len = len;
          count = 1;
        } else if (len == max_len) {
          count++;
        }
      }
    }
  }
  std::cout << "max_len: " << max_len << "\ncount: " << count << std::endl;
  return 0;
}
