#include "d3p1.cpp"
#include <gtest/gtest.h>

TEST(Day3Part1Tests, StripCorruptCharacters) {
  std::string data =
      "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
  EXPECT_EQ(strip(data), "mul(2,4)mul(5,5)mul(11,8)mul(8,5)");
}

TEST(Day3Part1Tests, CreateExpression) {
  std::string data = "mul(2,4)mul(5,5)mul(11,8)mul(8,5)";
  EXPECT_EQ(createExpression(data), "2*4+5*5+11*8+8*5");
}

TEST(Day3Part1Tests, Multiply) {
  std::string expression = "2*4";
  EXPECT_EQ(multiply(expression), 8);
}

TEST(Day3Part1Tests, EvaluateExpression) {
  std::string expression = "2*4+5*5+11*8+8*5";
  EXPECT_EQ(evaluateExpression(expression), 161);
}
