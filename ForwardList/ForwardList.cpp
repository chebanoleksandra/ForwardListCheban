#include "ForwardList.h"
#include <iostream>
using namespace std;

void ForwardList::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}

ForwardList::~ForwardList()
{
	clear();
}

ForwardList::ForwardList(const ForwardList& other)
{
	head = new Node(other.head->value);
	tail = head;
	Node* current = other.head->next;
	while (current != nullptr)
	{
		Node* temp = new Node(current->value);
		tail->next = temp;
		tail = temp;
		current = current->next;
	}
}

ForwardList& ForwardList::operator=(const ForwardList& other)
{
	if (this == &other)
	{
		return *this;
	}
	clear();
	if (other.head == nullptr)
	{
		return *this;
	}
	head = new Node(other.head->value);
	tail = head;
	Node* current = other.head->next;
	while (current != nullptr)
	{
		Node* temp = new Node(current->value);
		tail->next = temp;
		tail = temp;
		current = current->next;
	}
	return *this;
}

void ForwardList::push_back(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
}

void ForwardList::push_front(int value)
{
	Node* new_node = new Node(value);
	new_node->next = head;
	head = new_node;
	if (!tail)
	{
		tail = new_node;
	}
}

bool ForwardList::push_after(Node* prev, int value)
{
	if (!prev)
	{
		return false;
	}
	Node* new_node = new Node(value);
	new_node->next = prev->next;
	prev->next = new_node;
	if (prev == tail)
	{
		tail = new_node;
	}
	return true;
}

void ForwardList::print()
{
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

Node* ForwardList::GetHead()
{
	return head;
}

Node* ForwardList::GetTail()
{
	return tail;
}

const Node* ForwardList::find(int value)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

