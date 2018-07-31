#include <iostream>
#include <string>

using namespace std;


class Stack1
{
  private:
	string datastore[100];
	int top; // where the last data item is placed.  the last data element put onto the stack
  public:
	Stack1() // constructor
	{
	  top = -1;
	}
	void Push(string value)
	{
	  top++;
	  datastore[top] = value;
	}
	string Pop()
	{
	  string retVal = datastore[top];
	  top--;
	  return retVal;
	}
	string Peek() // returns value stored at the top of the stack
	{
	  return datastore[top];
	}

	int Count()
	{
	  return (top + 1);
	}
	void Clear()
	{
	  for (int i = 0; i < (top - 1); i++)
	  {
		datastore[i] = "";
	  }
	  top = -1;
	}
	bool IsEmpty() 
	{
	  if (top == -1)
	  {
		return true;
	  }
	  return false;
	}
};

void Stack()
{
  system("CLS");
  cout << "\n --- Non-STL Data Structures --- \n" << endl;

  cout << "\n --- Stack \n\n";

  Stack1 stack1; // stack is a LIFO (like a stack of trays)
  stack1.Push("Manish");
  stack1.Push("Avinash");
  stack1.Push("Vivaan");

  cout << "Number of elements in the stack : " << stack1.Count() << endl;

  string name = "";
  if (!stack1.IsEmpty())
  {
	name = stack1.Pop(); // since its LIFO, pops Vivaan off the stack since it was the last in.
	cout << name << " popped off the stack (LIFO)" << endl;
  }

  cout << "Number of items in the stack : " << stack1.Count() << endl;

  stack1.Clear();
  cout << "Number of items in the stack after Clear() : " << stack1.Count() << endl;

  getchar();
}

class Queue1
{
  private:
	string datastore[100];
	int back;
	const static int front = 0; // const because the front will never change.  the front is always the 0th element.  we make it a const so we can never change it by accident or on purpose
	void Shift()
	{
	  for (int i = front; i <= back; i++)
	  {
		datastore[i] = datastore[i + 1];
	  }
	  back--; // since we popped one element off the front of the stack
	}
  public:
	Queue1()
	{
	  back = -1;
	}
	void In(string value)
	{
	  back++;
	  datastore[back] = value;
	}
	string Out()
	{
	  string retVal = datastore[front];
	  Shift();
	  return retVal;
	}
	void Show(string str)
	{
	  cout << str << endl;
	  for (int i = front; i <= back; i++)
	  {
		cout << datastore[i] << endl;
	  }
	  cout << endl << endl;
	}
	int Count()
	{
	  cout << "Number of elements Count() in the queue : " << endl;
	  int cnt = 0;
	  for (int i = 0; i <= back; i++)
	  {
		cnt++;
	  }
	  return cnt;
	}
	string Front()
	{
	  return datastore[front];
	}
	bool IsEmpty()
	{
	  if (back == -1)
	  {
		return true;
	  }
	  return false;
	}
	void Clear()
	{
	  cout << "Clearing the queue.." << endl;
	  for (int i = front; i <= back; i++)
	  {
		datastore[i] = "";
	  }
	  back = -1;
	}
};

void Queue()
{
  Queue1 queue1;
  queue1.In("A");
  queue1.In("B");
  queue1.In("C");
  queue1.Show("Elements in the queue : ");
  getchar();

  //---------------------------------------------------------------------------------------

  queue1.Out();
  queue1.Show("Elements in the queue after one element is removed (FIFO) : ");
  getchar();

  //---------------------------------------------------------------------------------------

  queue1.In("D");
  queue1.Show("Elements in the queue after one element is added (FIFO) : ");
  getchar();

  //---------------------------------------------------------------------------------------

  cout << queue1.Count() << endl << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  queue1.Front();
  queue1.Show("The Front() of the queue : ");
  getchar();

  //---------------------------------------------------------------------------------------

  queue1.Clear();
  queue1.Show("The queue after Clear() : ");
  getchar();

  //---------------------------------------------------------------------------------------

  cout << "Is the queue empty : " << queue1.IsEmpty() << endl;
  getchar();

  //---------------------------------------------------------------------------------------

  cout << queue1.Count() << endl << endl;
  getchar();
}

class Node
{
  public:
	string data;
	Node *left; // left node pointer
	Node *right; // right node pointer
	Node(string d) // a constructor that places data into the data field  /0\
	{
	  data = d;
	  left = NULL;
	  right = NULL;
	}
};

void BinaryTree()
{

}

int main(void)
{
  //Stack(); // LIFO
  //Queue(); // FIFO
  BinaryTree(); 
  return 0;
}