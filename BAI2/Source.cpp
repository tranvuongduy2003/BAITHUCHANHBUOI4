#include <iostream>
using namespace std;

typedef struct Node Node;
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

typedef struct List List;
struct List
{
	Node* head;
	Node* tail;
};

Node* CreateNode(int);
void CreateList(List&);
void InsertTail(List&, Node*);
void DeleteNode(List&, int);
void PrintList(List);
void PrintReverseList(List);
Node* Search(List, int);
void Sort(List&);


int main()
{
	int t;
	List l;
	Node* p = nullptr;
	CreateList(l);
	for (int i = 0; i < 10; i++)
	{
		cin >> t;
		p = CreateNode(t);
		InsertTail(l, p);
	}

	PrintList(l);
	DeleteNode(l, 10);

	PrintList(l);
	PrintReverseList(l);

	p = Search(l, 14);
	if (p != nullptr)
		cout << "Tim thay " << p->data << endl;
	else
		cout << "Khong tim thay" << endl;
	
	Sort(l);
	PrintList(l);

	return 0;
}

Node* CreateNode(int key)
{
	Node* t = new Node;
	if (t == nullptr)
		return nullptr;
	t->data = key;
	t->prev = nullptr;
	t->next = nullptr;
	return t;
}
void CreateList(List& l)
{
	l.head = nullptr;
	l.tail = nullptr;
}
void InsertTail(List& l, Node* p)
{
	if (l.tail == nullptr)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}
void DeleteNode(List& l, int key)
{
	Node* p = l.head;
	while (p != nullptr && p->data != key)
		p = p->next;
	if (p == nullptr)
	{
		cout << "Khong ton tai phan tu!" << endl;
		return;
	}
	if (p->prev != nullptr)
		p->prev->next = p->next;
	if (p->next != nullptr)
		p->next->prev = p->prev;
	delete p;
}
void PrintList(List l)
{
	Node* p = l.head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void PrintReverseList(List l)
{
	Node* q = l.tail;
	while (q != nullptr)
	{
		cout << q->data << " ";
		q = q->prev;
	}
	cout << endl;
}
Node* Search(List l, int key)
{
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return nullptr;
}
void Sort(List& l)
{
	if (l.head == nullptr || l.head->next == nullptr)
		return;
	Node* p = l.head;
	while (p != nullptr)
	{
		Node* t = p;
		Node* q = l.head;
		while (q != p && q->data <= t->data)
			q = q->next;
		if (q != p)
		{
			if (t->prev != nullptr)
				t->prev->next = t->next;
			if (t->next != nullptr)
				t->next->prev = t->prev;

			if (q == l.head)
			{
				t->prev = nullptr;
				l.head->prev = t;
				t->next = l.head;
				l.head = t;
			}
			else
			{
				t->prev = q->prev;
				q->prev->next = t;
				q->prev = t;
				t->next = q;
			}
		}
		p = p->next;
	}
}