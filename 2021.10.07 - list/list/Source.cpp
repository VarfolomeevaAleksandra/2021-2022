#include<iostream>
#include<cstdlib>
#include<list>
#include<string>
#include<ctime>

using namespace std;

struct Subscriber
{
	long long number;
	string name;
	string address;
	Subscriber(long long nu = 0, string na = "", string ad = "") :
		number(nu), name(na), address(ad) {}
};

ostream& operator << (ostream& st, Subscriber x)
{
	return st << "����� " << x.number << "," << "\t" << "��� " << x.name << "," << "\t" << "����� " << x.address << endl;
}

istream& operator << (istream& st, Subscriber x)
{
	st >> x.number >> x.name >> x.address;
	return st;
}

void printMenu()
{
	cout << "0 - ����� �� ���������" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - ������� �������� �� ������ ��������" << endl;
	cout << "3 - ����������� ���������� �� ������ ��������" << endl;
	cout << "4 - ����������� ����" << endl;
}

void add_abonent(list<Subscriber>& s, long long number, string name, string address)
{
	Subscriber t(number, name, address);
	s.push_back(t);
}

void del_abonent(list<Subscriber>& s, long long number)
{
	for (auto i = s.begin(); i != s.end(); i++)
	{
		Subscriber t = *i;
		if (t.number == number)
		{
			s.erase(i);
			return;
		}
	}
	cout << "������ �������� ���" << endl;
}

void print(list<Subscriber>& s, long long number)
{
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		Subscriber t = *i;
		if (t.number == number)
		{
			cout << t;
			return;
		}
	}
	cout << "������ �������� ���" << endl;
}

void print_all(list<Subscriber>& s)
{
	Subscriber t;
	for (auto i = s.begin(); i != s.end(); i++)
	{
		t = *i;
		cout << t << endl;
	}
}

void processChoice(list<Subscriber>& s, int choice)
{
	switch (choice)
	{
	case 0:
	{
		exit(0);
	}
	break;
	case 1:
	{
		long long nu;
		string na;
		string ad;
		cout << "������� �����, ��� � �����" << endl;
		cin >> nu >> na >> ad;
		add_abonent(s, nu, na, ad);
	}
	break;
	case 2:
	{
		long long nu;
		cout << "������� �����" << endl;
		cin >> nu;
		del_abonent(s, nu);
	}
	break;
	case 3:
	{
		long long nu;
		cout << "������� �����" << endl;
		cin >> nu;
		print(s, nu);
	}
	break;
	case 4:
	{
		print_all(s);
	}
	break;
	}
}



int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	list<Subscriber>s;
	list<int>::iterator i;
	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(s, choice);
		system("pause");
	} 
	while (choice != 0);

	return EXIT_SUCCESS;
	
}
