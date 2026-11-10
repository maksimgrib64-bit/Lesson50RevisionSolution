#include "test.h"

string line() {
	return "-----------------------------------------------------------\n";
}

string convert( int array[], int size) {
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

void print( int array[], int expected[], int size, string name) {
	swap_extrem_elements(array, size);
	
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

// extreme elements are at the very beginning and end
void test01() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int expected[]{ 10, 2, 3, 4, 5, 6, 7, 8, 9, 1 };
	print(array, expected, SIZE, "test 01");
}

// several extreme elements (basic case)
void test02() {
	const int SIZE = 10;
	int array[]{ 1, 1, 1, 4, 5, 6, 10, 8, 10, 10 };
	int expected[]{ 1, 1, 10, 4, 5, 6, 10, 8, 10, 1 };
	print(array, expected, SIZE, "test 02");
}

// extreme elements are at the very beginning and end
void test03() {
	const int SIZE = 5;
	int array[]{ 5, 4, 3, 2, 1 };
	int expected[]{ 1, 4, 3, 2, 5 };
	print(array, expected, SIZE, "test 03");
}

// several extreme elements (basic case)
void test04() {
	const int SIZE = 5;
	int array[]{ 5, 5, 1, 2, 1 };
	int expected[]{ 5, 1, 1, 2, 5 };
	print(array, expected, SIZE, "test 04");
}

// two elements
void test05() {
	const int SIZE = 2;
	int array[]{ 1, 2 };
	int expected[]{ 2, 1 };
	print(array, expected, SIZE, "test 05");
}

// two elements
void test06() {
	const int SIZE = 2;
	int array[]{ 2, 1 };
	int expected[]{ 1, 2 };
	print(array, expected, SIZE, "test 06");
}

// all matching elements 
void test07() {
	const int SIZE = 3;
	int array[]{ 5, 5, 5 };
	int expected[]{ 5, 5, 5 };
	print(array, expected, SIZE, "test 07");
}

// wrong size
void test08() {
	const int SIZE = -1;
	int array[]{ 0 };
	int expected[]{ 0 };
	print(array, expected, SIZE, "test 08");
}

// wrong size
void test09() {
	const int SIZE = 0;
	int array[]{ 1 };
	int expected[]{ 1 };
	print(array, expected, SIZE, "test 09");
}

// three elements
void test10() {
	const int SIZE = 3;
	int array[]{ 1, 2, 1 };
	int expected[]{ 1, 1, 2 };
	print(array, expected, SIZE, "test 10");
}

// three elements
void test11() {
	const int SIZE = 3;
	int array[]{ 1, 2, 2 };
	int expected[]{ 2, 2, 1 };
	print(array, expected, SIZE, "test 11");
}


// three elements
void test12() {
	const int SIZE = 3;
	int array[]{ 2, 2, 1 };
	int expected[]{ 2, 1, 2 };
	print(array, expected, SIZE, "test 12");
}

// three elements
void test13() {
	const int SIZE = 3;
	int array[]{ 2, 1, 2 };
	int expected[]{ 2, 2, 1 };
	print(array, expected, SIZE, "test 13");
}

void run_all_tests() {
	cout << "\033[1;36mTOTAL 13 tests:\n\033[0m" << line();

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

}