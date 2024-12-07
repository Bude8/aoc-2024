#include "d5p2.cpp"
#include <gtest/gtest.h>

using namespace std;
map<int, set<int>> pageOrderingRules = {
    {29, {13}},
    {47, {13, 29, 53, 61}},
    {53, {13, 29}},
    {61, {13, 29, 53}},
    {75, {13, 29, 47, 53, 61}},
    {97, {13, 29, 47, 53, 61, 75}},
};

TEST(Day5Part1Tests, fixBadUpdate1) {
  vector<int> update = {75, 97, 47, 61, 53};
  vector<int> expected = {97, 75, 47, 61, 53};
  EXPECT_EQ(sortBadUpdate(update, pageOrderingRules), expected);
}

TEST(Day5Part1Tests, fixBadUpdate2) {
  vector<int> update = {{61, 13, 29}};
  vector<int> expected = {61, 29, 13};
  EXPECT_EQ(sortBadUpdate(update, pageOrderingRules), expected);
}

TEST(Day5Part1Tests, fixBadUpdate3) {
  vector<int> update = {{97, 13, 75, 29, 47}};
  vector<int> expected = {97, 75, 47, 29, 13};
  EXPECT_EQ(sortBadUpdate(update, pageOrderingRules), expected);
}
