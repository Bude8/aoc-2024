#include <fstream>
#include <iostream>
#include <regex>
#include <string>

std::string readFileIntoString(const std::string &filename) {
  std::ifstream ifs(filename);
  std::string data((std::istreambuf_iterator<char>(ifs)),
                   (std::istreambuf_iterator<char>()));
  return data;
}

std::string strip(std::string s) {
  std::regex re("mul\\(\\d+,\\d+\\)"); // Matches one or more digits
  std::string result;

  // Iterator to find matches
  auto begin = std::sregex_iterator(s.begin(), s.end(), re);
  auto end = std::sregex_iterator();

  // Concatenate all matches
  for (std::sregex_iterator i = begin; i != end; ++i) {
    result += i->str();
  }

  std::cout << "Stripped corrupted characters: " << result << std::endl;

  return result;
}

std::string createExpression(std::string s) {
  std::regex re("mul\\((\\d+),(\\d+)\\)");

  std::string result = std::regex_replace(s, re, "$1*$2+");

  std::regex reTrailingPlus("\\+$");
  result = std::regex_replace(result, reTrailingPlus, "");

  std::cout << "Created expression: " << result << std::endl;
  return result;
}

int multiply(std::string e) {
  std::stringstream ss(e);
  int result = 1;
  std::string part;

  while (std::getline(ss, part, '*')) {
    // If it's the first part, set result to that number
    if (result == 1) {
      result = std::stoi(part);
    } else {
      result *= std::stoi(part); // Multiply the number
    }
  }
  return result;
}

int evaluateExpression(std::string e) {
  // Split using stringstream
  std::stringstream ss(e);
  std::vector<std::string> parts;
  std::string part;

  while (std::getline(ss, part, '+')) {
    parts.push_back(part);
  }

  int result = 0;
  int currentValue;

  for (const auto &p : parts) {
    result += multiply(p);
  }

  std::cout << "Result: " << result << std::endl;
  return result;
}

#ifndef RUNNING_TESTS // If not running tests, run the main program

int main(int argc, char **argv) {
  std::string filename = "input.txt";
  std::string data;
  data = readFileIntoString(filename);

  data = strip(data);
  std::string expression = createExpression(data);
  int result = evaluateExpression(expression);

  return 0;
}

#endif // RUNNING_TESTS
