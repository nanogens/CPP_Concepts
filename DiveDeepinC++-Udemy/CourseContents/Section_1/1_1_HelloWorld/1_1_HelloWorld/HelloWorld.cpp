#include <iostream>

using namespace std;

int main(void)
{
    // << is called an insertion operator
	// std is a namespace
	// :: is called a scope operator
	// by putting "using namespace std", you don't need to put std::
	// for programming, avoid "using namespace" because it includes the entire namespace.  Use std:: instead!
	cout << "Hello World \n";
	getchar();
	std::cout << "Hello World !! \n" << std::endl;
	getchar();
	return 0;
}