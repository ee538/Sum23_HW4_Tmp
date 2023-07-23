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
TEST(HikerPathTest, Empty) {
  vector<vector<int>> maze = {};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{-1, -1}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, OneByOne) {
  vector<vector<int>> maze = {{0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{0, 0}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, OneByOne_Impossible) {
  vector<vector<int>> maze = {{1}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{-1, -1}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, SimpleMaze) {
  vector<vector<int>> maze = {//
                              {0, 0, 0, 1},
                              {0, 1, 0, 1},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{0, 0}, {0, 1}, {0, 2}, {1, 2},
                                      {2, 2}, {2, 3}, {3, 3}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, NeedUpDirection) {
  vector<vector<int>> maze = {//
                              {0, 1, 0, 0, 0},
                              {0, 1, 0, 1, 0},
                              {0, 1, 0, 1, 0},
                              {0, 0, 0, 1, 0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1},
                                      {3, 2}, {2, 2}, {1, 2}, {0, 2}, {0, 3},
                                      {0, 4}, {1, 4}, {2, 4}, {3, 4}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, NeedLeftDirection) {
  vector<vector<int>> maze = {//
                              {0, 0, 0, 0, 0},
                              {1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1},
                              {0, 0, 0, 0, 0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {
      {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 4}, {2, 4}, {2, 3}, {2, 2},
      {2, 1}, {2, 0}, {3, 0}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, NoPath1) {
  vector<vector<int>> maze = {//
                              {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 1, 0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{-1, -1}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}

TEST(HikerPathTest, NoPath2) {
  vector<vector<int>> maze = {//
                              {0, 1, 1, 1},
                              {1, 0, 1, 1},
                              {1, 1, 0, 1},
                              {1, 1, 1, 0}};
  Print2dVector("maze", maze);

  vector<vector<int>> expectedPath = {{-1, -1}};
  vector<vector<int>> actualPath = HikerPath(maze);

  EXPECT_EQ(expectedPath, actualPath);
}
