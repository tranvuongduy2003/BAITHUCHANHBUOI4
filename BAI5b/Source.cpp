#include <iostream>
using namespace std;

typedef struct Node Node;
struct Node
{
	int data;
	Node* next;
};

typedef struct Queue Queue;
struct Queue
{
	Node* front;
	Node* back;
};

void CreateQueue(Queue&);
void EnQueue(Queue&, int);
int DeQueue(Queue&);
int Empty(Queue);
int Full(Queue);
int Reverse(int);

int main()
{
	int n;
	cin >> n;

	cout << Reverse(n) << endl;
	return 0;
}

void CreateQueue(Queue& q)
{
	q.front = q.back = nullptr;
}
void EnQueue(Queue& q, int x)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "Queue is full" << endl;
		return;
	}
	p->data = x;
	p->next = nullptr;
	if (q.front == nullptr)
		q.front = q.back = p;
	else
	{
		q.back->next = p;
		q.back = q.back->next;
	}
}
int DeQueue(Queue& q)
{
	if (q.front == nullptr)
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	Node* p = q.front;
	int x = p->data;
	q.front = q.front->next;
	delete p;
	return x;
}
int Empty(Queue q)
{
	return q.front == nullptr;
}
int Full(Queue q)
{
	Node* p = new Node;
	return p == nullptr;
}
int Reverse(int a)
{
	Queue q;
	int s = 0;
	CreateQueue(q);
	while (a != 0)
	{
		EnQueue(q, a % 10);
		a /= 10;
	}
	while (!Empty(q))
		s = s * 10 + DeQueue(q);
	return s;
}