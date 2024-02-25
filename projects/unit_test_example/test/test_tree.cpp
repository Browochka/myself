#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "treesort.hpp"

TEST(ArraysEqual, AnyElementsCount) {
	std::vector<int> actual = { 1, 8, 2, 5, 3, 11,4,5 };
	treesort::sort(actual);
	std::vector<int> expected = { 1,2,3,4,5,5,8,11 };

	ASSERT_EQ(expected.size(), actual.size())
		<< "������ ������� ���������� � ���������������� ��������";

	for (int i = 0; i < actual.size(); i++) {
		ASSERT_EQ(expected[i], actual[i])
			<< "������ ��������� � �������������� ���������� � �������� � �������� "
			<< i;
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}