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

void CreateList(List&);
void InputList(List&);
void OrderedInsert(List&, Node*);
void PrintList(List);

void InputOrderedArray(int*, int&);
void ArrayOrderedInsert(int*, int, int&);
void PrintArray(int*, int);

int main()
{
	List l;
	int a[10001];
	int n = 0;

	clock_t start, end;

	//Linked List
	start = clock();
	CreateList(l);
	InputList(l);
	end = clock();
	PrintList(l);

	cout << "Thoi gian thuc hien bai toan su dung Linked List: " << (double)(end - start) / CLOCKS_PER_SEC << endl;

	//Array
	start = clock();
	InputOrderedArray(a, n);
	end = clock();
	PrintArray(a, n);
	cout << "Thoi gian thuc hien bai toan su dung Array: " << (double)(end -  start) / CLOCKS_PER_SEC << endl;

	return 0;
}

void CreateList(List& l)
{
	l.head = nullptr;
	l.tail = nullptr;
}
void InputList(List& l)
{
	int a;
	do
	{
		cin >> a;
		if (a != -1)
		{
			Node* t = new Node;
			t->prev = nullptr;
			t->next = nullptr;
			t->data = a;
			OrderedInsert(l, t);
		}
	} while (a != -1);
}
void OrderedInsert(List& l, Node* t)
{
	Node* p = l.head;
	if (p == nullptr)
		l.head = l.tail = t;
	else
	{
		while (p != nullptr && p->data <= t->data)
			p = p->next;
		if (p == nullptr)
		{
			l.tail->next = t;
			t->prev = l.tail;
			l.tail = t;
		}
		else if (p == l.head)
		{
			l.head->prev = t;
			t->next = l.head;
			l.head = t;
		}
		else
		{
			t->prev = p->prev;
			p->prev->next = t;
			p->prev = t;
			t->next = p;
		}
	}
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

void InputOrderedArray(int* a, int& n)
{
	int t;
	do
	{
		cin >> t;
		if (t != -1)
			ArrayOrderedInsert(a, t, n);
	} while (t != -1);
}
void ArrayOrderedInsert(int* a, int t, int& n)
{
	if (n == 0)
		a[0] = t;
	else
	{
		int i = 0;
		while (i < n && a[i] <= t)
			i++;
		if (i < n)
			for (int j = n; j > i; j--)
				a[j] = a[j - 1];
		a[i] = t;
	}
	n++;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//Nhin chung cach su dung mang va Linked List co thoi gian chay xap xi bang nhau,
//vi ca hai deu co do phuc tap O(n^2). Tuy nhien, voi so luong phan tu lon (du lieu
//ngau nhien) thi Linked List co phan nhanh hon mang va cach dung mang co hien tuong
//tran mang khi so phan tu vuot qua kich thuoc cua mang