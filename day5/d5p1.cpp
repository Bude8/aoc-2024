#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Function to split a line into two integers based on '|'
pair<int, int> parseLine(const string &line) {
  stringstream ss(line);
  string firstPart, secondPart;
  getline(ss, firstPart, '|');
  getline(ss, secondPart);
  return {stoi(firstPart), stoi(secondPart)};
}

vector<pair<int, int>> readPageOrderingRules(const string &fileName) {
  vector<pair<int, int>> data;
  ifstream inputFile(fileName);

  if (!inputFile) {
    cerr << "Error: Could not open file " << fileName << endl;
    return data;
  }

  string line;
  while (getline(inputFile, line)) {
    if (!line.empty()) {
      data.push_back(parseLine(line));
    }
  }

  if (data.empty()) {
    cout << "No data read from the file." << endl;
  }

  inputFile.close();
  return data;
}

// Function to parse a line of comma-separated values into a vector of integers
vector<int> parseCSVLine(const string &line) {
  vector<int> values;
  stringstream ss(line);
  string value;

  while (getline(ss, value, ',')) {
    values.push_back(stoi(value));
  }

  return values;
}

vector<vector<int>> readPagesInUpdates(const string &fileName) {
  vector<vector<int>> data;
  ifstream inputFile(fileName);

  if (!inputFile) {
    cerr << "Error: Could not open file " << fileName << endl;
    return data;
  }

  string line;
  while (getline(inputFile, line)) {
    if (!line.empty()) {
      data.push_back(parseCSVLine(line));
    }
  }

  if (data.empty()) {
    cout << "No data read from the file." << endl;
  }

  inputFile.close();
  return data;
}

// Map where the key is an integer, and the value is a set showing numbers that
// can only go after it
map<int, set<int>>
mapPageOrderingRules(vector<pair<int, int>> pageOrderingRules) {
  map<int, set<int>> result;

  for (const auto &rule : pageOrderingRules) {
    int key = rule.first;
    int value = rule.second;
    result[key].insert(value);
  }

  return result;
}

// Update is good if it respects the page ordering rules
// TODO: Can optimise this by refactoring to return the middle element
// of good updates as problem requires
bool isUpdateGood(vector<int> update, map<int, set<int>> pageOrderingRules) {
  vector<int> seen;
  for (const int &i : update) {
    seen.push_back(i);
    // if a number is in seen, and it appears in the set, it has violated the
    // rule
    for (const int &j : seen) {
      if (pageOrderingRules[i].count(j)) {
        return false;
      }
    }
  }
  return true;
}

#ifndef RUNNING_TESTS // If not running tests, run the main program
int main() {
  const string pageOrderingRulesFile = "input_page_ordering_rules.txt";
  vector<pair<int, int>> pageOrderingRules =
      readPageOrderingRules(pageOrderingRulesFile);

  const string pagesInUpdatesFile = "input_pages_in_updates.txt";
  vector<vector<int>> pagesInUpdates = readPagesInUpdates(pagesInUpdatesFile);

  map<int, set<int>> pageOrderingRulesMap =
      mapPageOrderingRules(pageOrderingRules);

  vector<vector<int>> goodUpdates;

  for (const auto &row : pagesInUpdates) {
    if (isUpdateGood(row, pageOrderingRulesMap)) {
      goodUpdates.push_back(row);
    }
  }

  int total = 0;
  for (const auto &row : goodUpdates) {
    int mid = row.at(row.size() / 2);
    total += mid;
  }

  cout << "Total: " << total;

  return 0;
}

#endif // RUNNING_TESTS
