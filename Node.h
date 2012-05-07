#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
struct Node
{
public:
	Node(void) : next(NULL), previous(NULL)
	{
	}

	Node(T data_arg) : next(NULL), previous(NULL), data(data_arg)
	{
	}

	~Node(void)
	{
	}

	T data;
	Node<T>* next;
	Node<T>* previous;
};

#endif