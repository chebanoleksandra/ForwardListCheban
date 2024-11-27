#pragma once
template <typename T>
class List
{
	class Node {
	public:
		T value;
		Node* prev;
		Node* next;
		Node() :value(0), prev(nullptr), next(nullptr)
		{}
		Node(T value) :value(value), prev(nullptr), next(nullptr)
		{}
		Node(Node* prev, T value) :value(value), prev(prev), next(nullptr)
		{}
		Node(T value, Node* next) :value(value), prev(nullptr), next(next)
		{}
	};
private:
	Node* head;
	Node* tail;
	size_t size;
public:
	List();
	List(const List<T>& other);
	void push_back(T value);
	void push_front(T value);
	void clear();
	void show() const;
	List& operator=(const List<T>& other);
	void reverse();
	void pop_back();
	void pop_front();
	List<T>* operator+(const List<T>& other);
	List<T>* operator*(const List<T>& other);
	~List();
};

#include "List.h"
#include <iostream>
using namespace std;

template <typename T>
List<T>::List()
	:head(nullptr), tail(nullptr), size(0)
{}

template <typename T>
List<T>::List(const List& other)
	: head(nullptr), tail(nullptr), size(0)
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

template <typename T>
void List<T>::push_back(T value)
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

template <typename T>
void List<T>::push_front(T value)
{
	if (head && tail)
	{
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

template <typename T>
void List<T>::clear()
{
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

template <typename T>
void List<T>::show() const
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
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

template <typename T>
void List<T>::reverse() {
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

template <typename T>
void List<T>::pop_back() {
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

template <typename T>
void List<T>::pop_front() {
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

template<typename T>
inline List<T>* List<T>::operator+(const List<T>& other)
{
	List<T>* result = new List<T>();
	Node* current = this->head;
	while (current) {
		result->push_back(current->value);
		current = current->next;
	}
	current = other.head;
	while (current) {
		result->push_back(current->value);
		current = current->next;
	}
	return result;
}

template<typename T>
inline List<T>* List<T>::operator*(const List<T>& other)
{
	List<T>* result = new List<T>();
	Node* current = this->head;
	while (current) {
		Node* otherCurrent = other.head;
		while (otherCurrent) {
			if (current->value == otherCurrent->value) {
				result->push_back(current->value);
				break;
			}
			otherCurrent = otherCurrent->next;
		}
		current = current->next;
	}
	return result;
}

template <typename T>
List<T>::~List()
{
	clear();
}
