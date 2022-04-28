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
void PushBack(List&, Node*);
void RemoveDuplicates(List&);
void PrintList(List);

void InputArray(int*, int&);
void ArrayRemoveDuplicates(int*, int&);
void PrintArray(int*, int);

int main()
{
	List l;
	int a[100001];
	int n = 0;

	clock_t start, end;
	
	//Linked List
	CreateList(l);
	InputList(l);
	start = clock();
	RemoveDuplicates(l);
	end = clock();
	PrintList(l);
	cout << "Thoi gian thuc hien bai toan su dung Linked List: " << (double)(end - start) / CLOCKS_PER_SEC << endl;


	//Array
	InputArray(a, n);
	start = clock();
	ArrayRemoveDuplicates(a, n);
	end = clock();
	PrintArray(a, n);
	cout << "Thoi gian thuc hien bai toan su dung Array: " << (double)(end - start) / CLOCKS_PER_SEC << endl;


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
			PushBack(l, t);
		}
	} while (a != -1);
}
void PushBack(List& l, Node* t)
{
	if (l.head == nullptr)
		l.head = l.tail = t;
	else
	{
		l.tail->next = t;
		t->prev = l.tail;
		l.tail = t;
	}
}
void RemoveDuplicates(List& l)
{
	if (l.head == nullptr || l.head->next == nullptr)
		return;
	Node* p = l.head;
	while (p != nullptr)
	{
		Node* q = p->next;
		while (q != nullptr)
		{
			if (q->data == p->data)
			{
				Node* t = q->next;
				q->prev->next = q->next;
				if (t != nullptr)
					q->next->prev = q->prev;
				else
				{
					l.tail = q->prev;
					l.tail->next = nullptr;
				}
				delete q;
				q = t;
			}
			else
				q = q->next;
		}
		p = p->next;
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

void InputArray(int* a, int& n)
{
	int t;
	do
	{
		cin >> t;
		if (t != -1)
			a[n++] = t;
	} while (t != -1);
}
void ArrayRemoveDuplicates(int* a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i + 1;
		while (j < n)
		{
			if (a[j] == a[i])
			{
				n--;
				for (int k = j; k <= n; k++)
					a[k] = a[k + 1];
			}
			else
				j++;
		}
	}
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//Khi so phan tu nho, hai cach dung mang va Linked List chay tuong doi nhanh va xap xi
//bang nhau. Khi so phan tu lon, cach dung Linked List se chay nhanh hon so voi cach
//dung mang vi ham RemoveDuplicates cua Linked List cua mat O(n^2) trong khi voi mang 
//thi phai can toi O(n^3), tuy nhien do la khi du lieu xuat hien nhieu cap so trung 
//nhau, con khi cac phan tu khac nhau nhieu thi cach dung mang lai nhanh hon (trong 
//truong hop tat ca cac phan tu deu khac nhau thi cach dung mang chi mat O(n^2) cach 
//xu li no cung xu li don gian hon cach dung Linked List). 