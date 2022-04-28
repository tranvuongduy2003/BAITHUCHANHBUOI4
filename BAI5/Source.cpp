#include <iostream>
using namespace std;

typedef struct Node Node;
struct Node
{
	int data;
	Node* next;
};

typedef struct Stack Stack;
struct Stack
{
	Node* top;
};

void CreateStack(Stack&);
void Push(Stack&, int);
int Pop(Stack&);
int Empty(Stack);
int Full(Stack);
int Reverse(int);


int main()
{
	int a;
	cin >> a;

	cout <<  Reverse(a) << endl;

	return 0;
}

void CreateStack(Stack& l)
{
	l.top = nullptr;
}
void Push(Stack& l, int x)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "Stack overflow" << endl;
		return;
	}
	p->data = x;
	p->next = nullptr;
	if (l.top == nullptr)
		l.top = p;
	else
	{
		p->next = l.top;
		l.top = p;
	}
}
int Pop(Stack& l)
{
	if (l.top == nullptr)
	{
		cout << "Stack underflow" << endl;
		return -1;
	}
	Node* p = l.top;
	int x = p->data;
	l.top = l.top->next;
	delete p;
	return x;
}
int Empty(Stack l)
{
	return l.top == nullptr;
}
int Full(Stack)
{
	Node* p = new Node;
	return p == nullptr;
}
int Reverse(int a)
{
	int s = 0, n = 1;
	Stack st;
	CreateStack(st);
	while (a != 0)
	{
		Push(st, a % 10);
		a /= 10;
	}
	while (!Empty(st))
	{
		s = s + Pop(st)*n;
		n *= 10;
	}
	return s;
}