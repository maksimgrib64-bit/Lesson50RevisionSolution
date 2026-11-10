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

void print(int array[], int expected[], int size,
	int a, int b, string name) {

	reverse(array, size, a, b);

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
		msg += "a = " + to_string(a) + "; b = " + to_string(b) + "\n";
		msg += "Array before:\t" + convert(array, size) + "\n";
		msg += "Array after:\t" + convert(array, size) + "\n";
	}

	msg += line();
	cout << msg;
}

void test01() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 0;
	int b = 9;
	int expected[]{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	print(array, expected, SIZE, a, b, "test 01");
}

void test02() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 9;
	int b = 0;
	int expected[]{ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	print(array, expected, SIZE, a, b, "test 02");
}

void test03() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 3;
	int b = 9;
	int expected[]{ 1, 2, 3, 10, 9, 8, 7, 6, 5, 4 };
	print(array, expected, SIZE, a, b, "test 03");
}

void test04() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 3;
	int b = 8;
	int expected[]{ 1, 2, 3, 9, 8, 7, 6, 5, 4, 10 };
	print(array, expected, SIZE, a, b, "test 04");
}

void test05() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 4;
	int b = 5;
	int expected[]{ 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 05");
}

void test06() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = -4;
	int b = 5;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 06");
}

void test07() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 4;
	int b = -5;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 07");
}

void test08() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 4;
	int b = 20;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 08");
}

void test09() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 20;
	int b = 5;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 09");
}

void test10() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 8;
	int b = 9;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };
	print(array, expected, SIZE, a, b, "test 10");
}

void test11() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 0;
	int b = 1;
	int expected[]{ 2, 1, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 11");
}

void test12() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 3;
	int b = 3;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 12");
}

void test13() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 7;
	int b = 9;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 10, 9, 8 };
	print(array, expected, SIZE, a, b, "test 13");
}

void test14() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 0;
	int b = 2;
	int expected[]{ 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 14");
}

void test15() {
	const int SIZE = 10;
	int array[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int a = 4;
	int b = 20;
	int expected[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print(array, expected, SIZE, a, b, "test 15");
}


// all the same elements
void test16() {
	const int SIZE = 5;
	int array[]{ 1, 1, 1, 1, 1 };
	int a = 2;
	int b = 3;
	int expected[]{ 1, 1, 1, 1, 1 };
	print(array, expected, SIZE, a, b, "test 16");
}

// only one element
void test17() {
	const int SIZE = 1;
	int array[]{ 7 };
	int a = 0;
	int b = 0;
	int expected[]{ 7 };
	print(array, expected, SIZE, a, b, "test 17");
}

// two elements
void test18() {
	const int SIZE = 2;
	int array[]{ 1, 2 };
	int a = 0;
	int b = 1;
	int expected[]{ 2, 1 };
	print(array, expected, SIZE, a, b, "test 18");
}

// two elements
void test19() {
	const int SIZE = 2;
	int array[]{ 2, 1 };
	int a = 1;
	int b = 0;
	int expected[]{ 1, 2 };
	print(array, expected, SIZE, a, b, "test 19");
}

// wrong size
void test20() {
	const int SIZE = -1;
	int array[]{ 0 };
	int a = 0;
	int b = 0;
	int expected[]{ 0 };
	print(array, expected, SIZE, a, b, "test 20");
}

// wrong size
void test21() {
	const int SIZE = 0;
	int array[]{ 1 };
	int a = 0;
	int b = 0;
	int expected[]{ 1 };
	print(array, expected, SIZE, a, b, "test 21");
}

void run_all_tests() {
	cout << "\033[1;36mTOTAL 21 tests:\n\033[0m" << line();

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
	test18();
	test19();
	test20();
	test21();
}