#include "d5p1.cpp"
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

TEST(Day5Part1Tests, mapPageOrderingRulesIntoMapSimple) {
  vector<pair<int, int>> pageOrderingRules = {
  {29, 13},
  {47, 13},
  {47, 29},
  };
  map<int, set<int>> expected = {
    {29, {13}},
    {47, {13, 29}}
  };

  EXPECT_EQ(mapPageOrderingRules(pageOrderingRules), expected);
}

TEST(Day5Part1Tests, mapPageOrderingRulesIntoMapMedium) {
  vector<pair<int, int>> pageOrderingRulesInput = {
  {47, 53},
  {97, 13},
  {97, 61},
  {97, 47},
  {75, 29},
  {61, 13},
  {75, 53},
  {29, 13},
  {97, 29},
  {53, 29},
  {61, 53},
  {97, 53},
  {61, 29},
  {47, 13},
  {75, 47},
  {97, 75},
  {47, 61},
  {75, 61},
  {47, 29},
  {75, 13},
  {53, 13},
  };
  map<int, set<int>> expected = {
    {29, {13}},
    {47, {53, 13, 61, 29}},
    {53, {29, 13}},
    {61, {13, 53, 29}},
    {75, {29, 53, 47, 61, 13}},
    {97, {13, 61, 47, 29, 53, 75}},
  };

  EXPECT_EQ(mapPageOrderingRules(pageOrderingRulesInput), expected);
}

// Same as above, but sorted the page ordering rules to see if there's a pattern
TEST(Day5Part1Tests, mapPageOrderingRulesIntoMapMedium2) {
  vector<pair<int, int>> pageOrderingRulesInputSorted = {
  {29, 13},
  {47, 13},
  {47, 29},
  {47, 53},
  {47, 61},
  {53, 13},
  {53, 29},
  {61, 13},
  {61, 29},
  {61, 53},
  {75, 13},
  {75, 29},
  {75, 47},
  {75, 53},
  {75, 61},
  {97, 13},
  {97, 29},
  {97, 47},
  {97, 53},
  {97, 61},
  {97, 75},
  };
  map<int, set<int>> expected = {
    {29, {13}},
    {47, {13, 29, 53, 61}},
    {53, {13, 29}},
    {61, {13, 29, 53}},
    {75, {13, 29, 47, 53, 61}},
    {97, {13, 29, 47, 53, 61, 75}},
  };

  EXPECT_EQ(mapPageOrderingRules(pageOrderingRulesInputSorted), expected);
}


TEST(Day5Part1Tests, validUpdateIsGood1) {
  vector<int> update{
    {75,47,61,53,29}
  };

  EXPECT_TRUE(isUpdateGood(update, pageOrderingRules));
}

TEST(Day5Part1Tests, validUpdateIsGood2) {
  vector<int> update{
    {97,61,53,29,13}
  };

  EXPECT_TRUE(isUpdateGood(update, pageOrderingRules));
}

TEST(Day5Part1Tests, validUpdateIsGood3) {
  vector<int> update{
    {75,29,13}
  };

  EXPECT_TRUE(isUpdateGood(update, pageOrderingRules));
}

TEST(Day5Part1Tests, invalidUpdateIsBad1) {
  vector<int> update{
    {75,97,47,61,53} // 75 before 95, which violates 97|75 rule
  };

  EXPECT_FALSE(isUpdateGood(update, pageOrderingRules));
}

TEST(Day5Part1Tests, invalidUpdateIsBad2) {
  vector<int> update{
    {75,97,47,61,53} // 75 before 95, which violates 97|75 rule
  };

  EXPECT_FALSE(isUpdateGood(update, pageOrderingRules));
}
