#pragma once
#include <iostream>

struct ListNode
{
	int requiredXP;
	int goldPrize;
	ListNode* next;
	ListNode(const int& _data, const int& _data2, ListNode* _next = nullptr) : requiredXP(_data), goldPrize(_data2), next(_next) {}
};

void pushFront(ListNode*& first, int requiredXP, int goldPrize)
{
	ListNode* newNode = new ListNode(requiredXP, goldPrize, first);
	first = newNode;
}

void pushBack(ListNode*& first, int requiredXP, int goldPrize)
{
	if (!first)
	{
		first = new ListNode(requiredXP, goldPrize, nullptr);
		return;
	}

	ListNode* curr = first;
	ListNode* newNode = new ListNode(requiredXP, goldPrize, nullptr);
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = newNode;
}

void pushAt(ListNode*& first, size_t index, int requiredXP, int goldPrize)
{
	if (index == 0)
	{
		pushFront(first, requiredXP, goldPrize);
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

	ListNode* newNode = new ListNode(requiredXP, goldPrize, nullptr);
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
		if (curr->requiredXP == data)
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
		std::cout << "Element " << counter << ": " << first->requiredXP << std::endl;
		first = first->next;
		counter++;
	}
	std::cout << "----------------------------\n";
}

void printWithArrows(ListNode* first)
{
	while (first)
	{
		std::cout << "[XP: " << first->requiredXP << ", Gold: " << first->goldPrize << "]" << " -> ";
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