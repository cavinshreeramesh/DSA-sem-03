#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
} *top=NULL;

bool isEmpty(){
    if(top==NULL){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    int count=0;
    struct node *ptr=top;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    if(count==10){
        return true;
    }else{
        return false;
    }
}

void push(int val){
    if(isFull()){
        cout<<"stack overflow\ncannot push"<<endl;
    }else{
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        if(top==NULL){
            temp->next=NULL;
        }
        else{
            temp->next=top;
        }
        top=temp;
    }
}

void pop(){
    struct node *temp;
    temp=top;
    top=top->next;
    free(temp);
}

int peek(){
    if(top==NULL){
        return -1;
    }else{
        return top->data;
    }
}

void display(){
    if(top==NULL){
        cout<<"empty stack"<<endl;
    }else{
        struct node *ptr=top;
        while(ptr!=NULL){
            cout<<ptr->data<<endl;
            ptr=ptr->next;
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


