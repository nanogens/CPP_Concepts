#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void StringConcat()
{
  system("CLS");
  cout << "\n --- String Concat --- \n";

  string str0; // automatically initializes str0 = "";  (i.e. it calls a default constructor which does that)
  string str1 = "";
  string str2(str1); // another way to declare and initialize string variables is to take the value of one string object and assign it to another
  string str3("a string");
  string str4(10, '*'); // ten *'s
  string str5 = "hello";
  string str6 = " world!";
  string str7 = str5 + str6 + "!";
  //string str8 = "hello" + ", "; // won't work if we try to concatenate two literals together
  string str8 = str5 + ", "; // this works because both are not literals

  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
  cout << str4 << endl;
  cout << str5 << endl;
  cout << str6 << endl;
  cout << str7 << endl;
  cout << str8 << endl;

  getchar();
}

void ComparingStrings()
{
  system("CLS");
  cout << "\n --- Comparing Strings --- \n";

  string s1 = "clear";
  string s2 = "clean";  // clear > clean even if C of clear is capital i.e. Clear
                        // cler is greater than clear  (because r is greater than a)
  if (s1 > s2)
  {
	cout << s1 << " is greater than " << s2 << endl;
  }
  else
  {
	cout << s2 << " is greater than " << s1 << endl;
  }
  
  cout << s1.compare(s2) << endl; // compare 2 strings
  getchar();
}

void SearchingStrings()
{
  system("CLS");
  cout << "\n --- Searching Strings --- \n";

  string s1 = "a needle in a needle haystack";
  string findthis = "needle";

  // Forward find
  cout << "\n --- Forward find\n";
  int pos = s1.find(findthis);  // pos returns starting position of substring.  
                                // only finds first occurance of needle in the string despite there being two needles
                                // needle is in position 2    
  if (pos >= 0)
  {
	cout << "find - Found needle at position " << pos << endl;
  }
  else
  {
	cout << "find - No needle " << pos << endl;  // if we can't find the sub-string, then find returns -1
  }
  getchar();

  //---------------------------------------------------------------------------------------

  // Reverse find 
  cout << "\n --- Reverse find\n";
  int rpos = s1.rfind(findthis);
  if (rpos >= 0)
  {
	cout << "rfind - Found needle at position " << rpos << endl;
  }
  else
  {
	cout << "rfind - No needle " << rpos << endl;  // if we can't find the sub-string, then find returns -1
  }
  getchar();

  //---------------------------------------------------------------------------------------

  // Search for any occurance of a string in another string
  cout << "\n --- Search for any occurance of a string in another string\n";
  string numbers = "0123456789";
  string identifier = "name";
  // finds if 01234... is present in name1 and reports the position of the first occurance of it
  int posff = identifier.find_first_of(numbers);
  if (posff >= 0)
  {
	cout << "Illegal identifier pos : " << posff << endl;
  }
  else
  {
	cout << "Legal identifier pos : " << posff << endl;
	cout << "No numbers you are looking for are present in the string.";
  }
  getchar();
}

void SubstringandReplace()
{
  system("CLS");
  cout << "\n --- Substring and Replace --- \n";

  // Getting a substring within a string (find, substr)
  cout << "\n --- Getting a substring within a string (find, substr)\n";

  string s1 = "a needle in a haystack";
  string word = "needle";
  int pos = s1.find(word); // s1.find(word) and then use
  string s2 = s1.substr(pos, word.length()); // substr(pos, word.length())
  cout << s2 << endl;
  string s3 = s1.substr(pos + word.length() + 1); // +1 to skip over the space
  cout << s3 << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  // Replace
  cout << "\n --- Replacing a substring within a string (replace)\n";
  s1.replace(pos, word.length(), "Manish"); // replaces the word at pos with word length 6 (i.e. needle) with Manish
  cout << s1 << endl;

  getchar();
}

void CStrings()
{
  // C-style strings - strings that were developed in the C language but which works in C++
  // Don't use this in C++ as its old style
  system("CLS");
  cout << "\n --- C-Style strings --- \n" << endl;

  cout << "\n --- Hello world\n";
  char c1[] = { 'h','e','l','l','o','\0' };  // strings in C style must be null terminated
  char c2[] = "world!";
  cout << c1 << " " << c2 << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "\n --- Compare 2 strings\n";
  int value = strcmp(c1, c2); // returns -1 if c1 < c2, +1 if c1 > c2, 0 if c1 == c2
  cout << "Strcmp value : " << value << endl; // returns -1 because hello < world  
  getchar();
}

int main()
{
  StringConcat();
  ComparingStrings();
  SearchingStrings();
  SubstringandReplace(); // used to find or locate substrings within a string, replace is used to take out and replace a substring with another substring
  CStrings(); // C-style strings - strings that were developed in the C language but which works in C++
  return 0;
}