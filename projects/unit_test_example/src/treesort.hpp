#ifndef TREESORT_HPP
#define TREESORT_HPP

#include <vector>

namespace treesort {
    void sort(std::vector<int> &arr);
    void heapify(std::vector <int>& arr, int N, int i);
}

#endif