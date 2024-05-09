#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"


TEST(DoublyLinkedListTest, push_back) {
    Browka::DoublyLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_EQ(l.size(), 3);
}

TEST(DoublyLinkedListTest, has_item) {
    Browka::DoublyLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_TRUE(l.has_item(3));
    EXPECT_FALSE(l.has_item(4));
}

TEST(DoublyLinkedListTest, remove_first) {
    Browka::DoublyLinkedList<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.remove_first(1);
    EXPECT_EQ(l.size(), 2);
    EXPECT_FALSE(l.has_item(1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}