#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	// ----- 2 numbers input, added and printed out
	//
	// Memory exists as MAIN, STACK, HEAP
	// Our program is loaded into MAIN memory
	// The variables a, b, c are loaded into STACK memory
	// << insertion operator
	// >> extraction operator
	int a, b, c = 0;
	cout << "Enter 2 numbers : \n";
	cin >> a >> b; 
	cout << "\nThe first number you entered was " << a << " and the second number was " << b << ".\n";
	c = a + b;
	cout << "\n\na + b = " << c << "\n";
	cout << "\n\n -----------------------------------------";
	getchar();
	getchar();

	// ----- Name input and printing
	//
	string strr;
	cout << "\n\nMay I know your name : ";
	//cin >> strr;
	getline(cin, strr);
	cout << "\n\nYour name is : " << strr << "\n";
	cout << "\n\n -----------------------------------------";
	getchar();
	getchar();

	// ----- Data type span
	//
	int x;
	cout << "\n\n" << sizeof(x) << "\n";
	cout << "\n\n" << INT_MAX << " to " << INT_MIN << ".\n\n";
	cout << "\n\n -----------------------------------------";
	getchar();
	getchar();
	// ----- Assigning
	//
	int x0 = 1;
	int x1(1);
	int x2 = (2);
	int x3{ 3 };
	int x4 = { 4 };
	cout << "\n\n -----------------------------------------";
	getchar();
	getchar();

	return 0;
}