#include <climits>
#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(NumConnectedComponentsTest, EmptyMaze) {
  vector<vector<char>> maze = {};
  Print2dVector("maze", maze);

  int expected = 0;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, OneByOneMaze_1) {
  vector<vector<char>> maze = {{'1'}};
  Print2dVector("maze", maze);

  int expected = 1;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, OneByOneMaze_0) {
  vector<vector<char>> maze = {{'0'}};
  Print2dVector("maze", maze);

  int expected = 0;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, SingleComponent) {
  vector<vector<char>> maze = {{'1', '1', '1', '1'},
                               {'1', '0', '0', '1'},
                               {'1', '0', '0', '0'},
                               {'1', '1', '1', '1'}};

  Print2dVector("maze", maze);

  int expected = 1;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, SingleComponent2) {
  vector<vector<char>> maze = {{'1', '1', '1', '1'},
                               {'1', '0', '0', '1'},
                               {'1', '0', '0', '1'},
                               {'1', '1', '1', '1'}};
  Print2dVector("maze", maze);

  int expected = 1;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, TwoByTwoMaze) {
  vector<vector<char>> maze = {//
                               {'1', '1'},
                               {'1', '1'}};
  Print2dVector("maze", maze);

  int expected = 1;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, ThreeByThreeMaze) {
  vector<vector<char>> maze = {//
                               {'1', '1', '1'},
                               {'0', '0', '0'},
                               {'1', '1', '1'}};
  Print2dVector("maze", maze);

  int expected = 2;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, OneByTenMaze) {
  vector<vector<char>> maze = {
      {'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'}};
  Print2dVector("maze", maze);

  int expected = 3;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}

TEST(NumConnectedComponentsTest, ThreeComponents) {
  vector<vector<char>> maze = {//
                               {'1', '1', '1', '1'},
                               {'0', '0', '0', '1'},
                               {'1', '0', '0', '0'},
                               {'0', '1', '1', '1'}};

  Print2dVector("maze", maze);

  int expected = 3;
  int actual = NumConnectedComponents(maze);

  EXPECT_EQ(expected, actual);
}
