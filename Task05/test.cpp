#include "test.h"

string line() {
	return "-----------------------------------------------------------\n";
}

string convert(int array[], int size) {
	if (size <= 0) {
		return "";
	}

	string s = to_string(array[0]);
	for (int i = 1; i < size; i++)
	{
		s += " " + to_string(array[i]);
	}
	return s;
}

void print(int array[], int expected[], int size, string name) {

	reverse(array, size);

	bool result = true;

	for (int i = 0; i < size; i++)
	{
		if (array[i] != expected[i]) {
			result = false;
			break;
		}
	}

	string msg = name + " --> " + (result ? "has completed successfully. Well DONE!!!\033[1;32m [PASS]"
		: "was not running successfully. Try again.\033[1;31m [FAIL]") + "\n";

	msg += "\033[0m";

	if (size > 0) {
		msg += "Array before:\t" + convert(array, size) + "\n";
		msg += "Array after:\t" + convert(array, size) + "\n";
	}

	msg += line();
	cout << msg;
}

// basic case (even number of elements)
void test01() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int expected[]{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	print(array, expected, SIZE, "test 01");
}

// basic case (odd number of elements)
void test02() {
	const int SIZE = 9;
	int array[]{ 10, 9, 8, 7, 6, 5, 4, 3, 2 };
	int expected[]{ 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, "test 02");
}

// basic case (even number of elements)
void test03() {
	const int SIZE = 6;
	int array[]{ 1, -2, 6, 5, -8, 7 };
	int expected[]{ 7, -8, 5, 6, -2, 1 };
	print(array, expected, SIZE, "test 03");
}

// basic case (odd number of elements)
void test04() {
	const int SIZE = 5;
	int array[]{ -2, 6, 5, -8, 7 };
	int expected[]{ 7, -8, 5, 6, -2 };
	print(array, expected, SIZE, "test 04");
}

// all the same elements
void test05() {
	const int SIZE = 5;
	int array[]{ 1, 1, 1, 1, 1 };
	int expected[]{ 1, 1, 1, 1, 1 };
	print(array, expected, SIZE, "test 05");
}

// only one element
void test06() {
	const int SIZE = 1;
	int array[]{ 7 };
	int expected[]{ 7 };
	print(array, expected, SIZE, "test 06");
}

// two elements
void test07() {
	const int SIZE = 2;
	int array[]{ 1, 2 };
	int expected[]{ 2, 1 };
	print(array, expected, SIZE, "test 07");
}

// two elements
void test08() {
	const int SIZE = 2;
	int array[]{ 2, 1 };
	int expected[]{ 1, 2 };
	print(array, expected, SIZE, "test 08");
}

// wrong size
void test09() {
	const int SIZE = -1;
	int array[]{ 0 };
	int expected[]{ 0 };
	print(array, expected, SIZE, "test 09");
}

// wrong size
void test10() {
	const int SIZE = 0;
	int array[]{ 1 };
	int expected[]{ 1 };
	print(array, expected, SIZE, "test 10");
}

void run_all_tests() {
	cout << "\033[1;36mTOTAL 10 tests:\n\033[0m" << line();

	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
}