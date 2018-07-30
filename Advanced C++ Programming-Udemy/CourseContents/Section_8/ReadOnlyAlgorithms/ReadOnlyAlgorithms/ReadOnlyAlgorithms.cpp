#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for accumulate
#include <numeric>    // for accumulate

#include <list> // for list
#include <iterator> // for back_insert

using namespace std;


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

void ReadOnlyAlgo()
{
  system("CLS");
  cout << "\n --- ReadOnlyAlgo --- \n" << endl;

  cout << "\n --- Sum numbers manually \n\n";
  int sum = 0;
  vector<int> numbers;
  for (int i = 1; i <= 10; i++)
  {
	numbers.push_back(i);
  }
  for (int i = 0; i < numbers.size(); i++)
  {
	sum += numbers[i];
  }
  cout << "\nThe sum is : " << sum << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Accumulate numbers \n\n";
  int sum1 = accumulate(numbers.begin(), numbers.end(), 0); // first element, last element, starting value (added to what you've summed up)
  cout << "The sum using accumulate() template is :" << sum1 << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Accumulate strings \n\n";
  vector<string> words;
  words.push_back("a");
  words.push_back("b");
  words.push_back("c");
  words.push_back("d");
  words.push_back("e");
  words.push_back("f");
  words.push_back("g");

  string palindrome = accumulate(words.begin(), words.end(), string(""));
  cout << palindrome << endl;

  //---------------------------------------------------------------------------------------

  cout << "\n --- Converting a Vector into a List (2 ways) \n\n";
  // One method of inserting a vector into a list
  // You need the library <iterator> at the top for back_insert
  // list<string> wrds;
  // copy(words.begin(), words.end(), std::back_inserter(wrds)); // you can use this

  // A second method of inserting a vector into a list
  // If you're making a new list, you can take advantage of a constructor that takes begin and end iterators
  list<string> wrds(words.begin(), words.end());
  wrds.reverse();
  Display(wrds);

  // You can then compare it to the palindrome

  //---------------------------------------------------------------------------------------


  getchar();
  getchar();
}

int main(void)
{
  ReadOnlyAlgo(); // will access the data in a data structure but not make any modifications
  return 0;
}