#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm> // for std::copy

using namespace std;

int main()
{
	ifstream is("numbers.txt");
	istream_iterator<double> start(is), end;
	vector<double> numbers(start, end);
	cout << "Read " << numbers.size() << " numbers" << endl;

	// print the numbers to stdout
	cout << "numbers read in:\n";
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, " ")); // leaves a space between each number
	cout << endl;

	// will print the first number
	cout << endl << numbers[0] << endl;

	getchar();
	getchar();
}