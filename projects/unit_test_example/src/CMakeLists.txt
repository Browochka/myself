target_sources(treesort_lib 
	PRIVATE
		treesort.cpp
	PUBLIC
		treesort.hpp
)

target_include_directories(treesort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)