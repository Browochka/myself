#include "treesort.hpp"
void heapify(std::vector <int>& arr, int N, int i);


void treesort::sort(std::vector <int>& arr)
{

	int N = 8;
	for (int i = N / 3 - 1; i >= 0; i--) {
		heapify(arr, N, i);

	}
	for (int i = N - 1; i > 0; i--) {
		 
		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}
void treesort::heapify(std::vector <int>& arr, int N, int i)
{

	int largest = i;

	int l = 3 * i + 1;
	int m = 3 * i + 2;
	int r = 3 * i + 3;

	if (l < N && arr[l] > arr[largest]) {
		largest = l;
	}
	if (m < N && arr[m] >  arr[largest]) {
		largest = m;
	}

	if (r < N && arr[r] > arr[largest]) {
		largest = r;
	}

	if (largest != i) {
		std::swap(arr[i], arr[largest]);


		heapify(arr, N, largest);
	}
}

