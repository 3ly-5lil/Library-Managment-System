#include<iostream>
#include<string>

using namespace std;

//global variables 
int user_index = 4, book_index = 0;

struct date
{
	int day, month, year, total_days;
};

struct account
{
	string username, password, name, email, account_type, contact[3];
	int id, number_of_contacts;
	date creation_date;
}user[999];

struct book
{
	string title, category;
	int number_of_copies, edition, production_year;
}library[999];

void add_user()
{
	cout << "sign up : \n";
	cout << "------------ \n";

	cout << "username : ";
	cin >> user[user_index].username;

	while (true)
	{
		//this bool to check if the username is used or not
		bool used = 0;
		for (int i = 0;i < user_index;i++)
		{
			if (user[user_index].username == user[i].username)
			{
				used = 1;
				break;
			}
		}
		if (used)
		{
			cout << "this username is used try again \n";
			cin >> user[user_index].username;
		}
		else
		{
			break;
		}
	}

	cout << "password : ";
	cin >> user[user_index].password;
	cout << "name : ";
	cin.ignore();
	getline(cin, user[user_index].name);
	cout << "email : ";
	cin >> user[user_index].email;
	cout << "acount type (student/guest) : ";
	cin >> user[user_index].account_type;

	while (user[user_index].account_type != "student"&& user[user_index].account_type != "guest")
	{
		cout << "invaild account type try again \n";
		cout << "acount type (student/guest) : ";
		cin >> user[user_index].account_type;
	}

	user[user_index].id = user_index + 1;

	cout << "number of contacts (min 1, max 3) : ";
	cin >> user[user_index].number_of_contacts;

	while (user[user_index].number_of_contacts < 1 || user[user_index].number_of_contacts > 3)
	{
		cout << "invaild number of contacts try again \n";
		cout << "number of contacts (min 1, max 3) : ";
		cin >> user[user_index].number_of_contacts;
	}

	for (int i = 0;i < user[user_index].number_of_contacts;i++)
	{
		cout << "contact number : ";
		cin >> user[user_index].contact[i];
	}
	cout << "enter the curent date \n";
	cout << "day : ";
	cin >> user[user_index].creation_date.day;
	cout << "month : ";
	cin >> user[user_index].creation_date.month;
	cout << "year : ";
	cin >> user[user_index].creation_date.year;
	user[user_index].creation_date.total_days = user[user_index].creation_date.day +
		user[user_index].creation_date.month * 30 + user[user_index].creation_date.year * 365;

	cout << "the user added succufly \n";
	user_index++;
	system("pause");
	system("CLS");
}

void add_book()
{
	cout << "the title : ";
	cin.ignore();
	getline(cin, library[book_index].title);
	cout << "category : ";
	getline(cin, library[book_index].category);
	cout << "the edition number : ";
	cin >> library[book_index].edition;
	cout << "number of copies : ";
	cin >> library[book_index].number_of_copies;
	cout << "the production year : ";
	cin >> library[book_index].production_year;
	cout << "the book added succufly \n";
	book_index++;
	system("pause");
	system("CLS");
}

void search_book()
{
	string title;
	int production_year;
	//this bool to check if the book exist or not
	bool exist = 0;
	cout << "(1)search by title \n";
	cout << "(2)search by production year \n";
	int select;
	cin >> select;
	if (select == 1)
	{
		system("CLS");
		cout << "the title : ";
		cin.ignore();
		getline(cin, title);
	}

	else if (select == 2)
	{
		system("CLS");
		cout << "the production year : ";
		cin >> production_year;
	}
	system("CLS");
	for (int i = 0;i < book_index;i++)
	{
		if (title == library[i].title || production_year == library[i].production_year)
		{
			cout << "title : " << library[i].title << endl;
			cout << "category : " << library[i].category << endl;
			cout << "edition number : " << library[i].edition << endl;
			cout << "the production year : " << library[i].production_year << endl;
			cout << "the number of copies : " << library[i].number_of_copies << endl;
			cout << "-------------------------------------------- \n";
			exist = 1;
		}
	}
	if (!exist)
	{
		cout << "the book wasn't found \n";
	}
	system("pause");
	system("CLS");
}

void buy_book()
{
	string title;
	//this bool to check if the book exist or not
	bool exist = 0;

	cout << "title : ";
	cin.ignore();
	getline(cin, title);

	for (int i = 0;i < book_index;i++)
	{
		if (library[i].title == title && library[i].number_of_copies > 0)
		{
			cout << "the operation succeed \n";
			library[i].number_of_copies--;
			exist = 1;
			break;
		}
	}
	if (!exist)
	{
		cout << "the book wasn't found \n";
	}
	system("pause");
	system("CLS");
}

void report()
{
	int day, month, year, total_days;
	//this bool check if there's user register in the last 7 days or not
	bool exist = 0;
	cout << "enter the curent date \n";
	cout << "day : ";
	cin >> day;
	cout << "month : ";
	cin >> month;
	cout << "year : ";
	cin >> year;
	total_days = day + month * 30 + year * 365;

	system("CLS");

	for (int i = 0;i < user_index;i++)
	{

		if (total_days - user[i].creation_date.total_days <= 7)
		{
			cout << "username : " << user[i].username << endl;
			cout << "password : " << user[i].password << endl;
			cout << "email : " << user[i].email << endl;
			cout << "id :" << user[i].id << endl;
			cout << "account type :" << user[i].account_type << endl;
			cout << "the creation date : " << user[i].creation_date.day
				<< "/" << user[i].creation_date.month << "/"
				<< user[i].creation_date.year << endl;
			cout << "number of contacts :" << user[i].number_of_contacts << endl;
			for (int j = 0;j < user[i].number_of_contacts;j++)
			{
				cout << user[i].contact[j] << endl;
			}
			cout << "--------------------------------\n";
			exist = 1;
		}
	}
	if (!exist)
	{
		cout << "there is no new users in the last 7 days \n";
	}
	system("pause");
	system("CLS");
}

//account x the account the user logged in with
void open(account x)
{
	int select;
	cout << "enter the number of the operation you want : \n";
	cout << "--------------------------------------------- \n";
	cout << "(1)add user \n";
	cout << "(2)add a book \n";
	cout << "(3)search for a book \n";
	cout << "(4)buy a book (staff only) \n";
	cout << "(5)report of the new users (staff only) \n";
	cout << "(6)log out \n";
	cin >> select;

	switch (select)
	{
	case 1:
		system("CLS");
		add_user();
		break;
	case 2:
		system("CLS");
		add_book();
		break;
	case 3:
		system("CLS");
		search_book();
		break;
	case 4:
		system("CLS");
		//checking if the account type is staff
		if (x.account_type == "staff")
		{
			buy_book();
		}
		else
		{
			cout << "only staff can use this option \n";
		}
		break;
	case 5:
		system("CLS");
		//checking if the account type is staff
		if (x.account_type == "staff")
		{
			report();
		}
		else
		{
			cout << "only staff can use this option \n";
		}
		break;
	case 6:
		return;
		break;
	default:
		cout << "please select a valid option \n";
		break;
	}
	//make sure that the user still logged in after choosing the operation
	open(x);
}

void log_in()
{
	cout << "login in : \n";
	cout << "---------- \n";

	string username, password;
	cout << "username : ";
	cin >> username;
	cout << "password : ";
	cin >> password;
	//this bool check if there's account with the same username and password
	bool vaild = 0;
	for (int i = 0;i < user_index;i++)
	{
		if (username == user[i].username && password == user[i].password)
		{
			vaild = 1;
			system("pause");
			system("CLS");
			open(user[i]);
		}
	}
	if (!vaild)
	{
		cout << "the username or password is wrong \n";
		log_in();
	}
}

int main()
{
	//this code for the color of the background and the text of the console
	system("COLOR f0");

	//the information of the staff accounts
	user[0].username = "admin1";
	user[0].password = "admin1";
	user[0].account_type = "staff";
	user[1].username = "admin2";
	user[1].password = "admin2";
	user[1].account_type = "staff";
	user[2].username = "admin3";
	user[2].password = "admin3";
	user[2].account_type = "staff";
	user[3].username = "admin4";
	user[3].password = "admin4";
	user[3].account_type = "staff";

	log_in();
	return(0);
}