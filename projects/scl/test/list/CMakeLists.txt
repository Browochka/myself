add_executable(list_tests test_list.cpp test_list_templates.cpp)

target_sources(scl_lib 
	PRIVATE
		test_list_templates.cpp
)

target_link_libraries(list_tests 
	gtest_main 
	scl_lib
)

add_test(list_tests list_tests)