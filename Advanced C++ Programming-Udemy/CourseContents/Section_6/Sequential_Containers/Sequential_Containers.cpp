#include <iostream>
#include <vector> 
#include <list> 
#include <string> 

using namespace std;

void Vector()
{
	system("CLS");
	cout << "\n\n --- Vector --- \n\n";

	// A vector will grow automatically as we add items beyond the initial array size.  
	// In this case initial array size is 0.
	// If we had numbers(10) in there, then the push_back function would add numbers to the 11th position (i.e. number[10])
	vector<int> numbers; 
	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(i);
		cout << "numbers[" << i << "]" << " = " << numbers[i] << "\n";
	}

	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	cout << "\n" << "Total" << " = " << sum;
	getchar();
}

void ListVector()
{
	system("CLS");
	cout << "\n --- ListVector --- \n";

	list<string> names;
	names.push_back("Amit");
	names.push_back("Manish");
	names.push_back("Zaki");

	cout << "\n --- Forward order list printing \n";
	// Forward order printing of list
	// Get an iterator to the beginning of the string
	list<string>::iterator iter = names.begin();
	while (iter != names.end())
	{
		cout << *iter << endl;
		iter++;
	}
	cout << "names.front() = " << names.front() << endl;
	cout << "names.back() = " << names.back() << endl;
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Reverse order list printing 1\n";
	// Reverse order printing of list - Take 1
	list<string>::iterator riter = names.end();
	while (riter != names.begin())
	{
		riter--; // have to put this here first so it decrements by one from the total number of elements in the list e.g. 10 = 0 to 9 elements so we decrement from 10 to 9 FIRST before doing stuff
		cout << *riter << endl;
	}
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Reverse order list printing 2 (note : list is actually reversed in memory here, not just printed in reverse order)\n";
	// Reverse order printing of list - Take 2
	names.reverse();
	list<string>::iterator riter2 = names.begin();
	while (riter2 != names.end())
	{
		cout << *riter2 << endl;
		riter2++;
	}
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Sort the list \n";
	names.sort();
	list<string>::iterator siter = names.begin();
	while (siter != names.end())
	{
		cout << *siter << endl;
		siter++;
	}
	getchar();
}

int main()
{
	Vector();
	ListVector();

	return 0; // must return an int or it will crash!
}