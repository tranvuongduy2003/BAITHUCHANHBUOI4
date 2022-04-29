#include <iostream>
using namespace std;

typedef struct Disks Disks;
struct Disks
{
	int n;
	char a;
	char b;
	char c;
};

typedef struct Node Node;
struct Node
{
	Disks data;
	Node* next;
};

typedef struct Stack Stack;
struct Stack
{
	Node* top;
};


void InitStack(Stack&);
void Push(Stack&, int);
Disks Pop(Stack&);
int Empty(Stack);
int Full(Stack);

void Chuyen(char, char);
//void ThapHaNoi(int, char, char, char);
void ThapHaNoi(int);


int main()
{
	//ThapHaNoi(3, 'A', 'B', 'C');
	//cout << endl;
	ThapHaNoi(3);
	return 0;
}

void InitStack(Stack& st)
{
	st.top = nullptr;
}
void Push(Stack& st, Disks x)
{
	Node* p = new Node;
	if (p == nullptr)
	{
		cout << "Stack overflow" << endl;
		exit(-1);
 	}
	p->data = x;
	p->next = st.top;
	st.top = p;
}
Disks Pop(Stack& st)
{
	if (st.top == nullptr)
	{
		cout << "Stack underflow" << endl;
		exit(-1);
	}
	Node* p = st.top;
	Disks x = p->data;
	st.top = st.top->next;
	delete p;
	return x;
}
int Empty(Stack st)
{
	return st.top == nullptr;
}
int Full(Stack)
{
	Node* p = new Node;
	return p == nullptr;
}

void Chuyen(char a, char b)
{
	cout << "Chuyen dia tu coc " << a << " sang coc " << b << endl;
}
//void ThapHaNoi(int n, char a, char b, char c)
//{
//	if (n == 1)
//		Chuyen(a, c);
//	else
//	{
//		ThapHaNoi(n - 1, a, c, b);
//		Chuyen(a, c);
//		ThapHaNoi(n - 1, b, a, c);
//	}
//}
void ThapHaNoi(int n)
{
	Disks disks;
	char A, B, C;
	Stack st;
	InitStack(st);
	disks.n = n, disks.a = 'A', disks.b = 'B', disks.c = 'C';
	Push(st, disks);
	do
	{
		disks = Pop(st);
		A = disks.a, B = disks.b, C = disks.c;
		if (disks.n == 1)
			Chuyen(disks.a, disks.c);
		else
		{
			n = disks.n;
			disks.n = n - 1, disks.a = B; disks.b = A, disks.c = C;
			Push(st, disks);
			disks.n = 1, disks.a = A, disks.b = ' '; disks.c = C;
			Push(st, disks);
			disks.n = n - 1, disks.a = A, disks.b = C, disks.c = B;
			Push(st, disks);
		}
	} while (!Empty(st));
}