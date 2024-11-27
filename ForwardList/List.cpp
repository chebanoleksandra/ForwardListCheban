/*#include "List.h"
#include <iostream>
using namespace std;

List::List()
	:head(nullptr), tail(nullptr), size(0)
{}

List::List(const List& other)
	:head(nullptr), tail(nullptr), size(0)
{
	if (!other.size == 0)
	{
		return;
	}

	Node* current = other.head;
	Node* x;
	Node* y = new Node(current->value);
	head = y;
	tail = y;
	current = current->next;
	while (current)
	{
		x = y;
		y = new Node(x, current->value);
		x->next = y;
		tail = y;
		current = current->next;
		size++;
	}
}

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
		//my version
		//Node* new_node = new Node(value);
		new_node->next = head;//

		Node* new_node = new Node(value, head);
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
	//my version
	//Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
		size--;
	}
	head = nullptr;
	tail = nullptr;//

	//classwork
	if (head && tail)
	{
		Node* current = tail;
		Node* temp = current->prev;
		while (current)
		{
			delete current;
			current = temp;
			temp = temp ? temp->prev : nullptr;
		}
		tail = nullptr;
		head = nullptr;
		size = 0;
	}
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

List& List::operator=(const List& other) {
	if (this == &other)
	{
		return *this;
	}
	if (other.head == nullptr)
	{
		return *this;
	}
	clear();
	Node* current = other.head;
	while (current) {
		push_back(current->value);
		current = current->next;
	}
	return *this;
}

void List::reverse() {
	if (head == nullptr || tail == nullptr)
	{
		return;
	}
	Node* current = head;
	Node* temp = nullptr;
	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	temp = head;
	head = tail;
	tail = temp;
}

void List::pop_back() {
	if (tail == nullptr)
	{
		return;
	}
	Node* temp = tail;
	tail = tail->prev;
	if (tail)
	{
		tail->next = nullptr;
	}
	else
	{
		head = nullptr;
	}

	delete temp;
	size--;
}

void List::pop_front() {
	if (head == nullptr)
	{
		return;
	}
	Node* temp = head;
	head = head->next;
	if (head)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}
	delete temp;
	size--;
}


List::~List()
{
	clear();
}*/