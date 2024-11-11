#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}

void List::push_back(int value)
{
	
	if (head && tail)
	{
		Node* new_node = new Node(tail, value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::push_front(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value);
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void List::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
		size--;
	}
	head = nullptr;
	tail = nullptr;
}

void List::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

List::~List()
{
	clear();
}
