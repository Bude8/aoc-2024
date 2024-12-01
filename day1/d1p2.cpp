#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

// Function to read the columns from a file into integer vectors
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

    // Read integers into variables and add to vectors
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

  if (column1.size() != column2.size()) {
    std::cerr << "The columns have different sizes! Was there an error with "
                 "the text file?";
    return 1;
  }

  int totalSimilarity = 0;
  for (int i : column1) {
    for (int j : column2) {
      int occurrences = 0;
      if (i == j) {
        occurrences += 1;
      }
      totalSimilarity += (i * occurrences);
    }
  }

  std::cout << "Part 2: " << totalSimilarity;

  return 0;
}
