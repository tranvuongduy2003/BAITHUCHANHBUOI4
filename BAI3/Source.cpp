#include <iostream>
#include <string>
using namespace std;

typedef struct Node Node;
struct Node
{
	string id;
	string name;
	int expYear;
	float salaryFactor;
	long basicSalary;
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
void InputList(List&, int&);
void InsertTail(List&, Node*);
void DescendingExpYearSort(List&);
void DescendingSalarySort(List&);
long AvarageSalary(Node*);
void TopFiveHighestSalary(List);
void TopFiveExpYear(List);

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
	n = 50;
	CreateList(l);
	Node* p = nullptr;
	for (int i = 0; p != nullptr && i < n; i++, p = p->next)
	{
		p = new Node;
		if (p == nullptr)
		{
			cout << "Het bo nho luu tru!" << endl;
			return;
		}
		getline(cin, p->id);
		getline(cin, p->name);
		cin >> p->expYear;
		cin >> p->salaryFactor;
		cin >> p->basicSalary;
		cin.ignore();
		p->prev = nullptr;
		p->next = nullptr;
		InsertTail(l, p);
	}
}
void InsertTail(List& l, Node* p)
{
	if (l.head == nullptr)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}
void DescendingExpYearSort(List& l)
{
	if (l.head == nullptr || l.head->next == nullptr)
		return;
	Node* p = l.head;
	while (p != nullptr)
	{
		Node* t = p;
		Node* q = l.head;
		while (q != p && q->expYear <= t->expYear)
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
	}
}
void DescendingSalarySort(List& l)
{
	if (l.head == nullptr || l.head->next == nullptr)
		return;
	Node* p = l.head;
	while (p != nullptr)
	{
		Node* t = p;
		Node* q = l.head;
		while (q != p && AvarageSalary(q) <= AvarageSalary(t))
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
	}
}
long AvarageSalary(Node* p)
{
	return p->salaryFactor * p->basicSalary;
}
void TopFiveHighestSalary(List l)
{
	DescendingSalarySort(l);
	Node* p = l.head;
	for (int i = 0; i < 5; i++)
	{
		cout << "Ma so nhan su: " << p->id << endl;
		cout << "Ho ten: " << p->name << endl;
		cout << "Tham nien cong tac: " << p->expYear << endl;
		cout << "He so luong: " << p->salaryFactor << endl;
		cout << "Luong co ban: " << p->basicSalary << endl;
		p = p->next;
	}
}
void TopFiveExpYear(List l)
{
	DescendingExpYearSort(l);
	Node* p = l.head;
	for (int i = 0; i < 5; i++)
	{
		cout << "Ma so nhan su: " << p->id << endl;
		cout << "Ho ten: " << p->name << endl;
		cout << "Tham nien cong tac: " << p->expYear << endl;
		cout << "He so luong: " << p->salaryFactor << endl;
		cout << "Luong co ban: " << p->basicSalary << endl;
		p = p->next;
	}
}