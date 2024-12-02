#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<int>> readMatrixFromFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Error: Unable to open file " << filename << "\n";
    return {};
  }

  std::vector<std::vector<int>> matrix;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<int> row;
    int num;

    while (iss >> num) {
      row.push_back(num);
    }

    if (!row.empty()) {
      matrix.push_back(row);
    }
  }

  file.close();
  return matrix;
}

bool descendingCheck(int a, int b) { return a > b; }

// Checks if the levels are either all increasing or all decreasing
bool isSorted(std::vector<int> row) {
  if (std::is_sorted(row.begin(), row.end()) ||
      std::is_sorted(row.begin(), row.end(), descendingCheck)) {
    return true;
  }
  return false;
}

// Checks if adjacent levels differ by at least 1 and at most 3
bool isValidDifference(std::vector<int> row) {
  for (int i = 0; i < row.size() - 1; ++i) {
    int diff = std::abs(row[i] - row[i + 1]);
    if (diff < 1 || diff > 3) {
      return false;
    }
  }

  return true;
}

#ifndef RUNNING_TESTS // If not running tests, run the main program

int main() {
  std::string filename("input.txt");
  // Read the matrix from the file
  std::vector<std::vector<int>> matrix = readMatrixFromFile(filename);

  // Output the matrix (row-wise iteration)
  if (matrix.empty()) {
    std::cerr << "Matrix is empty or could not be read.\n";
    return 1;
  }

  int safeRows = 0;
  for (const auto &row : matrix) {
    if (isSorted(row) && isValidDifference(row)) {
      ++safeRows;
    }
  }
  std::cout << "Number of safe rows: " << safeRows;

  return 0;
}

#endif // RUNNING_TESTS
