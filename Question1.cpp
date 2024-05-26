#include <iostream>
using namespace std;

class Employee
{
public:
    string Name;
    int age, number;
    virtual void display()
    {
        cout << Name << endl
             << age << endl
             << number << endl;
    }
};

class Manager : public Employee
{
public:
    string title;
    int clubdues;
    void display() override
    {
        cout << "Manager" << endl;
        Employee::display();
        cout << clubdues << endl
             << title << endl;
    }
};

class Scientist : public Employee
{
public:
    string title, publication;
    void display() override
    {
        cout << "Scientist" << endl;
        Employee::display();
        cout << title << endl
             << publication << endl;
    }
};

class Laborer : public Employee
{
public:
    string title;
    void display() override
    {
        cout << "Laborer" << endl;
        Employee::display();
        cout << title << endl;
    }
};

int main()
{
    Manager m1;
    m1.Name = "John Doe";
    m1.age = 30;
    m1.number = 123;
    m1.title = "Software Engineer";
    m1.clubdues = 50;
    m1.display();

    Scientist s1;
    s1.Name = "Jane Doe";
    s1.age = 28;
    s1.number = 234;
    s1.title = "Physicist";
    s1.publication = "Quantum Physics";
    s1.display();

    Laborer l1;
    l1.Name = "Mike Smith";
    l1.age = 25;
    l1.number = 345;
    l1.title = "Construction Worker";
    l1.display();

    return 0;
}