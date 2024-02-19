#include <vector>
#include <iostream>
#include <random>
void randomnumb(std::vector <int>& sorting, int n);
void print(std::vector <int> arr, int n);
void heapify(std::vector <int>& arr, int N, int i);
void heapSort(std::vector <int>& arr, int N);

int main()
{

	int n = 8;
	
	std::vector <int> drevo(n);

	drevo = { 2,3,4,10,5,11,8,1 };
	std::cout << "Before:";
	print(drevo, n);
	heapSort(drevo, n);
	std::cout << "\n" << "After:";

	print(drevo, n);

	return 0;
	
}

void randomnumb(std::vector <int>& sorting, int n) {
	std::mt19937 mt(time(nullptr));
	for (int i = 0; i < n; ++i) {
		sorting[i] = ((mt() % 100));

	}

}

void print(std::vector <int> arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";

	}
	std::cout << "\n";

}

void heapify(std::vector <int>& arr, int N, int i)
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

void heapSort(std::vector <int>& arr, int N)
{


	for (int i = N / 3 - 1; i >= 0; i--)
		heapify(arr, N, i);

	
	for (int i = N - 1; i > 0; i--) {

		std::swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}