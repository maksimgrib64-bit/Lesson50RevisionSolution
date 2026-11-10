#include "logic.h"
//O(N)
int count_nonzero_elements(int array[], int size) {
	if (size <= 0) {
		return -1;
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > 0) {
			count++;
		}
	}
	return count;
}
