#include <iostream>
using namespace std;
class person
{
private:
    int age;

protected:
    int getage(){
        return age;
    }
    string name;
    public:
    person(string n,int a):name(n),age(a){
        age=a;
        name=n;
    }
};
class Employee
{
private:
    int empid;

protected:
    int salary;
    int getempid(){
        return empid;
    }
    public:
    Employee(int s,int eid):salary(s),empid(eid){
        salary=s;
        empid=eid;
    }
};

class Manager : virtual public person, virtual public Employee
{
private:
    string type;
    public:
    string gettype(){
        return type;
    }
    Manager(string n,int a,int  s,int eid,string t):person(n,a),Employee(s,eid){
        type=t;
    }
};
class ITManager : public Manager
{
private:
    int noOfPersons;

public:
    int getnoOfPersons(){
        return noOfPersons;
    }
    ITManager(string n,int a,int  s,int eid,string t,int np):person(n,a),Employee(s,eid),Manager(n,a,s,eid,t){
        noOfPersons=np;
    }
    void display();
};
void ITManager::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<getage()<<endl;
    cout<<"Salary: "<<salary<<endl;
    cout<<"Empid: "<<getempid()<<endl;
    cout<<"Type: "<<gettype()<<endl;
    cout<<"No of Persons: "<<noOfPersons<<endl;
}
int main()
{
    ITManager m("Raj",25,10000,1234,"Manager",10);
    m.display();
    return 0;
}
