#include "d4p1.cpp"
#include <gtest/gtest.h>

TEST(Day4Part1Tests, WordSearchNone) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {};
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall1Horizontal) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'M', 'A', 'S', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall1HorizontalBackwards) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'S', 'A', 'M', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{2, 0}, {3, 0}, {4, 0}, {5, 0}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall2Horizontal) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'M', 'A', 'S', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'M', 'A', 'S'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
      {{2, 3}, {3, 3}, {4, 3}, {5, 3}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall2HorizontalBackwards) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'S', 'A', 'M', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'A', 'M', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{2, 0}, {3, 0}, {4, 0}, {5, 0}},
      {{0, 4}, {1, 4}, {2, 4}, {3, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall2HorizontalMix) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'M', 'A', 'S'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'A', 'M', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{2, 0}, {3, 0}, {4, 0}, {5, 0}},
      {{0, 4}, {1, 4}, {2, 4}, {3, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall1Vertical) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'M', 'X', 'X', 'X', 'X', 'X'},
                                               {'A', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall1VerticalBackwards) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'X', 'X', 'X', 'X', 'X'},
                                               {'A', 'X', 'X', 'X', 'X', 'X'},
                                               {'M', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 1}, {0, 2}, {0, 3}, {0, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall2Vertical) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'M', 'X', 'X', 'X', 'X'},
                                               {'X', 'A', 'X', 'M', 'X', 'X'},
                                               {'X', 'S', 'X', 'A', 'X', 'X'},
                                               {'X', 'X', 'X', 'S', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{1, 0}, {1, 1}, {1, 2}, {1, 3}},
      {{3, 1}, {3, 2}, {3, 3}, {3, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmall2VerticalBackwards) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'X', 'X', 'X', 'X', 'S'},
                                               {'A', 'X', 'X', 'X', 'X', 'A'},
                                               {'M', 'X', 'X', 'X', 'X', 'M'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 1}, {0, 2}, {0, 3}, {0, 4}},
      {{5, 1}, {5, 2}, {5, 3}, {5, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmallDiagonalUpRight) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'S', 'X', 'X'},
                                               {'X', 'X', 'A', 'X', 'X', 'X'},
                                               {'X', 'M', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 4}, {1, 3}, {2, 2}, {3, 1}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmallDiagonalDownRight) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'M', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'A', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'S', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 0}, {1, 1}, {2, 2}, {3, 3}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmallDiagonalUpLeft) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'S', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'A', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'M', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchSmallDiagonalDownLeft) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'X', 'M', 'X', 'X', 'X'},
                                               {'X', 'A', 'X', 'X', 'X', 'X'},
                                               {'S', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{0, 4}, {1, 3}, {2, 2}, {3, 1}},
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchMediumMix) {
  std::vector<std::vector<char>> wordSearch = {{'X', 'X', 'X', 'X', 'X', 'X'},
                                               {'X', 'S', 'A', 'M', 'X', 'X'},
                                               {'X', 'A', 'X', 'X', 'A', 'X'},
                                               {'X', 'M', 'A', 'S', 'X', 'S'},
                                               {'X', 'X', 'X', 'X', 'X', 'X'}};
  std::vector<std::vector<std::pair<int, int>>> matches = {
      {{2, 0}, {3, 1}, {4, 2}, {5, 3}}, // Diagonal
      {{1, 1}, {2, 1}, {3, 1}, {4, 1}}, // Horizontal backwards
      {{1, 1}, {1, 2}, {1, 3}, {1, 4}}, // Vertical backwards
      {{0, 3}, {1, 3}, {2, 3}, {3, 3}}, // Horizontal
  };
  EXPECT_EQ(doWordSearch(wordSearch), matches);
}

TEST(Day4Part1Tests, WordSearchLargeMix) {
  std::vector<std::vector<char>> wordSearch = {
      {'M', 'M', 'M', 'S', 'X', 'X', 'M', 'A', 'S', 'M'},
      {'M', 'S', 'A', 'M', 'X', 'M', 'S', 'M', 'S', 'A'},
      {'A', 'M', 'X', 'S', 'X', 'M', 'A', 'A', 'M', 'M'},
      {'M', 'S', 'A', 'M', 'A', 'S', 'M', 'S', 'M', 'X'},
      {'X', 'M', 'A', 'S', 'A', 'M', 'X', 'A', 'M', 'M'},
      {'X', 'X', 'A', 'M', 'M', 'X', 'X', 'A', 'M', 'A'},
      {'S', 'M', 'S', 'M', 'S', 'A', 'S', 'X', 'S', 'S'},
      {'S', 'A', 'X', 'A', 'M', 'A', 'S', 'A', 'A', 'A'},
      {'M', 'A', 'M', 'M', 'M', 'X', 'M', 'M', 'M', 'M'},
      {'M', 'X', 'M', 'X', 'A', 'X', 'M', 'A', 'S', 'X'},
  };
  std::vector<std::vector<std::pair<int, int>>> matches =
      doWordSearch(wordSearch);
  EXPECT_EQ(matches.size(), 18);
}
