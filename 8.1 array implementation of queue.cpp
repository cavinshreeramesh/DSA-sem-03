#include <bits/stdc++.h>
using namespace std;

int Queue[10];
int size=0;

bool isEmpty(){
    if(size==0)
        return true;
    else
        return false;
}

int isFull(){
    if(size==10)
        return true;
    else
        return false;
}

void Enqueue(int val){
    if(isFull()){
        cout<<"queue overflow\n";
    }else{
        Queue[size]=val;
        size++;
    }
}

void Dequeue(){
    if(isEmpty()){
        cout<<"queue underflow\n";
    }else{
        for(int i=0;i<size;i++){
            Queue[i]=Queue[i+1];
        }
        size--;
    }
}

int Size(){
    return size;
}

void display(){
    if(isEmpty()){
        cout<<"empty queue\n";
    }else{
        for(int i=0;i<size;i++){
            cout<<Queue[i]<<" ";
        }
        cout<<" "<<endl;
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
                display();
                break;
            default:
                t--;
        }
    }
    return 0;
}





