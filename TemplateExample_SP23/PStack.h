#ifndef PSTACK_H
#define PSTACK_H

typedef double SCALAR;

struct Node
{
	SCALAR info;
	Node* next;
};

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
	Node* topPtr;

};

#endif // !PSTACK_H

