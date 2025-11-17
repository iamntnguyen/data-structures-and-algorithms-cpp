#include <iostream>
#include <string>
#include <vector>

std::string intToRoman(int num) {
  const std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  const std::vector<std::string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                            "XL", "X",  "IX", "V",  "IV", "I"};

  std::string result = "";
  int i = 0;

  // Lặp qua các giá trị từ lớn nhất đến nhỏ nhất
  // loop 1: num = 27 >= 10 => result = "X", num = 17
  // loop 2: num = 17 >= 10 => result = "XX", num = 7
  // loop 3: num = 7 >= 5 => result = "XXV", num = 2
  // loop 4: num = 2 >= 1 => result = "XXVI", num = 1
  // loop 5: num = 1 >= 1 => result = "XXVII", num = 0
  while (num > 0) {
    // Lấy giá trị lớn nhất (values[i]) nhỏ hơn hoặc bằng số còn lại (num)
    while (num >= values[i]) {
      // Thêm ký hiệu La Mã tương ứng vào kết quả
      result += symbols[i];

      // Trừ giá trị đó khỏi số nguyên
      num -= values[i];
    }
    // Chuyển sang giá trị/ký hiệu La Mã tiếp theo
    i++;
  }

  return result;
}

int main() {
  int number = 27;
  std::string romanNumeral = intToRoman(number);
  std::cout << "number: " << number << " = " << romanNumeral << std::endl;  // Output: XXVII

  return 0;
}