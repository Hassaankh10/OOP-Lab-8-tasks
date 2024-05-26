/*This is the explanation of hybrid inheritance.
In hybrid inheritance, a class is derived from more than one base class. This means it combines features of both single inheritance (where a derived class inherits from only one base class) and multiple inheritance (where a derived class inherits from more than one base class). In this scenario, hybrid inheritance allows us to model different types of employees in the university management system by inheriting attributes and behaviors from both "Faculty" and "AdministrativeStaff" classes into the "TeachingAssistant" class.*/
#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    string name;
    int age;
    int salary;
    int empid;

public:
    Employee(string _name, int _age, int _salary, int _empid) : name(_name), age(_age), salary(_salary), empid(_empid) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    int getSalary() const { return salary; }
    int getEmpID() const { return empid; }
};

class Faculty : public Employee
{
protected:
    string department;
    string teaching_subjects;

public:
    Faculty(string _name, int _age, int _salary, int _empid, string _department, string _teaching_subjects)
        : Employee(_name, _age, _salary, _empid), department(_department), teaching_subjects(_teaching_subjects) {}
    string getDepartment() const { return department; }
    string getTeachingSubjects() const { return teaching_subjects; }
};

class AdministrativeStaff : public Employee
{
protected:
    string position;
    string office_location;

public:
    AdministrativeStaff(string _name, int _age, int _salary, int _empid, string _position, string _office_location)
        : Employee(_name, _age, _salary, _empid), position(_position), office_location(_office_location) {}
    string getPosition() const { return position; }
    string getOfficeLocation() const { return office_location; }
};

class TeachingAssistant : public Faculty, public AdministrativeStaff
{
protected:
    string section;
    string current_semester;

public:
    TeachingAssistant(string _name, int _age, int _salary, int _empid, string _department, string _teaching_subjects,
                      string _position, string _office_location, string _section, string _current_semester)
        : Faculty(_name, _age, _salary, _empid, _department, _teaching_subjects),
          AdministrativeStaff(_name, _age, _salary, _empid, _position, _office_location),
          section(_section),
          current_semester(_current_semester) {}

    string getSection() const { return section; }
    string getCurrentSemester() const { return current_semester; }
};

int main()
{
    TeachingAssistant ta("John Doe", 25, 25000, 1001, "Computer Science", "Programming", "Assistant", "Building A", "Section A", "Fall 2024");
    cout << "Name: " << ta.getName() << endl;
    cout << "Age: " << ta.getAge() << endl;
    cout << "Salary: " << ta.getSalary() << endl;
    cout << "Employee ID: " << ta.getEmpID() << endl;
    cout << "Department: " << ta.getDepartment() << endl;
    cout << "Teaching Subjects: " << ta.getTeachingSubjects() << endl;
    cout << "Position: " << ta.getPosition() << endl;
    cout << "Office Location: " << ta.getOfficeLocation() << endl;
    cout << "Section: " << ta.getSection() << endl;
    cout << "Current Semester: " << ta.getCurrentSemester() << endl;

    return 0;
}
