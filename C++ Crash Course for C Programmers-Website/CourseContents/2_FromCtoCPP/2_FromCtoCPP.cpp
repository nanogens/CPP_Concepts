#include <iostream>

// Example Usage Define Statements
//#define _IO_Ch2_1_INPUTOUTPUT 1
//#define _IO_Ch2_2_NEWDELETE 1
//#define _IO_Ch2_3_REFERENCES 1
//#define _IO_Ch2_4_DEFAULTPARAMETERS 1
//#define _IO_Ch2_5_NAMESPACES 1
//#define _IO_Ch2_6_OVERLOADING 1
//#define _IO_Ch2_7_CONSTINLINE 1
//#define _IO_Ch2_8_MIXINGCANDCPP 1

// Exercise Define Statements 
//#define A_pointer_to_a_character 1
//#define A_constant_pointer_to_a_character 1
//#define A_pointer_to_a_constant_char 1
//#define A_reference_to_a_character 1
//#define A_constant_pointer_to_a_constant_character 1
#define A_2D_Array 1

// -------------------------------------------------------------------------------------------

// Define Statements for Explainations
#ifdef _IO_Ch2_7_CONSTINLINE
#define SQUARE(x) x*x  
#endif
#ifdef _IO_Ch2_8_MIXINGCANDCPP
//#define __cplusplus 1
#endif

// -------------------------------------------------------------------------------------------

// Namespaces
#ifdef _IO_Ch2_5_NAMESPACES
namespace first { int var = 5; }
namespace second { int var = 3; }
#endif

// -------------------------------------------------------------------------------------------

// Macros
#ifdef _IO_Ch2_7_CONSTINLINE
int inline square(int x)
{
  return x*x;
}
#endif

// -------------------------------------------------------------------------------------------

// Extern Linkage Declarations
// Notes :
// To link other files (e.g. if we plan to use C++ along with C, we might extern link an external CPP .h library)
#ifdef _IO_Ch2_8_MIXINGCANDCPP
#ifdef __cplusplus
extern "C"
{
#endif
#include "some-c-code.h" // uncomment this only when we have an external file
#ifdef __cplusplus
}
#endif
#endif

// -------------------------------------------------------------------------------------------

// Function Prototypes
#ifdef _IO_Ch2_4_DEFAULTPARAMETERS
float foo(float a, float, float); // for IO_Ch2_4_DEFAULTPARAMETERS
float foo(float a = 0, float b = 1, float c = 2)
{
  return (a + b + c);
}
#endif
#ifdef _IO_Ch2_6_OVERLOADING
float add(float, float);
int add(int, int);

float add(float a, float b)
{
  return a + b;
}

int add(int a, int b)
{
  return a + b;
}
#endif

// -------------------------------------------------------------------------------------------

void Lecture_2(void)
{
#ifdef _IO_Ch2_1_INPUTOUTPUT
  int i;
  std::cout << "Please enter an integer value: ";
  std::cin >> i;
  std::cout << "The value you entered is " << i << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_2_NEWDELETE
  // Notes :
  // The (new and delete) keywords are used to allocate and free memory.  
  // They are "object-aware" so you'd better use them instead of (malloc and free).
  // In any case, never cross the streams (new/free or malloc/delete).
  // delete does two things: it calls the destructor and it deallocates the memory.
  int *a = new int;
  *a = 5;
  std::cout << "\n" << *a;
  getchar();
  getchar();
  delete a;

  int *b = new int[5];
  delete[] b;
#endif

#ifdef _IO_Ch2_3_REFERENCES
  // Notes :
  // A reference allows you to declare an alias to another variable.
  // As long as the aliased variable lives, you can use indifferently the variable or the alias.
  int x;
  int &foo = x;
  foo = 42;
  std::cout << x << "," << foo << " " << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_4_DEFAULTPARAMETERS
  // Notes :
  // You can specify default values for function parameters.
  // When the function is called with fewer parameters, default value are used.
  std::cout << foo(1) << std::endl
	<< foo(1, 2) << std::endl
	<< foo(1, 2, 3) << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_5_NAMESPACES
  // Notes :
  // Namespace allows to group classes, functions and variables under a common scope name that can be referenced elsewhere.
  std::cout << first::var << std::endl;
  std::cout << second::var << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_6_OVERLOADING
  // Notes 
  // It is not legal to overload a function based on the return type (but you can do it anyway). <- WTF does that mean?
  // Strangely here, you have to explicitly cast the int to tell the function what datatype you are sending in.
  // I guess 4 + 2 is the same as 4.0 + 2.0 and either the int or the float add functions which are overloaded can be used.
  int i = add((int)4, (int)2);
  std::cout << i << std::endl;
  getchar();
  getchar();

  // You have to explicitly cast the float to tell the function what datatype you are sending in
  float f = add((float)4.4, (float)2.2);
  std::cout << f << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_7_CONSTINLINE
  // Notes
  // Usage of the define statement like shown below SQUARE(3) is OK.  But SQUARE(3+3) is not - gives a strange answer of 15!
  int result = SQUARE(3);
  std::cout << result << std::endl;
  getchar();
  getchar();

  // Defines the macros are bad if not used properly as illustrated below
  // Do NOT do this.  This is to showcase bad usage of a define function
  result = SQUARE(3 + 3);
  std::cout << result << std::endl;
  getchar();
  getchar();

  // For constants, the const notation is preferred
  const int two = 2;

  // For macros, prefer the inline notation
  // See Macro definition way up top for square()
  result = square(3);
  std::cout << result << std::endl;
  getchar();
  getchar();
#endif

#ifdef _IO_Ch2_8_MIXINGCANDCPP
  // See above in Extern Linkage Declarations
#endif
}

void Exercise_2(void)
{
  // Notes :
  // Question : How would you declare.
#ifdef A_pointer_to_a_character
  char a; // a character
  char *b_ptr; // = &a; <--- either write it on 1 line or 2 lines as shown in the line below
  b_ptr = &a; // set the pointer b_ptr to the address of a.  they are now both linked

  *b_ptr = 'x'; // assign the contents pointed to by b_ptr (which is the contents of a) the value of 'x' 
				//a = 'x'; 

				// Now print the value of a
  std::cout << a << std::endl;
  getchar();
  getchar();
#endif

#ifdef A_constant_pointer_to_a_character
  const char b = 'y'; // both have to be const and a value (in this case 'y') has to be set to b
  const char *a_ptr; // a constant pointer to a character
  a_ptr = &b;
  // b = 'x'; // Not allowed to change the value of the const once assigned (as done above) it seems
  std::cout << b << std::endl;
  getchar();
  getchar();
#endif

#ifdef A_pointer_to_a_constant_character
  // Same as (A_constant_pointer_to_a_character) above since both have to be const
  const char a = 'x'; // both have to be const
  const char *a_ptr = &a; // a pointer to a constant character
  std::cout << *a_ptr << std::endl;  // Error : A value of type "const char *" cannot be used to initialize an entity of type "char *"
  getchar();
  getchar();
#endif

#ifdef A_constant_pointer_to_a_constant_character
  // Same as above (A_constant_pointer_to_a_character) and (A_pointer_to_a_constant_character) above since both have to be const
  // const char a = 'x'; // a const character
  // const char *a_ptr = &a; // a pointer to a constant character
#endif

#ifdef A_reference_to_a_character
  char a = 'm';
  char *a_ptr; // a reference to a character
  a_ptr = &a;
  std::cout << *a_ptr << std::endl;
  getchar();
  getchar();
#endif

#ifdef A_reference_to_a_constant_character
  char a = 'm';
  char *a_ptr; // a reference to a character
  a_ptr = &a;
  std::cout << *a_ptr << std::endl;
  getchar();
  getchar();
#endif

#ifdef A_2D_Array
  // int **arr declares a pointer (on the stack?) which points to pointer(s) (on the heap?).
  // Each of those pointer(s) point to an array of integers on the heap.
  // Note : heap is for dynamic allocation, stack is for static allocation.

  const size_t n = 2;
  // ** = pointers to pointers = 2D array


  int **arr = new int *[n];   // means that you declared a pointer on the stack and initialized it so it points to an array of n pointers on the heap
  // As of here, the n pointers point nowhere.  They are not initialized and thus contain some garbage value.
  // We should assign them something sensible in a loop before usage - which is what happens in the next 2 steps below.

  // create the array of pointers on the heap (MT?)
  // Since each element of the array is also a pointer, you need to initialize those pointers as well
  // This initializes an array that is n x n
  for (size_t i = 0; i < n; ++i) // if you want an array of 100 x 200, substitute the n here for 100 and put 
  {
	arr[i] = new int[n]; // 200 here for this n.  You can then access the bottom-right corner with p[99][199]
  } 

  // reconfigure the plot? from 1D to 2D array (MT?)
  for (size_t i = 0; i < n; i++)
  {
	for (size_t j = 0; j < n; j++)
	{
	  arr[i][j] = i * (i + j);
	  std::cout << "arr[" << i << "," << j << "] = "
		        << arr[i][j] << std::endl;
	}
  }

  // delete the main node of each of the 2D array (MT?)
  // Yes, when the time to delete the pointer comes, you have to reverse the process.
  for (size_t i = 0; i < n; ++i)
  {
	delete[] arr[i];
  }
  delete[] arr;
  getchar();
  getchar();
#endif


}

// -------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
  Lecture_2();
  Exercise_2();



  return 0;
}
