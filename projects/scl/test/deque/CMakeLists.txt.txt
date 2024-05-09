add_executable(list_deque_tests test_list_deque.cpp)

target_sources(scl_lib 
	PRIVATE
		test_list_deque_templates.cpp
)

target_link_libraries(list_deque_tests 
	gtest_main 
	scl_lib
)

add_test(list_deque_tests list_deque_tests)
