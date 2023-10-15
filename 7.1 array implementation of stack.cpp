#include <bits/stdc++.h>
using namespace std;

int top=-1;
int stk[10];

bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

int isFull(){
    if(top==9)
        return true;
    else
        return false;
}

void push(int val){
    if(isFull()){
        cout<<"stack overflow\ncannot push\n";
    }else{
        top++;
        stk[top]=val;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"stack underflow\ncannot pop\n";
    }else{
        top--;
    }
}

int peek(){
    if(isEmpty()){
        return -1;
    }else{
        return stk[top];
    }
}

void display(){
    if(isEmpty()){
        cout<<"empty stack\n";
    }else{
        for(int i=top;i>=0;i--){
            cout<<stk[i]<<endl;
        }
    }
}


int main()
{
    cout<<"stack operation:\n 1. is empty\n 2. is full\n 3. push\n 4. pop\n 5. peek \n 6. display\n";
    int choice,t=1,value;
    while(t){
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"stack is empty: "<<isEmpty()<<endl;
                break;
            case 2:
                cout<<"stack is full: "<<isFull()<<endl;
                break;
            case 3:
                cout<<"enter value to push: ";
                cin>>value;
                push(value);
                break;
            case 4:
                pop();
                break;
            case 5:
                cout<<peek()<<endl;
                break;
            case 6:
                display();
                break;
            default:
                t--;
        }
    }
    return 0;
}

