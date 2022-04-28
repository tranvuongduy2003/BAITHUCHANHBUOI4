#include <iostream>
#include <string>
using namespace std;

struct Node
{
	void* data;
	struct Node* next;
};
typedef struct Node Node;

struct Stack
{
	Node* top;
};
typedef struct Stack Stack;

void CreateStack(Stack&);
void Push(Stack&, void*);
void* Pop(Stack&);
int Empty(Stack);
int Full(Stack);
string ConvertToBinary(int);
string ConvertToHexa(int);
string ConvertToOctal(int);

int main()
{
	int a;
	cin >> a;
	cout << ConvertToBinary(a) << endl;
	cout << ConvertToHexa(a) << endl;
	cout << ConvertToOctal(a) << endl;
	return 0;
}

void CreateStack(Stack& st)
{
	st.top = nullptr;
}
void Push(Stack& st, void* x)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "Stack overflow" << endl;
		exit(-1);
	}
	p->data = x;
	p->next = nullptr;
	if (st.top == nullptr)
		st.top = p;
	else
	{
		p->next = st.top;
		st.top = p;
	}
}
void* Pop(Stack& st)
{
	if (st.top == nullptr)
	{
		cout << "Stack underflow" << endl;
		exit(-1);
	}
	Node* p = st.top;
	void* x = p->data;
	st.top = st.top->next;
	delete p;
	return x;
}
int Empty(Stack st)
{
	return st.top == nullptr;
}
int Full(Stack st)
{
	Node* p = new Node;
	return p == nullptr;
}

string ConvertToBinary(int a)
{
	Stack st;
	CreateStack(st);
	string s = "";
	while (a != 0)
	{
		Push(st, (int*)(a % 2));
		a /= 2;
	}
	while (!Empty(st))
		s += char((int)Pop(st) + 48);
	return s;
}
string ConvertToHexa(int a)
{
	Stack st;
	CreateStack(st);
	string s = "";
	int t;
	while (a != 0)
	{
		Push(st, (int*)(a % 16));
		a /= 16;
	}
	while (!Empty(st))
	{
		t = (int)Pop(st);
		if (t < 10)
			s += char(t + 48);
		else
			s += char(t + 55);
	}
	return s;
}
string ConvertToOctal(int a)
{
	Stack st;
	CreateStack(st);
	string s = "";
	while (a != 0)
	{
		Push(st, (int*)(a % 8));
		a /= 8;
	}
	while (!Empty(st))
		s += char((int)Pop(st) + 48);
	return s;
}