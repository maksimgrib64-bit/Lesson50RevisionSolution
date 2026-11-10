#include "logic.h"
int main() {
	int size;
	cout << "Input size:";
	cin >> size;
	if (size <= 0 or size > MAX_SIZE) {
		cout << "Size must be between 1 and " << MAX_SIZE << endl;
		return -1;
	}

	int* array = new int[size];
	cout << "Input elements:";
	for (int i = 0; i < size; ++i) cin >> array[i];

	double result = find_sum(array, size);
	cout << "Sum of elements smaller than average is " << result << endl;

	return 0;
}