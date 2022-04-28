#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef struct Node Node;
struct Node
{
	string name;
	long value;
	int quantity;
	Node* prev; 
	Node* next;
};

typedef struct List List;
struct List
{
	Node* head;
	Node* tail;
};


void CreateList(List&);
void InputList(List&);
void InsertTail(List&, Node*);
void SwapNode(List&, Node*, Node*);
int CompareName(string, string);
void AscendingSort(List&);
void PrintList(List, int, int);

int main()
{
	return 0;
}

void CreateList(List& l)
{
	l.head = nullptr;
	l.tail = nullptr;
}
void InputList(List& l, int& n)
{
	cin >> n;
	Node* p = nullptr;
	for (int i = 0; p != nullptr && i < n; i++, p = p->next)
	{
		p = new Node;
		if (p == nullptr)
		{
			cout << "Het bo nho luu tru!" << endl;
			return;
		}
		getline(cin, p->name);
		cin >> p->value;
		cin >> p->quantity;
		cin.ignore();
		p->prev = p->next = nullptr;
		InsertTail(l, p);
	}
}
void InsertTail(List& l, Node* p)
{
	if (l.head == nullptr)
		l.head = l.tail = nullptr;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}
void SwapNode(List& l, Node* t, Node* q)
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
int CompareName(string s1, string s2)
{
	stack<char> st;
	st.push(s1[0]);
	for (int i = 1; i < s1.length(); i++)
		if (s1[i] == ' ')
			st.push(s1[i + 1]);
	int i;
	for (i = s2.length() - 1; !st.empty() || i > 0; i--)
	{
		if (s2[i - 1] == ' ')
		{
			if (s2[i] > st.top())
				return -1;
			else if (s2[i] < st.top())
				return 1;
			else
				st.pop();
		}
	}
	if (st.empty())
		return -1;
	else
	{
		if (s2[0] > st.top())
			return -1;
		else if (s2[0] < st.top())
			return 1;
		else
			st.pop();
		if (st.empty())
			return 0;
		else
			return 1;
	}
}
void AscendingSort(List& l)
{
	if (l.head == nullptr || l.head->next == nullptr)
		return;
	Node* p = l.head;
	while (p != nullptr)
	{
		Node* t = p;
		Node* q = l.head;
		while (q != p && q->value > t->value)
			q = q->next;
		if (q != p)
		{
			if (q->value != t->value)
				SwapNode(l, q, t);
			else
			{
				if (CompareName(q->name, t->name) == -1)
					SwapNode(l, q, t);
			}
		}
	}
}
void PrintList(List l, int x, int y)
{
	Node* p = l.head;
	while (p != nullptr)
	{
		if (p->quantity > x && p->quantity < y)
		{
			cout << "Ten mat hang: " << p->name << endl;
			cout << "Gia mat hang: " << p->name << endl;
			cout << "So luong hang ton kho: " << p->quantity << endl;
		}
		p = p->next;
	}
}