set(SOURCES 
	test_tree.cpp
)

add_executable(test_tree ${SOURCES})
target_link_libraries(test_tree 
	gtest_main 
	gmock_main 
	treesort_lib
)

add_test(test_tree test_tree)