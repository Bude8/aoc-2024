#pragma region Includes
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <cassert>
#include <vector>
using namespace std;

#pragma region InputFile
fstream get_input() {
  fstream f("input.txt", ios::in);
  return f;
}
#pragma endregion

int main() {
  fstream f = get_input();
  string ln;

  vector<string> grid;
  while (getline(f, ln)) {
    grid.push_back(ln);
  }

  long tot = 0;

  for (int i = 1; i < grid.size() - 1; i++) {
    for (int j = 1; j < grid[i].length() - 1; j++) {
      stringstream left, right;
      left << grid[i - 1][j - 1] << grid[i][j] << grid[i + 1][j + 1];
      right << grid[i + 1][j - 1] << grid[i][j] << grid[i - 1][j + 1];

      string l = left.str(), r = right.str();
      if ((l == "MAS" || l == "SAM") && (r == "MAS" || r == "SAM")) {
        tot++;
      }
    }
  }

  cout << "P2: " << tot << endl;
}
