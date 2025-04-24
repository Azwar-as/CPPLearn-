#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node *next;
};

Node *head;

void insertHead(int x);
void insertTail(int x);
void deleteHead();
void deleteTail();
void printLinkedList();

int main()
{
	insertHead(10);
	insertHead(5);
	insertTail(20);
	insertTail(30);

	printLinkedList();

	deleteHead();
	printLinkedList();

	deleteTail();
	printLinkedList();

	return 0;
}

void insertHead(int x)
{
	Node *newNode = new Node();
	newNode->value = x;
	newNode->next = NULL;

	if (head != NULL)
		newNode->next = head;

	head = newNode;
}

void insertTail(int x)
{
	Node *newNode = new Node();
	newNode->value = x;
	newNode->next = NULL;

	if (head == NULL)
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
}

void deleteHead()
{
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
		return;
	}

	if (head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		Node *currentHead = head;
		head = currentHead->next;
		delete currentHead;
	}
}

void deleteTail()
{
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
		return;
	}

	if (head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		Node *deletedNode;
		Node *currentNode = head;
		while (currentNode->next->next != NULL)
		{
			currentNode = currentNode->next;
		}

		deletedNode = currentNode->next;
		currentNode->next = NULL;
		delete deletedNode;
	}
}

void printLinkedList()
{
	Node *currentNode = head;
	cout << "Isi Linked List: ";
	while (currentNode != NULL)
	{
		cout << currentNode->value;
		if (currentNode->next != NULL)
			cout << " -> ";

		currentNode = currentNode->next;
	}
	cout << endl;
}