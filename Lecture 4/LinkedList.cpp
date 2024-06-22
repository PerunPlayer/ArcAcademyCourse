#include <iostream>

struct ListNode
{
	int data;
	ListNode* next;
	ListNode(const int& _data, ListNode* _next = nullptr) : data(_data), next(_next) {}
};

void pushFront(ListNode*& first, int data)
{
	ListNode* newNode = new ListNode(data, first);
	first = newNode;
}

void pushBack(ListNode*& first, int data)
{
	if (!first)
	{
		first = new ListNode(data, nullptr);
		return;
	}

	ListNode* curr = first;
	ListNode* newNode = new ListNode(data, nullptr);
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = newNode;
}

void pushAt(ListNode*& first, size_t index, int data)
{
	if (index == 0)
	{
		pushFront(first, data);
		return;
	}

	if (!first || !first->next)	// here index is always >= 1, so the list must have at least two elements
	{
		return;
	}

	ListNode* curr = first;
	for (size_t i = 0; i < index - 1; i++)
	{
		if (!curr)		// if at some point we have reached after the last element, then there is no such index
		{
			std::cout << "Invalid index" << std::endl;
			return;
		}
		curr = curr->next;
	}

	ListNode* newNode = new ListNode(data, nullptr);
	ListNode* next = curr->next;
	curr->next = newNode;
	newNode->next = next;
}

void popFront(ListNode*& first)
{
	if (!first)
	{
		return;
	}

	if (!first->next)	// if there is exactly one element
	{
		delete first;
		first = nullptr;
		return;
	}

	ListNode* newFirst = first->next;
	delete first;
	first = newFirst;
}

void popBack(ListNode*& first)
{
	if (!first)
	{
		return;
	}

	if (!first->next)	// if there is exactly one element
	{
		delete first;
		first = nullptr;
		return;
	}

	ListNode* curr = first;
	while (curr->next->next)
	{
		curr = curr->next;
	}
	delete curr->next;
	curr->next = nullptr;
}

void popAt(ListNode*& first, size_t index)
{
	if (index == 0)
	{
		popFront(first);
		return;
	}

	if (!first || !first->next)	// here index is always >= 1, so the list must have at least two elements
	{
		return;
	}

	ListNode* curr = first;
	for (size_t i = 0; i < index - 1; i++)
	{
		if (!curr->next)	// if at some point we have reached the last element (meaning we try to delete the element after), then there is no such index
		{
			std::cout << "Invalid index" << std::endl;
			return;
		}
		curr = curr->next;
	}

	ListNode* next = curr->next->next;
	delete curr->next;
	curr->next = next;
}

ListNode*& find(ListNode*& first, int data)
{
	ListNode* curr = first;
	while (curr)
	{
		if (curr->data == data)
		{
			return curr;
		}
		curr = curr->next;
	}
	std::cout << "Element not found. First element returned.\n";
	return first;
}

void reverse(ListNode*& first)
{
	ListNode* current = first;
	ListNode* prev = nullptr;
	ListNode* next = nullptr;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	first = prev;
}

bool checkForLoop(ListNode*& first)
{
	ListNode* fastIterator = first;
	ListNode* slowIterator = first;

	do
	{
		fastIterator = fastIterator->next->next;
		slowIterator = slowIterator->next;
		if (fastIterator == slowIterator)
		{
			return true;
		}
	} while (fastIterator && slowIterator);
}

void print(ListNode* first)
{
	unsigned int counter = 0;
	while (first)
	{
		std::cout << "Element " << counter << ": " << first->data << std::endl;
		first = first->next;
		counter++;
	}
	std::cout << "----------------------------\n";
}

void printWithArrows(ListNode* first)
{
	while (first)
	{
		std::cout << first->data << " -> ";
		first = first->next;
	}
	std::cout << "nullptr" << std::endl;
}

void destroy(ListNode*& first)
{
	while (first)
	{
		ListNode* next = first->next;
		delete first;
		first = next;
	}
}

int main()
{
	ListNode* five = new ListNode(5, nullptr);
	ListNode* four = new ListNode(4, five);
	ListNode* three = new ListNode(3, four);
	ListNode* two = new ListNode(2, three);
	ListNode* head = new ListNode(1, two);
	printWithArrows(head);

	pushFront(head, 0);
	printWithArrows(head);

	pushBack(head, 100);
	printWithArrows(head);

	pushAt(head, 5, 99);
	printWithArrows(head);

	popFront(head);
	printWithArrows(head);

	popBack(head);
	printWithArrows(head);

	pushAt(head, 3, 33);
	printWithArrows(head);

	popAt(head, 3);
	printWithArrows(head);

	std::cout << find(head, 3)->data << std::endl;
	std::cout << find(head, 56)->data << std::endl;
	reverse(head);
	printWithArrows(head);

	destroy(head);
	printWithArrows(head);

	return 0;
}