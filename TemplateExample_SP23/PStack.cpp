#include "PStack.h"
#include <new>
#include <cmath>

using namespace std;

PStack::PStack()
{
	topPtr = nullptr;
}

PStack::~PStack()
{
	while (topPtr != nullptr)
	{
		Pop();
	}
}

bool PStack::IsEmpty()
{
	return (topPtr == nullptr);
}

bool PStack::IsFull()
{
	Node* temp;

	try
	{
		temp = new Node;
		delete temp;
		return false;
	}
	catch (const bad_alloc exception)
	{
		return true;
	}
}

bool PStack::Push(SCALAR item)
{
	if (!IsFull())
	{
		Node* temp = new Node;
		temp->info = item;
		temp->next = topPtr;

		topPtr = temp;

		return true;
	}
	else
	{
		return false;
	}
}

SCALAR PStack::Pop()
{
	if (!IsEmpty())
	{
		Node* temp = topPtr;
		SCALAR item = topPtr->info;
		topPtr = topPtr->next;
		delete temp;
		return item;
	}
	else
	{
		return NAN;
	}
}

SCALAR PStack::Top()
{
	return topPtr->info;
}
