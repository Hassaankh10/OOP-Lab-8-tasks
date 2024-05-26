#include<iostream>
using namespace std;
class Animal
{
private:
    int age;
    string size;
public:
    Animal();
    Animal(int a, string s);
    int getAge() const{
        return age;
    };
    string getSize() const{
        return size;
    }
    void setAge(int a){
        age=a;
    }
    void setSize(string s){
        size=s;
    }
};
Animal::Animal()
{
    age=0;
    size="";
}
Animal::Animal(int a, string s){
    age=a;
    size=s;
}
class Dog: public Animal
{
private:
    string breed;
public:
    Dog();
    Dog(int a, string s, string b);
    string getBreed() const{
        return breed;
    }
    void setBreed(string b){
        breed=b;
    }
    void Display();

};

Dog::Dog(): Animal(){
    breed="";
}

Dog::Dog(int a, string s, string b): Animal(a,s){
breed=b;
}
class Cat: public Animal{
private:
int NumberOfLives;
public:
    Cat();
    Cat(int a, string s, int n);
    int getNumberOfLives() const{
        return NumberOfLives;
    }
    void setNumberOfLives(int n){
        NumberOfLives=n;
    }
    void Display();
};
Cat::Cat(): Animal(){
NumberOfLives=0;
}
Cat::Cat(int a, string s, int n): Animal(a,s){
NumberOfLives=n;
}
void Cat::Display(){
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Size: "<<getSize()<<endl;
    cout<<"Number of Lives: "<<getNumberOfLives()<<endl;
}
void Dog::Display(){
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Size: "<<getSize()<<endl;
    cout<<"Number of Lives: "<<getBreed()<<endl;
}
int main(){
Dog d(1,"small","lab");
d.Display();
Cat c(2,"medium",9);
c.Display();
return 0;
}