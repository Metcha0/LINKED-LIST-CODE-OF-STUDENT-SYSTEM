#include <iostream>
#include <string.h>
#include <string>

using namespace std;

// Implementation of the node .
class node
{
public:
	string name;
	int id;
	string course;
	float mark;
	node* next;
	// parameterized counstructor of node .
	node(string n, int ID, string c, float m)
	{
		name = n;
		id = ID;
		course = c;
		mark = m;
	}
};

// Implementation of the Linked list .
class studentlist
{
	int someArray[3];

	node* head, * tail;

public:
	
	//constructor 
	studentlist()
	{
		head = tail = NULL;
	}
	bool isempty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	
	void readArray()
	{
		std::cout << "Reading someArray elements.\n";

		// prefer using size_t for lengths and sizes, instead of int
		for (std::size_t i = 0; i < 3; ++i)
		{
			std::cout << "someArray[" << i << "]: ";
			std::cin >> someArray[i];
		}
	}
	
	//get the length of linkedlist .
	int getlength()
	{
		int count = 0;
		node* ptr = head;
		while (ptr != NULL)
		{
			++count;
			ptr = ptr->next;
		}
		return count;
	}
	
	// delete first node in linked list .
	void deletefirst()
	{
		node* n = head;
		if (isempty())
		{
			cout << " IS Empty /n";
		}
		else
		{
			head = head->next;
			delete n;
		}
	}
	
	//delete last node in linkedlist .
	void deletelast()
	{
		node* temp, * prev;
		temp = prev = head;
		while (temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		tail = prev;
		delete temp;
	}
	
	void deleteatpos(int pos)
	{
		if (pos<0 || pos>getlength())
		{
			cout << " Invalid postion \n";
		}
		else if (pos == 0)
		{
			deletefirst();
		}
		else if (pos == getlength())
		{
			deletelast();
		}
		else
		{
			node* x;
			node* temp = head;
			for (int i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			x = temp->next;
			temp->next = temp->next->next;
			delete x;
		}
	}

	// checking if the id used before or not 
	bool checking(int id)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->id == id)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	
	//inserting a new student .
	void insertingdata(string na, int i, string c, float m)
	{
		
		if (checking(i) == true)
		{
		cout << " This Student id is already exist : " << i<< endl;
		}
		else
		{
			node* n = new node(na, i, c, m);
		    n->next = head;
			if (isempty())
			{
				head = tail = n;
			}
			else
			{
				n->next = head;
				head = n;
			}
		}
	}

	// search for the position of the entered id .
	int searchfordelete(int id)
	{
		int pos=-1;
		node* temp = head;
		int counter = -1;
		while (temp != NULL)
		{		
			counter++;	
			if (checking(id) == true)
			{
				if (temp->id == id)
				{
					pos = counter;
					return pos;
				}
			}
			else
				{
					cout << "NOt exist \n";
					return -1;
				}
			temp = temp->next;
		}
	}
	
	//delete the student by using his ID .
	void deleting(int id)
	{
		if (checking(id) == true)
		{
			
			deleteatpos(searchfordelete(id));
			cout << " Deleted done for id : " << id << endl;
		}
		else 
		{
			cout << " This id is not exist for delete : " << id << endl;
		}
	 
	}

	// showing information of students .
	void show()
	{
		node* ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->name << " , " << ptr->id << " , " << ptr->course
				<< " , " << ptr->mark << endl;
			ptr = ptr->next;
		}
		cout << endl;
	}
};
int main()
{
	// Testing the function .
	
	//////////////////////////////////
	
	// Getting objects from the studentlist class 
	
	studentlist s1;
	
	//this for inserting a fixed test data after testing the insertion function .

	// Data of student for test .
	string mo[] = { " afsha" , " neymar" , " salah" , " messi" };
	int id[] = { 1000 , 2000 , 3000 ,4000 };
	string co[] ={ " English " , " math " , " data structure " , " Microprocessor " };
	float ma[] = { 100 , 50 , 80 , 10000000 };
	
	s1.insertingdata(mo[0] , id[0], co[0] , ma[0]);
	s1.insertingdata(mo[1] , id[1], co[1] , ma[1]);
	s1.insertingdata(mo[2] , id[2], co[2] , ma[2]);
	s1.insertingdata(mo[3] , id[3], co[3] , ma[3]);
	// showing data 
	s1.show();

	// insert student holds id existed before 
	cout << " ------------------------------------------------------ \n";
	s1.insertingdata("Test name", 4000, "test courses ", 105);
	cout << " ------------------------------------------------------ \n";
	
	// showing after insert exesit id //
	s1.show();


	//delete by entering exist id  
	s1.deleting(2000);
	s1.show();

	// try to delete unexist id 
	s1.deleting(9000);
	
	cout << " -------------------------------------------------------------------------------------------- /n";

	//enering data from user 
	//entering array an passing it to the class functions
 int const size = 5;

	string names[size], subjects[size];
	int ids[size];
	float totalmarks[size];





	return 0;
	}