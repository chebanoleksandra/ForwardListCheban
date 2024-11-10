#pragma once

class Node
{
public:
	int value;
	Node* next;
	Node() : value(0), next(nullptr) {}
	Node(int value) : value(value), next(nullptr) {}
};
class ForwardList
{
	Node* head;
	Node* tail;
	void clear();
public:
	ForwardList() : head(nullptr), tail(nullptr) {}
	ForwardList(const ForwardList& other);
	ForwardList& operator=(const ForwardList& other);
	void push_back(int value);
	void push_front(int value);
	bool push_after(Node* prev, int value);
	void print();
	Node* GetHead();
	Node* GetTail();
	const Node* find(int value);
	~ForwardList();
};
