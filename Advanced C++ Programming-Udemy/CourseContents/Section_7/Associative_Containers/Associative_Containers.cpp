#include <iostream>
#include <utility> // for pair
#include <string>
#include <map> // for map
#include <set> // for set

using namespace std;

void Pair()
{
	system("CLS");
	cout << "\n --- Pair --- \n" << endl;

	cout << "\n --- Pair (first, second) \n\n";

	// instantiate an object number1 with <first data type, second data type>
	pair<string, string> number1("Jones", "123");
	cout << number1.first << " : " << number1.second << endl;
	getchar();

	//---------------------------------------------------------------------------------------

	pair<string, int> student1("Brown", 80);
	cout << student1.first << " : " << student1.second << endl;
	getchar();

	//---------------------------------------------------------------------------------------
}

void Map1()
{
	system("CLS");
	cout << "\n --- Map1 --- \n" << endl;

	cout << "\n --- Map (size, erase) \n\n";

	// <data type of the key, datatype of the value>  name of the map
	// internally we are storing the value we are using the pair class
	map<string, string> numbers;

	numbers["Jones"] = "365";
	numbers["Smith"] = "467";
	numbers["Brown"] = "111";
	cout << "Jones : " << numbers["Jones"] << endl;
	cout << "Number of numbers : " << numbers.size() << endl;
	numbers.erase("Smith");
	cout << "Number of numbers : " << numbers.size() << endl;
	getchar();
}

void Map2()
{
	system("CLS");
	cout << "\n --- Map2 --- \n" << endl;

	cout << "\n --- Map (find, end) \n\n";
	map<string, int> grades;
	grades["Jones"] = 78;
	grades["Smith"] = 83;
	grades["Green"] = 92;
	string name;
	cout << endl << "Enter a name to find : ";
	cin >> name;
	// an iterator based find (used in an if statement)
	if (grades.find(name) != grades.end())
	{
		cout << name << ": " << grades[name] << endl;
	}
	else
	{
		cout << "\nName not found.." << endl;
	}

	//---------------------------------------------------------------------------------------

	cout << "\n --- Map (sum, using -> with an iterator) \n\n";
	double average = 0.0;
	int sum = 0;
	map<string, int>::iterator it = grades.begin();
	while (it != grades.end())
	{
		sum += it->second; // returns the 2nd element in the map which is the grade
		cout << it->second << endl;
		it++;
	}
	average = (sum / grades.size());
	cout << "\nThe average grade is : " << average << endl;

	getchar();
	getchar();
}

void Sets()
{
	system("CLS");
	cout << "\n --- Set --- \n" << endl;

	cout << "\n --- Set (insert, begin, end) Note : Duplicates are not entered into the set.  The output is in alphabetical order and sequence of entry does not matter. \n\n";
	set<string> words;
	string word = "";
	do
	{
		cout << "Enter a word ('quit' to quit) : ";
		cin >> word;
		if (word != "quit")  // have to do this or it will include the word "quit" in the set
		{
			words.insert(word);
		}
	}
	while(word != "quit");

	cout << endl;
	set<string>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << *it << endl;
		it++;
	}
	getchar();
	getchar();
}

int main()
{
	// Section 7
	Pair();
	Map1();
	Map2();
	Sets(); // repeated words only inserted one time in the set (duplicates eliminated).  output is in alphabetical order.
	return 0; // must return an int or it will crash!
}