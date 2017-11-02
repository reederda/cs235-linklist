#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedListInterface.h"
using namespace std;

template <typename T>

class LinkedList :
public LinkedListInterface<T>
{
public:

	class Node
	{
	public:
		T value;
		Node *next;

		Node(T valor)
		{
			value = valor;
			next = NULL;
		}
	};


	int listSize;
	Node *head, *tail;

	LinkedList(void)
	{
		listSize = 0;
		head = nullptr;
		tail = nullptr;

	};
	virtual ~LinkedList(void) { clear();};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value)
	{
		if (listSize == 0)
		{
			Node *n = new Node(value);
			n->next = NULL;
			head = n;
			tail = n;
			listSize++;
			return;
		}
		if (!(checkDupe(value)))
		{
			Node *n = new Node(value);
			n->next = head;
			head = n;
			listSize++;
			return;
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value)
	{
		if (listSize == 0)
		{
			Node *n = new Node(value);
			n->next = NULL;
			head = n;
			tail = n;
			listSize++;
			return;
		}
		if (!(checkDupe(value)))
		{


			Node *n = new Node(value);
			tail->next = n;
			tail = n;
			n->next = NULL;
			listSize++;
			return;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode)
	{
		if (listSize == 0)
		{
			return;
		}
		Node *curr;
		curr = head;
		if (!(checkDupe(value)))
		{
			while (curr->next != NULL)
			{
				if (curr->value == insertionNode)
				{
					Node *n = new Node(value);
					n->next = curr->next;
					curr->next = n;
					listSize++;
					return;
				}
				curr = curr->next;
			}

			if (curr == tail && curr->value == insertionNode)
			{
				Node *n = new Node(value);
				tail->next = n;
				n->next = NULL;
				tail = n;
				listSize++;
				return;
			}
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value)
	{
		Node *curr;
		Node *prev;
		curr = head;
		prev = NULL;
		if (listSize == 0)
		{
			return;
		}

		if (checkDupe(value))
		{
			while (curr->next != NULL)
			{
				if (curr->value == value)
				{
					if (head == curr)
					{
						head = head->next;
						//curr->next = NULL;
						delete curr;
						listSize--;
						return;
					}
					else
					{
						prev->next = curr->next;
						curr->next = NULL;
						delete curr;
						listSize--;
						return;
					}
				}

				prev = curr;
				curr = curr->next;
			}

			if (listSize == 1)
			{
				prev = curr;
			}
			tail = prev;
			tail->next = NULL;
			delete curr;
			listSize--;

			if (listSize == 0)
			{
				head = NULL;
				tail = NULL;
			}
			return;
		}
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear()
	{
		Node *curr;
		Node *prev;
		curr = head;
		if (listSize == 0)
		{
			return;
		}
		while (curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
			delete prev;
		}

		delete curr;
		head = NULL;
		tail = NULL;
		listSize = 0;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index)
	{
		Node *curr;
		curr = head;

		if (index >= (listSize) || index < 0)
		{
			throw out_of_range("YOU'RE STUPID"); //C++ throw error function
		}
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
			//i++;
		}
		return curr->value;
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size()
	{
		return listSize;
	}

	/*
	toString

	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString()
	{
		stringstream ss;
		Node *curr = head;

		if (listSize == 0)
		{
			return ss.str();
		}

		ss << curr->value;
		curr = curr->next;

		if (listSize == 1)
		{
			return ss.str();
		}

		while ( curr->next != NULL)
		{
			ss << " " << curr->value;
			curr = curr->next;
		}
		ss << " " << curr->value;

		return ss.str();
	}

	bool checkDupe(T value)
	{
		Node *curr = head;
		while (curr->value != value)
		{
			if (curr->next == NULL)
			{
				return false;
			}
			curr = curr->next;
		}
		return true;
	}
};
