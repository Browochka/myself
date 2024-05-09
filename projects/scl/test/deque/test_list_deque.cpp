
#include <gtest/gtest.h>

#include "list_deque.hpp"

TEST(ListDequeTest, Empty) {
    Browka::ListDeque<int> deque;
    EXPECT_TRUE(deque.empty());

    deque.push_back(1);
    EXPECT_FALSE(deque.empty());
}

TEST(ListDeque, PushBack) {
    Browka::ListDeque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    EXPECT_EQ(deque.size(), 3);
}

TEST(ListDeque, PopFrontAndBack) {
    Browka::ListDeque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    EXPECT_EQ(deque.size(), 3);

    deque.pop_front();
    EXPECT_EQ(deque.size(), 2);
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.back(), 3);

    deque.pop_back();
    EXPECT_EQ(deque.size(), 1);
    EXPECT_EQ(deque.front(), 2);
    EXPECT_EQ(deque.back(), 2);

    deque.pop_back();
    EXPECT_TRUE(deque.empty());
    EXPECT_EQ(deque.size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
