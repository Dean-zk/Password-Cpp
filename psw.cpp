#include <iostream>
#include <random>
#include <string>
#include <vector>

std::vector<char> chars;

// thought that 4 for loops where redundant,
// so I wrote this which is even More redundant...
std::vector<char> AddCharsLoop(char pSc, char pLc, int pSg,
                               std::vector<char> &pChars) {
  if (pSg == 0) {
    for (char c = pSc; c <= pLc; c++) {
      pChars.push_back(c);
    }
  }

  else if (pSg == 1) {
    for (char c = pSc; c >= pLc; c++) {
      pChars.push_back(c);
    }
  }

  return pChars;
}

//&pChars allows a more clean way to modify data without making copies.
std::vector<char> AddChars(std::vector<char> &pChars) {
  AddCharsLoop('a', 'z', 0, pChars);
  AddCharsLoop('A', 'Z', 0, pChars);
  AddCharsLoop('?', '!', 1, pChars);
  AddCharsLoop('0', '9', 0, pChars);

  return pChars;
}

std::string GeneratePassword(int pLength) {
  chars = AddChars(chars);
  std::string sb;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, chars.size() - 1);

  int j = 0;

  while (j < pLength) {
    sb.push_back(chars[dist(gen)]);
    j++;
  }

  return sb;
}

// Main program to run.
void program() {
  std::cout << "Enter length of password => ";
  int length;
  std::string pswLen;
  std::getline(std::cin, pswLen);

  if (std::stoi(pswLen, nullptr, 10)) {
    length = std::stoi(pswLen, nullptr, 10);
    std::string psw = GeneratePassword(length);
    std::cout << "Your password: " << psw << "\n";
  }
}

int main() {
  program(); // Making it a different fucntion to keep the main clean.
  return 0;
}
