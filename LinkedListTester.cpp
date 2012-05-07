#include <iostream>
#include <limits>
#include "LinkedList.h"

int main()
{
	LinkedList<int> list;
	list.add(3);
	list.add(4);
	list.add(5);
	list.remove(4);

	Node<int>* ptr = list.head;
	while(ptr != NULL)
	{
		std::cout << ptr->data << std::endl;
		ptr = ptr->next;
	}

	std::cout << "Press ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}
