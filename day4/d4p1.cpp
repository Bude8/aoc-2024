#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Function to simulate `get_input()`
fstream get_input() {
    // Replace "input.txt" with the actual path to your input file.
    fstream f("input.txt", ios::in);
    if (!f.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        exit(1);
    }
    return f;
}

int main() {
    fstream f = get_input();
    string ln;

    vector<string> grid;
    while (getline(f, ln)) {
        grid.push_back(ln);
    }

    long tot = 0;

    // Rows
    for (string& s : grid) {
        for (int i = 0; i < s.length() - 3; i++) {
            string cut = s.substr(i, 4);
            if (cut == "XMAS" || cut == "SAMX") {
                tot++;
            }
        }
    }

    // Columns
    for (int i = 0; i < grid[0].length(); i++) {
        for (int j = 0; j < grid.size() - 3; j++) {
            stringstream ss;
            ss << grid[j][i] << grid[j + 1][i] << grid[j + 2][i] << grid[j + 3][i];
            if (ss.str() == "XMAS" || ss.str() == "SAMX") {
                tot++;
            }
        }
    }

    // Left diagonal
    for (int r = 0; r < grid.size() - 3; r++) {
        for (int i = 3; i < grid[r].length(); i++) {
            stringstream ss;
            ss << grid[r][i] << grid[r + 1][i - 1] << grid[r + 2][i - 2] << grid[r + 3][i - 3];
            if (ss.str() == "XMAS" || ss.str() == "SAMX") {
                tot++;
            }
        }
    }

    // Right diagonal
    for (int r = 0; r < grid.size() - 3; r++) {
        for (int i = 0; i < grid[r].length() - 3; i++) {
            stringstream ss;
            ss << grid[r][i] << grid[r + 1][i + 1] << grid[r + 2][i + 2] << grid[r + 3][i + 3];
            if (ss.str() == "XMAS" || ss.str() == "SAMX") {
                tot++;
            }
        }
    }

    cout << "P1: " << tot << endl;

    return 0;
}
