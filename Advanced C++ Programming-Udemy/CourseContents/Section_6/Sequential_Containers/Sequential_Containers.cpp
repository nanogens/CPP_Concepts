#include <iostream>
#include <vector> 
#include <list> 
#include <string> 
#include <deque>

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

void Display(list<string> lyst)
{
	// Get an iterator to the beginning of the string
	list<string>::iterator iter = lyst.begin();
	while (iter != lyst.end())
	{
		cout << *iter << endl;
		iter++;
	}
}

void ListVector()
{
	system("CLS");
	cout << "\n --- ListVector --- \n";

	list<string> names;
	names.push_back("Amit");
	names.push_back("Manish");
	names.push_back("Zaki");

	cout << "\n --- Forward order list printing\n";
	// Forward order printing of list
	Display(names);
	cout << "names.front() = " << names.front() << endl;
	cout << "names.back() = " << names.back() << endl;
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Reverse order list printing 1 (done manually, no command) \n";
	// Reverse order printing of list - Take 1
	list<string>::iterator riter = names.end();
	while (riter != names.begin())
	{
		riter--; // have to put this here first so it decrements by one from the total number of elements in the list e.g. 10 = 0 to 9 elements so we decrement from 10 to 9 FIRST before doing stuff
		cout << *riter << endl;
	}
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Reverse order list printing 2 (reverse) (note : list is actually reversed in memory here, not just printed in reverse order)\n";
	// Reverse order printing of list - Take 2
	names.reverse();
	Display(names);
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Sort the list (sort) \n";
	names.sort();
	Display(names);
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Add item to beginning of the list (push_front) \n";
	names.push_front("Avi");
	Display(names);
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Size of the list (size) \n";
	cout << "Size of the list : " << names.size() << endl;
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Remove a specified item from the list (remove) \n";
	names.remove("Avi");
	Display(names);
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Remove item from the front of the list (pop_front) and back of the list (pop_back) \n";
	names.pop_front();
	names.pop_back();
	Display(names);
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Clear list (clear) and check if list is empty (empty) \n";
	names.clear();
	if (names.empty() == true)
	{
		cout << "List is now empty" << endl;
	}
	else
	{
		cout << "List is not yet empty" << endl;
	}
	Display(names);
	getchar();
}

void Deque1()
{
	system("CLS");
	cout << "\n --- Deque 1 --- \n" << endl;

	cout << "\n --- Deque push (push_back, push_front) \n";

	deque<string> line;
	line.push_back("Customer 1");
	line.push_front("Customer 2");
	line.push_back("Customer 3");

	for(int i = 0; i < line.size(); i++)
	{
		cout << "line[" << i << "] : " << line[i] << endl;
	}
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Deque (pop_back, pop_front) \n";
	line.pop_back();
	line.pop_front();
	for (int i = 0; i < line.size(); i++)
	{
		cout << "line[" << i << "] : " << line[i] << endl;
	}
	getchar();
}

int Find(deque<string> d, string value)
{
	for (int i = 0; i < d.size(); i++)
	{
		if (d.at(i) == value)
		{
			return i; // position in deque where string was found
		}
	}
	return -1; // did not find the item requested
}

void Deque2()
{
	system("CLS");
	cout << "\n --- Deque 2 --- \n" << endl;

	cout << "\n --- Deque find at (at) \n\n";
	deque<string> line;
	line.push_back("Narain");
	line.push_back("Vivaan");
	line.push_back("Khushi");
	line.push_back("Priti");
	line.push_back("Jeena");

	string name;
	cout << "Name to find : ";
	cin >> name;
	int pos = Find(line, name);
	if (pos > -1)
	{
		cout << name << " found at position " << pos << endl;
	}
	else
	{
		cout << name << " not found." << endl;
	}
	getchar();
	getchar();

	//---------------------------------------------------------------------------------------

	cout << "\n --- Iterator on a deque to loop through the values rather than using indexing \n\n";
	deque<string>::iterator iter = line.begin();
	iter++; // position the iterator where you want the item to go in to the deque
	line.insert(iter, "Parasite");
	for (iter = line.begin(); iter < line.end(); iter++)
	{
		cout << *iter << endl;
	}
	getchar();

	//---------------------------------------------------------------------------------------
}


int main()
{
	// Section 6
	//Vector();
	//ListVector();
	//Deque1(); //  allows us to add / remove items at both the front and back of the deck
	//Deque2();

	return 0; // must return an int or it will crash!
}