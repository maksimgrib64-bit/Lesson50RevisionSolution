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

void print(int array[], int size, string name, bool expected) {
	bool actual = is_the_same_elements(array, size);
	bool result = expected == actual;

	string msg = name + " --> " + (result ? "has completed successfully. Well DONE!!!\033[1;32m [PASS]"
		: "was not running successfully. Try again.\033[1;31m [FAIL]") + "\n";

	msg += "\033[0m";

	if (size > 0) {
		msg += "Array:\t" + convert(array, size) + "\n";
	}
	
	msg += line();

	cout << msg;
}

// no matching elements
void test01() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	bool expected = false;
	print(array, SIZE, "test 01", expected);
}

// only one pair of matching elements (first and last)
void test02() {
	int array[]{ 10, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = 10;
	bool expected = true;
	print(array, size, "test 02", expected);
}

// only one pair of matching elements (at the end)
void test03() {
	int array[]{ 1, 2, 3, 5, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 03", expected);
}

// only one pair of matching elements (at the middle)
void test04() {
	int array[]{ 1, 5, 5, 6, 7 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 04", expected);
}

// only one pair of matching elements (at the beginning)
void test05() {
	int array[]{ 5, 5, 6, 7, 8 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 05", expected);
}

// only one pair of matching elements (at the middle and the end)
void test06() {
	int array[]{ 1, 5, 3, 4, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 06", expected);
}

// only one pair of matching elements (at the middle)
void test07() {
	int array[]{ 1, 2, 4, 4, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 07", expected);
}

// only one pair of matching elements (at the middle)
void test08() {
	int array[]{ 1, 4, 3, 4, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 08", expected);
}

// only one pair of matching elements (at the beginning and the middle)
void test09() {
	int array[]{ 4, 2, 3, 4, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 09", expected);
}

// only one pair of matching elements (at the middle and the end)
void test10() {
	int array[]{ 1, 2, 5, 4, 5 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 10", expected);
}

// two elements
void test11() {
	int array[]{ 1 , 2 };
	int size = 2;
	bool expected = false;
	print(array, size, "test 11", expected);
}

// two matching elements
void test12() {
	int array[]{ 2, 2 };
	int size = 2;
	bool expected = true;
	print(array, size, "test 12", expected);
}

// all matching elements
void test13() {
	int array[]{ 7, 7, 7, 7, 7 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 13", expected);
}

// only one elements
void test14() {
	int array[]{ 1 };
	int size = 1;
	bool expected = false;
	print(array, size, "test 14", expected);
}

void test15() {
	int array[]{ 0 };
	int size = 0;
	int expected = false;
	print(array, size, "test 15", expected);
}

void test16() {
	int array[]{ 0 };
	int size = -1;
	int expected = false;
	print(array, size, "test 16", expected);
}

// all zero (matching) elements
void test17() {
	int array[]{ 0, 0, 0, 0, 0 };
	int size = 5;
	bool expected = true;
	print(array, size, "test 17", expected);
}

void run_all_tests() {
	cout << "\033[1;36mTOTAL 17 tests:\n\033[0m" << line();

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
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
}