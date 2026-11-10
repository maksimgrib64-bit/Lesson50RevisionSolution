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

void print(int array[], int size, string name, int expected) {
	int actual = count_nonzero_elements(array, size);
	bool result = expected == actual;

	string msg = name + " --> " + (result ? "has completed successfully. Well DONE!!!\033[1;32m [PASS]"
		: "was not running successfully. Try again.\033[1;31m [FAIL]") + "\n";

	msg += "\033[0m";

	if (size > 0) {
		msg += "Array:\t" + convert(array, size) + "\n";
	}
	msg += "Your count of non-zero elements is " + to_string(actual) + "\n";
	msg += line();
	cout << msg;
}

// all non-zero elements
void test01() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int expected = 10;
	print(array, SIZE, "test 01", expected);
}

// only one zero element
void test02() {
	const int SIZE = 5;
	int array[]{ 1, 2, 0, 4, 5 };
	int expected = 4;
	print(array, SIZE, "test 02", expected);
}

// basic case
void test03() {
	const int SIZE = 10;
	int array[]{ 1, 2, 0, 4, 0, 6, 0, 8, 9, 10 };
	int expected = 7;
	print(array, SIZE, "test 03", expected);
}

// all zero elements
void test04() {
	const int SIZE = 10;
	int array[SIZE]{ };
	int expected = 0;
	print(array, SIZE, "test 04", expected);
}

// only one non-zero element
void test05() {
	const int SIZE = 5;
	int array[]{ 0, 0, 1, 0, 0 };
	int expected = 1;
	print(array, SIZE, "test 05", expected);
}

// one zero element
void test06() {
	const int SIZE = 1;
	int array[]{ 0 };
	int expected = 0;
	print(array, SIZE, "test 06", expected);
}

// one non-zero element
void test07() {
	const int SIZE = 1;
	int array[]{ 1 };
	int expected = 1;
	print(array, SIZE, "test 07", expected);
}

// only one non-zero element
void test08() {
	const int SIZE = 2;
	int array[]{ 0, 1 };
	int expected = 1;
	print(array, SIZE, "test 08", expected);
}

// wrong size
void test09() {
	const int SIZE = 0;
	int array[]{ 0 };
	int expected = -1;
	print(array, SIZE, "test 09", expected);
}

// wrong size
void test10() {
	const int SIZE = -1;
	int array[]{ 0 };
	int expected = -1;
	print(array, SIZE, "test 10", expected);
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