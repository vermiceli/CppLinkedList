#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <typename T>
class LinkedList
{
public:
	/// <summary>
	/// Initializes a new instance of the LinkedList class.
	/// Creates an empty linked list.
	/// </summary>
	LinkedList(void)
	{
		std::cout << "Constructor" << std::endl;
		head = NULL;
		tail = NULL;
	}

	/// <summary>
	/// Finalizes a LinkedList object.  Removes all the dynamically allocated members
	/// that it is responsible for, i.e. it's elements
	/// </summary>
	~LinkedList(void)
	{
		Node<T>* ptr = head;
		while(ptr != NULL)
		{
			Node<T>* ptr2 = ptr;
			ptr = ptr->next;
			delete ptr2;
		}
	}

	/// <summary>
	/// Adds an element to the list
	/// <param name="data">An element to add to the list</param>
	/// </summary>
	void add(const T data)
	{
		// We have an empty list
		if(head == NULL)
		{
			head = new Node<T>(data);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(data);
			Node<T>* ptr = tail;
			tail = tail->next;
			tail->previous = ptr;
		}
	}

	/// <summary>
	/// Removes an element from a list
	/// <param name="data">The element to remove from the list</param>
	/// </summary>
	/// <returns>Whether or not the element was removed</returns>
	bool remove(const T data)
	{
		Node<T>* ptr = head;
		
		// The list is empty
		if(head == NULL)
		{	
			return false;
		}
		else if(head->data == data)
		{
			// Removing the head element
			if(tail == head)
			{
				tail = head->next;
			}

			head = head->next;
			ptr->next = NULL;
			delete ptr;
			return true;
		}

		// Find the element in the list
		while(ptr != NULL)
		{
			if(ptr->data == data)
			{
				if(ptr->previous != NULL) 
				{
					ptr->previous->next = ptr->next;
				}

				if(ptr->next != NULL)
				{
					ptr->next->previous = ptr->previous;
				}
				else
				{
					// Removing the tail element
					tail = ptr->previous;
				}

				ptr->next = NULL;
				ptr->previous = NULL;
				delete ptr;
				return true;
			}
			ptr = ptr->next;
		}

		return false;
	}

	/// <summary>
	/// The beginning of the linked list.
	/// </summary>
	Node<T>* head;

	/// <summary>
	/// The end of the linked list.
	/// </summary>
	Node<T>* tail;
};

#endif