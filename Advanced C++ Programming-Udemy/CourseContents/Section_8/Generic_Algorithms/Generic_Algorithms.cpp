#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // for accumulate, fill
#include <numeric>    // for accumulate
#include <list> // for list
#include <iterator> // for back_insert
#include <deque>

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

void Read_Only_Algorithms()
{
  system("CLS");
  cout << "\n --- Read Only Algorithms --- \n" << endl;

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

  cout << "\n --- Accumulate numbers using accumulate() \n\n";
  int sum1 = accumulate(numbers.begin(), numbers.end(), 0); // first element, last element, starting value (added to what you've summed up)
  cout << "The sum using accumulate() template is :" << sum1 << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Accumulate strings using accumulate() \n\n";
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
}

template<typename T>
void Display(vector<T> v)
{
  for (int i = 0; i < v.size(); i++)
  {
	cout << v[i] << " ";
  }
  cout << endl;
}

void Read_Write_Algorithms()
{
  system("CLS");
  cout << "\n --- Read Write Algorithms --- \n" << endl;

  cout << "\n --- Fill (fill) \n\n";
  vector<int> numbers;
  for (int i = 1; i <= 10; i++)
  {
	numbers.push_back(i);
  }
  Display(numbers);
  // now fill the vector with zeros
  fill(numbers.begin(), numbers.end(), 0);
  //fill(numbers.begin(), numbers.end(0), ""); // use this to blank out all strings in a vector
  Display(numbers);
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Replace Number (replace) \n\n";
  replace(numbers.begin(), numbers.end(), 0, 10); // replaces ALL 0's with 10's 
  Display(numbers);
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Replace String (replace) \n\n";
  // We will commit a series of words to a vector and replace a word with another word (i.e. Manish with Parasite)
  vector<string> stt;
  stt.push_back("I");
  stt.push_back("am");
  stt.push_back("Manish");
  Display(stt);
  // need this stupid (const string) or it complains about replace not having an overloaded function capable of handing "Manish", "Parasite".
  replace(stt.begin(), stt.end(), (const string) "Manish", (const string) "Parasite");
  Display(stt);
  getchar();
}

void Sorting_Algorithms()
{
  system("CLS");
  cout << "\n --- Sorting Algorithms --- \n" << endl;

  cout << "\n --- Sorting Numbers (changing an array into a vector, sort) \n\n";
  // easier to initialize data in an array and then copy it into a vector
  const int sizeNumbers = 10;
  int numbers[] = { 10,1,9,2,8,3,7,4,6,5 };
  vector<int> nums(numbers, numbers + sizeNumbers);
  cout << "As is : ";
  Display(nums);
  sort(nums.begin(), nums.end());
  cout << "Sorted : ";
  Display(nums);
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Construct Separate Strings of words into One String (sentence) and Sort (sort) \n\n";
  const int size = 16;
  string words[] = { "now","is","the","time","for","all",
					"good","people","to","come","to",
					"the","aid","of","their","party" };
  vector<string> sentence(words, words + size);
  cout << "As is : ";
  Display(sentence);
  sort(sentence.begin(), sentence.end());
  cout << "Sorted : ";
  Display(sentence);
  getchar();
}

template <typename T>
void DisplayDeque(deque<T> ddata)
{
  for (int i = 0; i < ddata.size(); i++)
  {
	cout << "ddata[" << i << "] : " << ddata[i] << endl;
  }
}

void Iterator_Front_Back_Inserter()
{
  system("CLS");
  cout << "\n --- Iterator Front Back Inserter --- \n" << endl;

  cout << "\n --- Back Inserter (back_inserter) \n\n";
  vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  vector<int> v2;
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);

  Display(v1);
  // back_inserter gives us the means of adding data to a container
  // the last item specifies the container we wish to backinsert into
  // the container we are back_inserting into must allow the push_back function to be operable (e.g. array does not have push_back so we do not have back_inserter)
  copy(v2.begin(), v2.end(), back_inserter(v1)); 
  Display(v1);
  getchar();

  cout << "\n --- Front Inserter (front_inserter) \n\n";
  // works with containers that push_front e.g. deque
  deque<int> d1;
  d1.push_front(1);
  d1.push_front(2);
  d1.push_front(3);
  cout << "Initial contents of d1 : " << endl;
  // we can't use the Display() function for this deque unfortunately so we display the Deque as so
  DisplayDeque(d1);
  cout << "Contents of v2 vector : ";
  Display(v2);

  copy(v2.begin(), v2.end(), front_inserter(d1)); // front insert 1, 2, 3 of d1 into 4, 5, 6 of v2 and save it all in d1 

  cout << endl;
  cout << "First and last element of d1 deque following front insert : " << d1.front() << " , " << d1.back() << endl;
  cout << "Full contents of d1 deque following front insert : " << endl;
  DisplayDeque(d1);
  getchar();
}

void Iterator_Reverse()
{
  system("CLS");
  cout << "\n --- Reverse Iterator --- \n" << endl;

  cout << "\n --- Reverse (reverse rbegin rend) \n\n";
  vector<int> numbers;
  for (int i = 1; i <= 10; i++)
  {
	numbers.push_back(i);
  }

  cout << "Forward order : ";
  for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
  {
	cout << *iter << " ";
  }
  cout << endl;
  cout << "Reverse order : ";
  // with reverse, rbegin is end and rend is begin.  riter++ is --
  // don't get confused by this as when we use the reverse_iterator, we are starting from the end and "incrementing" to the beginning (wtf)
  for (vector<int>::reverse_iterator riter = numbers.rbegin(); riter != numbers.rend(); riter++)
  {
	cout << *riter << " ";
  }
  getchar();
}

int main(void)
{
  Read_Only_Algorithms(); // will access the data in a data structure but not make any modifications
  Read_Write_Algorithms(); // algorithms that write data to the container they are working on
  Sorting_Algorithms();
  Iterator_Front_Back_Inserter(); // to specify a particular place in which to insert data into a container
  Iterator_Reverse(); // we can use reverse iterators to determine if a word is a palindrome or not
  return 0;
}