#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class test
{
private:
	int m;
public:
	test();
	void SetNumLines(int);
	void Lines();
	virtual void Virtua(void);
};

void test::Virtua(void)
{
	cout << "In Virtual Function : BASE CLASS " << "\n";
}

void test::Lines(void)
{
	for (int x = 0; x < m; x++)
	{
		cout << "This is a test! " << x << "\n";
	}
	cout << "________________\n";
}

test::test()
{
	cout << "In Constructor : BASE CLASS " << "\n";
}


//---
class dertest : public test
{
public:
	dertest();
	virtual void Virtua(void);
};

void dertest::Virtua(void)
{
	cout << "In Virtual Function : DERIVED CLASS " << "\n";
}


dertest::dertest()
{
	cout << "In Constructor : DERIVED CLASS " << "\n";
}

void test::SetNumLines(int r)
{
	this->m = r;
}



void main()
{
	/*
	test a, b;
	a.SetNumLines(4);
	b.SetNumLines(2);
	a.Lines();
	b.Lines();
	*/
	dertest d;
	d.SetNumLines(3);
	d.Virtua();
	getchar();
}