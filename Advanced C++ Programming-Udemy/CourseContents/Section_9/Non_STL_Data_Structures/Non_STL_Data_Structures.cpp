#include <iostream>
#include <string>

using namespace std;

// ====================================== STACK ======================================

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

// ====================================== QUEUE ======================================

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
  system("CLS");
  cout << "\n --- Queue \n\n";

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

// ====================================== BINARY SEARCH TREE ======================================

class Node
{
  public:
	string data;
	Node *left; // left node pointer
	Node *right; // right node pointer

	Node(string d) // a constructor that places data into the data field  
	{
	  data = d;
	  left = NULL;
	  right = NULL;
	}
};

class BST
{
  private:
	Node *root; // our first field and only field is root node.
	void Insert(string data, Node *aNode); // a private search function that will be called from a public search function
	Node *Search(string data, Node *aNode); // a search function that returns a pointer to a node.  Parameters are a data string and a pointer to a node
	void preOrder(Node *aNode); // a means of traverse a binary search tree
	void postOrder(Node *aNode);
	void inOrder(Node *aNode);
  public:
	BST();
	void Insert(string data);
	Node *Search(string data); // the data being searched
	void preOrder();
	void inOrder();
	void postOrder();
};

BST::BST()
{
  root = NULL;
}

// the private Insert method
void BST::Insert(string data, Node *aNode)
{
  if (data < aNode->data) 
  {
	// decides where to insert data.  either at the corrent node or some node further down the tree	
	if (aNode->left != NULL) 	// check to see if the data is the current node.  if it is, we have to ensure the data to the left is not equal to null.
	{
	  Insert(data, aNode->left);
	}
	else
	{
	  aNode->left = new Node(data); // create a new node
	  aNode->left->left = NULL;  // setting the left and right nodes of the newly created node to NULL
	  aNode->left->right = NULL;
	}
  }
  else if (data >= aNode->data)
  {
	if (aNode->right != NULL)
	{
	  Insert(data, aNode->right);
	}
	else
	{
	  aNode->right = new Node(data);
	  aNode->right->left = NULL;
	  aNode->right->right = NULL;
	}
  }
}

// the public Insert
void BST::Insert(string data)
{
  if (root != NULL)
  {
	Insert(data, root);
  }
  else
  {
	root = new Node(data);
	root->left = NULL;
	root->right = NULL;
  }
}

// the public Search
Node* BST::Search(string data, Node *aNode)
{
  if (aNode != NULL)
  {
	if(data == aNode->data) // if the data we are searching for was found in that node
	{
	  return aNode;
	}
	if (data < aNode->data)
	{
	  return Search(data, aNode->left);
	}
	else
	{
	  return Search(data, aNode->right);
	}
  }
  else
  {
	return NULL;
  }
}

// public preOrder
void BST::preOrder()
{
  preOrder(root);
}

void BST::preOrder(Node *aNode)
{
  if (aNode != NULL)
  {
	cout << aNode->data << " ";
	preOrder(aNode->left);
	preOrder(aNode->right);
  }
}

// public inOrder
void BST::inOrder()
{
  inOrder(root);
}

// private inOrder
void BST::inOrder(Node *aNode)
{
  if (aNode != NULL)
  {
	inOrder(aNode->left);
	cout << aNode->data << " ";
	inOrder(aNode->right);
  }
}

// public postOrder
void BST::postOrder()
{
  postOrder(root);
}

// private postOrder
void BST::postOrder(Node *aNode)
{
  if (aNode != NULL)
  {
	postOrder(aNode->left);
	postOrder(aNode->right);
	cout << aNode->data << " ";
  }
}

// the private Search
Node* BST::Search(string data)
{
  return Search(data, root);
}

void BinarySearchTree()
{
  system("CLS");
  cout << "\n --- Binary Search Tree \n\n";

  BST *btree = new BST;
  btree->Insert("apple");
  btree->Insert("mango");
  btree->Insert("kiwi");
  btree->preOrder();
  cout << endl;
  btree->inOrder();
  cout << endl;
  btree->postOrder();

  getchar();
}


// ====================================== LINKED LIST ======================================


class LLNode
{
  public:
	string data;
	LLNode* next;
	LLNode(string aData, LLNode* aNext)
	{
	  data = aData;
	  next = aNext;
	}
	string getData() // get data
	{
	  return data;
	}
	LLNode *Next() // get pointer to next node
	{
	  return next;
	}
	void setNext(LLNode *aNext) // this function is used to append a new node to the linked list
	{
	  next = aNext;
	}
};

class LList
{
  public:
	LLNode *head; // every linked list has to start off with a head node.  the first node in the linked list.
	LList()
	{
	  head = NULL; // everytime we have a new node, its head is set to point to NULL.  kind of like push_back for a vector.
	}
	void Append(string data)
	{
	  LLNode *newNode = new LLNode(data, NULL);
	  LLNode *tmp = head;
	  if (tmp != NULL)
	  {
		while (tmp->Next() != NULL)
		{
		  tmp = tmp->Next();
		}
		tmp->setNext(newNode);
	  }
	  else
	  {
		head = newNode;
	  }
	}
	void Delete(string data)
	{
	  LLNode *tmp = head;
	  if (tmp == NULL) // if this temporary node is NULL (there are no nodes in the list), just return
	  {
		// why does he not delete tmp here?? because its null, nothing to delete!
		return;
	  }
	  if (tmp->Next() == NULL) // tests to see if we are at the end of the list
	  {
		delete tmp;
		head = NULL;
	  }
	  else
	  {
		LLNode *prev = NULL;
		do // we are switching the node before the node we want to delete so it points to the node after we want to delete
		{
		  if (tmp->getData() == data) // if we found the data we are searching for in the node
		  {
			break; // break out of while - prev then is the previous node (the 2 lines below are not executed)
		  }
		  prev = tmp; 
		  tmp = tmp->Next();
		} 
		while (tmp != NULL);
		prev->setNext(tmp->Next()); // the previous node is set to point to the node ahead of the node where data matched (i.e. node we want to delete)
		delete tmp;
	  }
	}
	void Print()
	{
	  LLNode *tmp = head;
	  if (tmp == NULL) // if there are no nodes
	  {
		cout << "Empty list" << endl;
		return;
	  }
	  if (tmp->Next() == NULL) // if there is just one node
	  {
		cout << tmp->getData();
		cout << " --> ";
		cout << "NULL";
	  }
	  else
	  {
		do
		{
		  cout << tmp->getData();
		  cout << " --> ";
		  tmp = tmp->Next();
		} 
		while (tmp != NULL);
		cout << "NULL" << endl;
	  }
	}
};

void SinglyLinkedList()
{
  system("CLS");
  cout << "\n --- Singly Linked List \n\n";

  LList *no = new LList();
  no->Append("One");
  no->Append("Two");
  no->Append("Three");
  no->Append("Four");

  no->Print();
  getchar();
  
  cout << "Deleting the string Three from the Linked List" << endl;
  no->Delete("Three"); // NOTE : You cannot delete the HEAD node until all other nodes are deleted.  That is a general rule of linked lists.
  no->Print();
  getchar();
}


int main(void)
{
  Stack(); // LIFO
  Queue(); // FIFO
  BinarySearchTree();
  SinglyLinkedList(); // a series of nodes which are connected by pointers.  a node consists of 2 fields : a data field and a next field which points to the next node in the list
  return 0;
}