#include "d2p1.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(Day2Part1Tests, DescendingRowValidDifference) {
  std::vector<int> row = {7, 6, 4, 2, 1};
  EXPECT_TRUE(isSorted(row));
  EXPECT_TRUE(isValidDifference(row));
}

TEST(Day2Part1Tests, AscendingRowInvalidDifference) {
  std::vector<int> row = {1, 2, 7, 8, 9};
  EXPECT_TRUE(isSorted(row));
  EXPECT_FALSE(isValidDifference(row)); // Difference of 5
}

TEST(Day2Part1Tests, DescendingRowInvalidDifference) {
  std::vector<int> row = {9, 7, 6, 2, 1};
  EXPECT_TRUE(isSorted(row));
  EXPECT_FALSE(isValidDifference(row)); // Difference of 4
}

TEST(Day2Part1Tests, NotSortedValidDifference) {
  std::vector<int> row = {1, 3, 2, 4, 5};
  EXPECT_FALSE(isSorted(row));         // Mixed increasing and decreasing
  EXPECT_TRUE(isValidDifference(row)); // All differences are between 1 and 3
}

TEST(Day2Part1Tests, DescendingRowInvalidDifference2) {
  std::vector<int> row = {8, 6, 4, 4, 1};
  EXPECT_TRUE(isSorted(row));           // Sorted in descending order
  EXPECT_FALSE(isValidDifference(row)); // 4 -> 4 is not a valid difference
}

TEST(Day2Part1Tests, AscendingRowValidDifference) {
  std::vector<int> row = {1, 3, 6, 7, 9};
  EXPECT_TRUE(isSorted(row));
  EXPECT_TRUE(isValidDifference(row)); // All differences are valid
}
