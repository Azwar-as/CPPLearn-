#include <iostream>

using namespace std;

// JAVIER GAVRA ABHINAYA
// A11.2024.15771

class LinkedList
{
	struct Node
	{
		int value;
		Node *next;
	};

private:
	Node *head = NULL;

public:
	int length = 0;

	Node *getHead()
	{
		return head;
	}

	bool isEmpty()
	{
		return (head == NULL);
	}

	void print()
	{
		Node *currentNode = head;
		cout << "Linked List: ";
		while (currentNode != NULL)
		{
			cout << currentNode->value;
			if (currentNode->next != NULL)
				cout << " -> ";

			currentNode = currentNode->next;
		}
		cout << endl;
	}

	void insertHead(int x)
	{
		Node *newNode = new Node{x, head};
		head = newNode;
		length++;
	}

	void insertTail(int x)
	{
		Node *newNode = new Node{x, NULL};

		if (isEmpty())
		{
			head = newNode;
		}
		else
		{
			Node *currentNode = head;
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
		length++;
	}

	void insertByPosition(int x, int position)
	{
		if (position > (length + 1))
		{
			cout << "Index out of bound" << endl;
			return;
		}

		if (position == 1)
		{
			insertHead(x);
		}
		else if (position == (length + 1))
		{
			insertTail(x);
		}
		else
		{
			Node *newNode = new Node{x, NULL};
			Node *currentNode = head;

			for (int i = 1; i < position - 1; i++)
			{
				currentNode = currentNode->next;
			}

			newNode->next = currentNode->next;
			currentNode->next = newNode;
			length++;
		}
	}

	void insertByIndex(int x, int index)
	{
		if (index > length)
		{
			cout << "Index out of bound" << endl;
			return;
		}

		if (index == 0)
		{
			insertHead(x);
		}
		else if (index == length)
		{
			insertTail(x);
		}
		else
		{
			Node *newNode = new Node{x, NULL};
			Node *currentNode = head;
			int i = 0;

			while (currentNode->next != NULL)
			{
				if (i == (index - 1))
					break;

				currentNode = currentNode->next;
				i++;
			}

			newNode->next = currentNode->next;
			currentNode->next = newNode;
			length++;
		}
	}

	void deleteHead()
	{
		if (isEmpty())
		{
			cout << "Linked List is empty" << endl;
			return;
		}

		Node *deletedNode = head;
		head = head->next;
		delete deletedNode;
		length--;
	}

	void deleteTail()
	{
		if (isEmpty())
		{
			cout << "Linked List is empty" << endl;
			return;
		}

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node *currentNode = head;
			while (currentNode->next->next != NULL)
			{
				currentNode = currentNode->next;
			}
			delete currentNode->next;
			currentNode->next = NULL;
		}
		length--;
	}

	void deleteByIndex(int index)
	{
		if (index >= length)
		{
			cout << "Index out of bound" << endl;
			return;
		}

		if (index == 0)
		{
			deleteHead();
		}
		else if (index == (length - 1))
		{
			deleteTail();
		}
		else
		{
			Node *currentNode = head;
			int i = 0;

			while (currentNode->next != NULL)
			{
				if ((i + 1) == index)
					break;

				currentNode = currentNode->next;
				i++;
			}

			Node *deleteNode = currentNode->next;
			currentNode->next = currentNode->next->next;
			delete deleteNode;
			length--;
		}
	}

	void deleteByValue(int query)
	{
		if (isEmpty())
		{
			cout << "Linked List is empty" << endl;
			return;
		}

		Node *currentNode = head;
		Node *previousNode = NULL;

		while (currentNode != NULL)
		{
			if (currentNode->value == query)
			{
				if (currentNode == head)
				{
					deleteHead();
				}
				else
				{
					previousNode->next = currentNode->next;
					delete currentNode;
					length--;
				}
				return; // Exit after deleting the first occurrence
			}
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		cout << "Value not found in the list" << endl;
	}

	void clear()
	{
		while (head->next != NULL)
		{
			Node *temp = head;
			head = temp->next;
			delete temp;
		}
		head = NULL;
		length = 0;
	}
};

int main()
{
	LinkedList list;
	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(20);
	list.insertHead(1);
	list.print();
	cout << "Head : " << list.getHead()->value << endl;

	list.deleteHead();
	list.print();
	cout << "Head : " << list.getHead()->value << endl;

	list.deleteTail();
	list.print();

	list.deleteTail();
	list.deleteHead();
	list.print();

	list.deleteHead();

	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(20);
	list.insertHead(1);
	list.print();
	cout << "Length : " << list.length << endl;

	/*
	list.insertByIndex(100, 2);
	list.print();
	cout << "Length : " << list.length << endl;
	*/

	list.insertByPosition(100, 5);
	list.print();
	cout << "Length : " << list.length << endl;

	list.deleteByIndex(1);
	list.print();
	cout << "Length : " << list.length << endl;

	list.clear();
	list.print();

	list.insertHead(10);
	list.insertHead(5);
	list.insertTail(20);
	list.insertHead(1);
	list.print();

	list.deleteByValue(5);
	list.print();

	list.deleteByValue(100); // Value not found
	list.print();

	return 0;
}
