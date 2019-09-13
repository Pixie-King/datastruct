#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class student
{
public:
	int number;
	double score;
	char name[11];
	int age;
	int filenum;
	double height;
	char area;
};

class node
{
public:
	student stu;
	node *next;
	node(student s, node* n = NULL) { stu = s; next = n; }
	node(node*n = NULL) { next = n; }
	void printstu();
};
void node::printstu()
{
	cout << stu.filenum << '-' << stu.area << '-' << stu.age << '-' << stu.name << '-' << stu.number << '-';
	cout << setiosflags(ios::fixed) << setprecision(1);
	cout << stu.height << '-';
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << stu.score << endl;
}
class list
{
	node *head , *tail,*current,*first;
public:
	list() { first=new node(head); head = tail = NULL; current = first; }
	void insert(student stu);
	void print();
};
void list::insert(student stu)
{
	current = first;
	while (current ->next!=NULL)
	{
		if (stu.age >= current->stu.age && stu.age <= current->next->stu.age)
		{
			current->next = new node(stu, current->next);
			break;
		}
		current = current->next;
	}
	if(current->next==NULL)
		if(head == NULL)
			head = current->next = new node(stu, current->next);
		else current->next = new node(stu, current->next);

}
void list::print()
{
	current = head;
	while (current != NULL)
	{
		current->printstu();
		current = current->next;
	}
}
int main()
{
	student stu;
	ifstream in;
	list clist, dlist, elist, flist;
	in.open("d:\\data_struct\\data1.dat", ios::binary | ios::in);
	while (in.peek() != EOF)
	{
		in.read((char*)(&stu), sizeof(stu));
		if (stu.area == 'C')
		{
			clist.insert(stu);
		}
		if (stu.area == 'D')
		{
			dlist.insert(stu);
		}
		if (stu.area == 'E')
		{
			elist.insert(stu);
		}
		if (stu.area == 'F')
		{
			flist.insert(stu);
		}
	}
	clist.print();
	dlist.print();
	elist.print();
	flist.print();
	system("pause");
	return 0;
}