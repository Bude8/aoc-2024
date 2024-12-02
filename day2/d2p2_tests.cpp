#include "d2p2.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(Day2Part1Tests, SafeWithoutLevelRemoved) {
  std::vector<int> row = {7, 6, 4, 2, 1};
  EXPECT_TRUE(isSafe(row));
}

TEST(Day2Part1Tests, UnsafeWithLevelRemoved) {
  std::vector<int> row = {1, 2, 7, 8, 9};
  EXPECT_FALSE(isSafe(row));
}

TEST(Day2Part1Tests, UnsafeWithLevelRemoved2) {
  std::vector<int> row = {9, 7, 6, 2, 1};
  EXPECT_FALSE(isSafe(row));
}

TEST(Day2Part1Tests, SafeByRemovingSecondLevel) {
  std::vector<int> row = {1, 3, 2, 4, 5};
  EXPECT_TRUE(isSafe(row));
}

TEST(Day2Part1Tests, SafeByRemovingThirdLevel) {
  std::vector<int> row = {8, 6, 4, 4, 1};
  EXPECT_TRUE(isSafe(row));
}

TEST(Day2Part1Tests, SafeWithoutLevelRemoved2) {
  std::vector<int> row = {1, 3, 6, 7, 9};
  EXPECT_TRUE(isSafe(row));
}
