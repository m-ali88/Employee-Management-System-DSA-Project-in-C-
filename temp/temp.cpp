#pragma warning(disable : 4996)

#include <iostream>
#include<conio.h>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<string>
using namespace std;

struct Node {
	string Emp_id, Name, Post, Department;
	float salary;
	Node* next;
	Node* prev;
};

class Employee {
private:
	Node* front, * rear;
public:
	Employee();
	void Introduction();
	void Login();
	void Menu();
	void Insert();
	void Search();
	void Edit();
	void Delete();
	void Display();
	void Salary();
	void readsal();
};

Employee::Employee() {
	front = NULL;
	rear = NULL;
}

void Employee::Introduction() {
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "\t\t\t==================================";
	cout << "\n\t\t\t==================================";
	cout << "\n\n\t\t\t    EMPLOYEE MANAGEMENT SYSTEM";
	cout << "\n\n\t\t\t==================================";
	cout << "\n\t\t\t==================================";
	_getch();
}

void Employee::Login() {
p:
	system("cls");
	string user, pass;
	cout << "\n\n";
	cout << "\t\t\t======================";
	cout << "\n\n\t\t\t     LOGIN PANEL";
	cout << "\n\n\t\t\t======================";
	cout << "\n\n\nEnter USER NAME : ";
	cin >> user;
	cout << "\n\nENTER PASSWORD : ";
	for (int i = 1; i <= 6; i++) {
		pass += _getch();
		cout << "*";
	}
	if (user == "ALI" && pass == "123456") {
		cout << "\n\n\n\t\t\tLOGIN SUCCESSFUL";
		cout << "\n\n\n\t\t\tLOADING";
		for (int i = 1; i <= 6; i++) {
			Sleep(500);
			cout << ".";
		}
		Menu();
	}
	else if (user != "ALI" && pass == "123456") {
		cout << "\n\nUSER NAME IS WRONG...";
	}
	else if (user == "ALI" && pass != "123456") {
		cout << "\n\nPASSWORD IS WRONG...";
	}
	else if (user != "ALI" && pass != "1234") {
		cout << "\n\nUSERNAME & PASSWORD ARE WRONG...";
	}
	_getch();
	goto p;
}

void Employee::Menu() {
p:
	system("cls");
	int a;
	cout << "\n\n\t\t\t============================";
	cout << "\n\n\t\t\t   EMPLOYEE CONTROL PANEL";
	cout << "\n\n\t\t\t============================";
	cout << "\n\n1: INSERT  RECORD";
	cout << "  \n2: SEARCH  RECORD";
	cout << "  \n3: EDIT    RECORD";
	cout << "  \n4: DELETE  RECORD";
	cout << "  \n5: DISPLAY RECORD";
	cout << "  \n6: SALARY  RECORD";
	cout << "  \n7: DISPLAY SALARY RECORD";
	cout << "  \n8: EXIT";
	cout << "\n\nENTER YOUR CHOICE: ";
	cin >> a;
	switch (a) {
	case 1:

		Insert();
		break;
	case 2:
		Search();
		break;
	case 3:
		Edit();
		break;
	case 4:
		Delete();
		break;
	case 5:
		Display();
		break;
	case 6:
		Salary();
		break;
	case 7:
		readsal();
		break;
	case 8:
		exit(0);
	default:
		cout << "INVALID CHOICE....TRY AGAIN";

	}
	_getch();
	goto p;
}

void Employee::Insert() {
p:
	system("cls");
	string id, n, p, d,Temp;
	float sa;
	cout << "\n\n\t\t\t===========================";
	cout << "\n\n\t\t\t INSERT EMPLOYEE RECORD";
	cout << "\n\n\t\t\t===========================";
	cout << "\n\n EMPLOYEE ID: ";
	cin >> id;
	cin.ignore();
	cout << "\n\n EMPLOYEE NAME: ";
	getline(cin, n);
	cout << "\n\n EMPLOYEE POST: ";
	getline(cin, p);
	cout << "\n\n EMPLOYEE DEPARTMENT: ";
	getline(cin, d);
	cout << "\n\n EMPLOYEE SALARY: ";
	cin >> sa;
	fstream a;
	a.open("Employee Record.txt", ios::in);
	if (!a)
	{
		cout << "\nError while opening the file\n";
	}
	else
	{
		while (getline(a, Temp))
		{
			if (Temp == id)
			{
				cout << "***DUPLICATE EMPLOYEE RECORD***";
				cout << "\n\n\n Enter Again!!";
				_getch();
				goto p;
			}
		}
	}
	a.close();
	
		Node* temp = new Node;
		temp->Emp_id = id;
		temp->Name = n;
		temp->Post = p;
		temp->Department = d;
		temp->salary = sa;
		temp->next = NULL;
		temp->prev = NULL;
		if (rear == NULL) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
		ofstream myfile("Employee Record.txt", ios::app);
		myfile << temp->Emp_id << endl;
		myfile << temp->Name << endl;
		myfile << temp->Post << endl;
		myfile << temp->Department << endl;
		myfile << temp->salary << endl;;
		myfile << "\n\n";
		myfile.close();
		cout << "\n\n***EMPLOYEE RECORD INSERTED***";
	
}

void Employee::Search() {
	system("cls");
	string temp, ID;
	cout << "\n\n\t\t\t===========================";
	cout << "\n\n\t\t\t  SEARCH EMPLOYEE RECORD";
	cout << "\n\n\t\t\t===========================";
	cout << "\n\nEnter Employee ID : ";
	cin >> ID;
	cout << endl<<endl;
	fstream a;
	int i = 0;
	int found = 0;
	a.open("Employee Record.txt", ios::in);
	if (!a)
	{
		cout << "\nError while opening the file\n";
	}
	else
	{
		while (getline(a, temp))
		{
			if (temp == ID)
			{
				cout << "Employee ID: ";
				cout << temp << "\n\n";
				i = 4;
				found++;
			}
			else if (temp != ID && i == 4)
			{
				cout << "Employee Name: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 3)
			{
				cout << "Employee Post: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 2)
			{
				cout << "Employee Department: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 1)
			{
				cout << "Employee Salary: ";
				cout << temp << "\n\n";
				--i;
			}
			
		}
		cout << endl << endl;
		
	}
	a.close();
	if (found == 0) {
		cout << "***RECORD NOT FOUND***";
	}
}

void Employee::Edit() {
	system("cls");
	string temp, ID;
	cout << "\n\n\t\t\t=========================";
	cout << "\n\n\t\t\t MODIFY EMPLOYEE RECORD";
	cout << "\n\n\t\t\t=========================";
	cout << "\n\nEnter Employee ID : ";
	cin >> ID;
	cout << endl << endl;
	fstream a;
	int i = 0;
	int found = 0;
	a.open("Employee Record.txt", ios::in);
	if (!a)
	{
		cout << "\nError while opening the file\n";
	}
	else
	{
		while (getline(a, temp))
		{
			if (temp == ID)
			{
				cout << "Employee ID: ";
				cout << temp << "\n\n";
				i = 4;
				found++;
			}
			else if (temp != ID && i == 4)
			{
				cout << "Employee Name: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 3)
			{
				cout << "Employee Post: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 2)
			{
				cout << "Employee Department: ";
				cout << temp << "\n\n";
				--i;
			}
			else if (temp != ID && i == 1)
			{
				cout << "Employee Salary: ";
				cout << temp << "\n\n";
				--i;
			}
		}
		cout << endl << endl;
	}
	a.close();
	if (found == 0) {
		cout << "***RECORD NOT FOUND***";
	}
	else {
		int choice1;
		cout << "\n\nEnter 1 to Modify";
		cout << "\nEnter 2 to Go Back";
		cout << "\n\nEnter Your Choice : ";
		cin >> choice1;
		cin.ignore();
		if (choice1 == 1)
		{
			ifstream b;
			ofstream c;
			b.open("Employee Record.txt");
			c.open("record.txt");
			int i = 6;
			while (getline(b, temp))
			{
				if (temp != ID && i == 6)
				{
					c << temp << endl;
				}
				if (temp == ID && i == 6)
				{
					i--;
				}
				if (temp == ID && i == 6)
				{
					i--;
				}
				else if (i > 0 && i < 6)
				{
					i--;
				}
				if (i == 0)
				{
					i = 6;
				}
			}
			cout << "***EMPLOYEE RECORD DELETED***" << endl;
			b.close();
			c.close();
			remove("Employee Record.txt");
			rename("record.txt", "Employee Record.txt");
			Insert();
		}
	}

}

void Employee::Delete() {
	system("cls");
	int found = 0;
	string ID,temp;
	cout << "\n\n\t\t\t=========================";
	cout << "\n\n\t\t\t DELETE EMPLOYEE RECORD";
	cout << "\n\n\t\t\t=========================";
	cout << "\n\nEnter Employee ID : ";
	cin >> ID;
	ifstream b;
	ofstream c;
	b.open("Employee Record.txt");
	c.open("record.txt");
	int i = 6;
	while (getline(b, temp))
	{
		if (temp != ID && i == 6)
		{
			c << temp << endl;
			found++;
		}
		if (temp == ID && i == 6)
		{
			i--;
		}
		if (temp == ID && i == 6)
		{
			i--;
		}
		else if (i > 0 && i < 6)
		{
			i--;
		}
		if (i == 0)
		{
			i = 6;
		}
	}
	if (found == 0) {
		cout << "***RECORD NOT FOUND***";
	}
	else {
		cout << "***EMPLOYEE RECORD DELETED***" << endl;
		b.close();
		c.close();
		remove("Employee Record.txt");
		rename("record.txt", "Employee Record.txt");
	}
}

void Employee::Display() {
	system("cls");
	cout << "\n\n\t\t\t=========================";
	cout << "\n\n\t\t\t DISPLAY EMPLOYEE RECORD";
	cout << "\n\n\t\t\t=========================";
	ifstream a;
	a.open("Employee Record.txt");
	if (!a)
	{
		cout << "\nError while opening the file\n";
	}
	else
	{
		string temp;
		int e = 0;
		int r = 0;
		cout << endl;
		while (getline(a, temp))
		{
			if (temp.empty())
			{
				r = r + 1;
				if (r == 2)
				{
					e = 0;
					r = 0;
					cout << endl;
				}
			}
			else {
				if (e < 5)
				{
					if (e == 0)
					{
						cout << "Employee ID : "<<temp << endl<<endl;
						e = e + 1;
					}
					else if (e == 1)
					{
						cout << "Employee Name : " << temp << endl << endl;
						e = e + 1;
					}
					else if (e == 2)
					{
						cout << "Employee Post : " << temp << endl << endl;
						e = e + 1;
					}
					else if (e == 3)
					{
						cout << "Employee Department : " << temp << endl << endl;
						e = e + 1;
					}
					else if (e == 4)
					{
						cout << "Employee Salary : " << temp << endl << endl;
						e = e + 1;
					}
				}
			}
		}
	}
	a.close();	
}

void Employee::Salary() {
	system("cls");
	time_t timetoday;
	time(&timetoday);
	string ID,temp;
	cout << "\n\n\t\t\t=========================";
	cout << "\n\n\t\t\t SALARY SLIP GENERATION";
	cout << "\n\n\t\t\t=========================";


		cout << "\n\n ENTER EMPLOYEE ID FOR SLIP: ";
		cin >> ID;
		fstream a;
		int i = 0;
		int found = 0;
		a.open("Employee Record.txt", ios::in);
		ofstream myfile("Salary Record.txt", ios::app);
		if (!a)
		{
			cout << "\nError while opening the file\n";
		}
		else
		{
			while (getline(a, temp))
			{
				if (temp == ID)
				{
					system("cls");
					cout << "\n\t\t\t******************************";
					cout << "\n\t\t\t*                            *";
					cout << "\n\t\t\t*   EMPLOYEE SALARY SLIP     *";
					cout << "\n\t\t\t*                            *";
					cout << "\n\t\t\t******************************";
					myfile << "\n\t\t\t******************************";
					myfile << "\n\t\t\t*                            *";
					myfile << "\n\t\t\t*   EMPLOYEE SALARY SLIP     *";
					myfile << "\n\t\t\t*                            *";
					myfile << "\n\t\t\t******************************";
					cout << "\n\n\t\t\t EMPLOYEE ID:      " << temp;
					myfile << "\n\n\t\t\t EMPLOYEE ID:      " << temp;
					i = 4;
					found++;
				}
				else if (temp != ID && i == 4)
				{
					cout << "\n\n\t\t\t EMPLOYEE Name:      " << temp;
					myfile << "\n\n\t\t\t EMPLOYEE Name:      " << temp;
					--i;

				}
				else if (temp != ID && i == 3)
				{
					cout << "\n\n\t\t\t EMPLOYEE Post:      " << temp;
					myfile << "\n\n\t\t\t EMPLOYEE Post:      " << temp;
					--i;
				}
				else if (temp != ID && i == 2)
				{
					cout << "\n\n\t\t\t EMPLOYEE Department:      " << temp;
					myfile << "\n\n\t\t\t EMPLOYEE Department:      " << temp;
					--i;
				}
				else if (temp != ID && i == 1)
				{
					cout << "\n\n\t\t\t EMPLOYEE Salary:      " << temp;
					myfile << "\n\n\t\t\t EMPLOYEE Salary:      " << temp;
					--i;
				}

			}
			if (found == 0) {
				cout << "\n\n***RECORD NOT FOUND***";
			}
			else {
				cout << "\n\n\t\t\t TIME:             " << asctime(localtime(&timetoday));
				myfile << "\n\n\t\t\t TIME:             " << asctime(localtime(&timetoday));
				myfile.close();
				cout << endl << endl;

			}
		}
		a.close();
		
}

void Employee::readsal() {
	string myText;

	cout << "\n\n\t\t\t=========================";
	cout << "\n\n\t\t\t    SALARY RECORD";
	cout << "\n\n\t\t\t=========================\n\n";

	ifstream MyReadFile("Salary Record.txt");

	while (getline(MyReadFile, myText)) {

		cout << myText << "\n\n";
	}
}

int main()
{
	Employee e;
	e.Introduction();
	e.Login();
}

