#include <iostream>

using namespace std;

namespace firstNums
{
  int num1 = 10;
  int num2 = 12;
}

namespace secondNums
{
  int num1 = 1;
  int num2 = 2;
}

namespace minMax
{
  int Min(int num1, int num2)
  {
	if (num1 < num2)
	{
	  return num1;
	}
	else
	{
	  return num2;
	}
  }

  int Max(int num1, int num2)
  {
	if (num1 > num2)
	{
	  return num1;
	}
	else
	{
	  return num2;
	}
  }
}

namespace People
{
  class Person
  {
    private:
	  string name;
	  string sex;
    public:
	  Person(string n, string s)
	  {
		name = n;
		sex = s;
	  }
	  string get()
	  {
		return name + ", " + sex;
	  }
  };
}

void MM()
{
  using namespace minMax;
  using namespace People;
  int a, b;
  cout << "Enter a number : ";
  cin >> a;
  cout << "Enter another number : ";
  cin >> b;
  cout << Min(a, b) << endl;
  cout << Max(a, b) << endl;
  getchar();
  getchar();
}

void Namesp()
{
  cout << "num1 in firstNums : " << firstNums::num1 << endl;
  cout << "num1 in secondNums : " << secondNums::num1 << endl;
  cout << endl;
  cout << "num2 in firstNums : " << firstNums::num2 << endl;
  cout << "num2 in secondNums : " << secondNums::num2 << endl;

  getchar();

  {
	using namespace firstNums;
	cout << "num1 in firstNums : " << num1 << endl;
	cout << "num2 in firstNums : " << num2 << endl << endl;
  }
  {
	using namespace secondNums;
	cout << "num1 in secondNums : " << num1 << endl;
	cout << "num2 in secondNums : " << num2 << endl;
  }
  getchar();
}

int main()
{
  //Namesp();
  MM();
  return 0;
}
