#include "PStackTemplate.h"
#include <iostream>

using namespace std;

int main()
{
	PStack<double> test;

	test.Push(7);
	cout << test.Pop();

	PStack<int> a;

	auto pi = 3;

	return 0;
}