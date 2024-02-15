#include <iostream>
#include "../include/LinkedList.h"

using linkedlist::linkedList;
using linkedlist::Node;


linkedList::linkedList()
{
	std::shared_ptr<Node> head = nullptr;
}

void linkedList::insertAtbegin(int x)
{
	auto n = std::make_shared<Node>(x);
	if (Head == nullptr)
	{
		Head = n;
		return;
	}
	n->next = Head;
	Head = n;
}
void linkedList::insertAtlast(int x)
{
	auto n = std::make_shared<Node>(x);
	if (Head == nullptr)
	{
		Head = n;
		return;
	}
	auto tmp = Head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}

int linkedList::getLength()
{
	auto count = 1;
	auto tmp = Head;
	while (tmp->next != nullptr)
	{
		count++;
		tmp = tmp->next;
	}
	return count;
}

void linkedList::deleteIndex(int index)
{
	int count = getLength();
	if (index == 1)
	{
		Head = Head->next;
		return;
	}
	if (index == count)
	{
		auto tmp = Head;
		auto tmp1 = Head->next;
		while (tmp1->next != nullptr)
		{
			tmp = tmp->next;
			tmp1 = tmp1->next;
		}
		tmp->next = nullptr;
		return;
	}
	if (index > 1 && index < count)
	{
		auto tmp = Head;
		auto tmp1 = Head->next;
		auto count1 = 2;
		while (index != count1)
		{
			tmp = tmp->next;
			tmp1 = tmp1->next;
			count1++;
		}
		tmp->next = tmp1->next;
		tmp1->next = nullptr;
		return;
	}
	if (index <= 0 || index > count)
	{
		std::cout << "Trying to delete invalid node\n";
		return;
	}
}

void linkedList::display()
{
	auto tmp = Head;
	while (tmp != nullptr)
	{
		std::cout << tmp->n << " -> ";
		tmp = tmp->next;
	}
	std::cout << '\n';
}

void linkedList::insertAtPos(int index, int value)
{
	auto lng = getLength();
	if (index < 0 || index > lng + 1)
	{
		std::cout << "Trying OutOfBound Insertion using insertAtPos()\n";
	}

	if (index > 1 && index <= lng)
	{
		auto tmp = Head;
		auto tmp0 = tmp;
		auto cnt = 1;
		while (cnt != index)
		{
			tmp0 = tmp;
			tmp = tmp->next;
			cnt++;
		}
		auto n = std::make_shared<Node>(value);
		tmp0->next = n;
		n->next = tmp;
		return;
	}

	if (index == 1)
	{
		insertAtbegin(value);
		return;
	}
	if (index == lng + 1)
	{
		insertAtlast(value);
		return;
	}
}
