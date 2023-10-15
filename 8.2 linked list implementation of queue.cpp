#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct Queue{
    node *front;
    node *rear;
    int size=0;
} Queue;

Queue *Q=(Queue*)malloc(sizeof(Queue));

int Size(){
    return Q->size;
}

bool isEmpty(){
    if(Q->size==0){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(Q->size==10){
        return true;
    }else{
        return false;
    }
}

void Enqueue(int val){
    if(isFull()){
        cout<<"queue overflow\ncannot enqueue"<<endl;
    }else{
        node *n=(node*)malloc(sizeof(node));
        n->data=val;
        n->next=NULL;
        if(Q->size==0){
            Q->front=n;
            Q->rear=n;
        }else{
            Q->rear->next=n;
            Q->rear=n;
        }
        Q->size+=1;
    }
}

void Dequeue(){
    if(Q->size!=0){
        node *temp;
        temp=Q->front;
        Q->front=Q->front->next;
        free(temp);
    }else{
        cout<<"Queue underflow\nCannot dequeue\n";
    }
    Q->size-=1;
}

void Display(){
    
    
    
    if(isEmpty()){
        cout<<"empty queue"<<endl;
    }else{
        node *ptr=Q->front;
        while(ptr!=Q->rear){
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
        cout<<Q->rear->data<<endl;
    }
}

int main()
{
    cout<<"Queue operation:\n 1. is empty\n 2. is full\n 3. enqueue\n 4. dequeue\n 5. size \n 6. display\n";
    int choice,t=1,value;
    while(t){
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"queue is empty: "<<isEmpty()<<endl;
                break;
            case 2:
                cout<<"queue is full: "<<isFull()<<endl;
                break;
            case 3:
                cout<<"enter value to enqueue: ";
                cin>>value;
                Enqueue(value);
                break;
            case 4:
                Dequeue();
                break;
            case 5:
                cout<<Size()<<endl;
                break;
            case 6:
                Display();
                break;
            default:
                t--;
        }
    }
    return 0;
}







