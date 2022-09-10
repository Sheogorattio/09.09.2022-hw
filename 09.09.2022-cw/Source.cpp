#include <iostream>
using namespace std;


class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p); // реализовать делегирование!!!
	void Print();
	~Book();
};

Book::Book(const char* n) {
	cout << "book construct(1 param)\n";
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Book::Book(const char* n, int p):Book(n) 
{
	cout << "book construct(2 param)\n";
	pages = p;
}
void Book::Print() {
	cout << "b_name: " << name << endl << "b_pages: " << pages << endl;
}
Book::~Book() {
	delete[] name;
}

class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student() :step(0), book(nullptr, 0)
	{

	}
	Student(const char* n, double st, const char* bookName, int bookPages);// использовать инициализаторы!!!
	~Student();
	void Print();
};

Student::Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages)
{
	cout << "student init\n";
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Student::~Student() {
	delete[] name;
}
void Student::Print() {
	cout << "name: " << name << endl << "step: " << step << endl;
	book.Print();
}


int main() {
	Student obj("student name", 2000.0, "book name", 800);
	obj.Print();
	system("pause");
}