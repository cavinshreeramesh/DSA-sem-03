#include <iostream>
using namespace std;
int list[10];
int list_size=0;
void Create() {
        int n;
        cout<<"Enter no of elements: ";
        cin>>n;
        if(n>10){
            cout<<"list overflow";
        }else{
            cout<<"Enter the elemnets: ";
            for(int i=0;i<n;i++){
                cin>>list[i];
            }
            cout<<"List created\n";
            list_size=n;
        }
    }

void Insert(){
    int pos;
    cout<<"Enter position of insertion: ";
    cin>>pos;
    if(pos>9){
        cout<<"Invalid postion";
    }else if(list_size==10){
        cout<<"list overflow";
    }else{
        for(int i=list_size-1;i>=pos;i--){
            list[i+1]=list[i];
        }
        cout<<"Enter element to insert: ";
        cin>>list[pos];
        list_size++;
        cout<<"Element inserted\n";
    }
}

void Delete(){
    if(list_size==0){
        cout<<"list underflow";
    }else{
        cout<<"Enter position of deletetion";
        int pos;
        cin>>pos;
        if(pos>9){
            cout<<"Invalid postion";
        }else{
            for(int i=pos+1;i<list_size;i++){
                list[i-1]=list[i];
            }
            list_size--;
            list[list_size]==0;
            cout<<"Element deleted\n";
        }
    }
}

bool Isfull(){
    if(list_size==10){
        return true;
    }else{
        return false;
    }
}

bool Isempty(){
    if(list_size==0){
        return true;
    }else{
        return false;
    }
}

void Display(){
        for(int i=0;i<list_size;i++){
            cout<<list[i]<<" ";
        }
        cout<<"\n";
}

void Search(){
    int element;
    cout<<"Enter element to searchfor: ";
    cin>>element;
    cout<<"The element "<<element<<" is at indexes: ";
    for(int i=0;i<list_size;i++){
        if(list[i]==element){
            cout<<i<<", ";
        }
    }
}
    
int main() {
    Create();
    int state=1;
    int choice=0;
    while(state!=0){
        cout<<"Menu: \n1. Insert \n2. Delete \n3. Is full \n4. Is empty \n5. Display \n6. Search";
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            Insert();
        }else if(choice==2){
            Delete();
        }else if(choice==3){
            cout<<Isfull();
        }else if(choice==4){
            cout<<Isempty();
        }else if(choice==5){
            Display();
        }else if(choice==6){
            Search();
        }
    }
    return 0;
}

