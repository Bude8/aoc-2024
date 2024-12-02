#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

bool readColumns(const std::string &filename, std::vector<int> &column1,
                 std::vector<int> &column2) {
  std::ifstream file(filename);

  if (!file) {
    std::cerr << "Unable to open file: " << filename << "\n";
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int col1, col2;

    if (iss >> col1 >> col2) {
      column1.push_back(col1);
      column2.push_back(col2);
    }
  }

  file.close();
  return true;
}

int main(int gc, char *argv[]) {
  std::string filename = "input.txt";
  std::vector<int> column1, column2;

  if (!readColumns(filename, column1, column2)) {
    std::cerr << "Error reading file.\n";
  }

  std::cout << "Length of column1: " << std::size(column1) << "\n";
  std::cout << "Length of column2: " << std::size(column2) << "\n";

  std::sort(column1.begin(), column1.end());
  std::sort(column2.begin(), column2.end());

  if (column1.size() != column2.size()) {
    std::cerr << "The columns have different sizes! Was there an error with "
                 "the text file?";
    return 1;
  }

  int totalDifference = 0;

  for (int i = 0; i <= column1.size(); i++) {
    totalDifference += abs(column1[i] - column2[i]);
  }

  std::cout << "Part 1: " << totalDifference;

  return 0;
}
