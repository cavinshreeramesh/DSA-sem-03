#include <iostream>

using namespace std;

struct customer{
    int cust_id;
    char name[100];
    long int phone_no;
    int points;
}people[3];

int main()
{
    struct customer person1;
    cout<<"Enter name: ";
    cin>>person1.name;
    cout<<"enter phone no.: ";
    cin>>person1.phone_no;
    person1.points=450;
    person1.cust_id=121;
    cout<<person1.name<<" has "<<person1.points<<" points"<<endl;
    cout<<"Enter name: ";
    cin>>people[2].name;
    cout<<"points of "<<people[2].name<<" before assigning value: "<<people[2].points<<endl;
    people[2].points=person1.points;
    cout<<"points of "<<people[2].name<<" after assigning value: "<<people[2].points<<endl;
    if(person1.points==people[2].points){
        cout<<person1.name<<"'s points = "<<people[2].name<<"'s points"<<endl;
    }else{
        cout<<"points not equal";
    }
    return 0;
}