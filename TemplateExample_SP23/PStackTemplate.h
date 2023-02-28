#ifndef PSTACK_H
#define PSTACK_H

//typedef double SCALAR;

//#include "PStack.h"
#include <new>
#include <cmath>

using namespace std;

template<class SCALAR>
struct Node
{
	SCALAR info;
	Node<SCALAR>* next;
};

template<class SCALAR>
class PStack
{
public:
	PStack();
	~PStack();
	bool IsEmpty();
	bool IsFull();
	bool Push(SCALAR item);
	SCALAR Pop();
	SCALAR Top();

private:
	Node<SCALAR>* topPtr;

};

//#endif // !PSTACK_H

template<class SCALAR>
PStack<SCALAR>::PStack()
{
	topPtr = nullptr;
}

template<class SCALAR>
PStack<SCALAR>::~PStack()
{
	while (topPtr != nullptr)
	{
		Pop();
	}
}

template<class SCALAR>
bool PStack<SCALAR>::IsEmpty()
{
	return (topPtr == nullptr);
}

template<class SCALAR>
bool PStack<SCALAR>::IsFull()
{
	Node<SCALAR>* temp;

	try
	{
		temp = new Node<SCALAR>;
		delete temp;
		return false;
	}
	catch (const bad_alloc exception)
	{
		return true;
	}
}

template<class SCALAR>
bool PStack<SCALAR>::Push(SCALAR item)
{
	if (!IsFull())
	{
		Node<SCALAR>* temp = new Node<SCALAR>;
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

template<class SCALAR>
SCALAR PStack<SCALAR>::Pop()
{
	if (!IsEmpty())
	{
		Node<SCALAR>* temp = topPtr;
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

template<class SCALAR>
SCALAR PStack<SCALAR>::Top()
{
	return topPtr->info;
}

#endif // !PSTACK_H