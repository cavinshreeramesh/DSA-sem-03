#include <iostream>

using namespace std;

struct parent{
    char name[100];
    int age;
};

struct student{
    char name[100];
    int age;
    struct parent *parentptr;
};

int main()
{
    struct parent p1;
    struct student s1;
    cout<<"Enter name of student: ";
    cin>>s1.name;
    cout<<"Enter age of student: ";
    cin>>s1.age;
    cout<<"Enter name of parent: ";
    cin>>p1.name;
    cout<<"Enter age of parent: ";
    cin>>p1.age;
    s1.parentptr=&p1;
    cout<<"details of student: "<<endl;
    cout<<"name: "<<s1.name<<endl;
    cout<<"age: "<<s1.age<<endl;
    cout<<"parent name: "<<s1.parentptr->name<<endl;
    cout<<"parent age: "<<s1.parentptr->age<<endl;
    return 0;
}