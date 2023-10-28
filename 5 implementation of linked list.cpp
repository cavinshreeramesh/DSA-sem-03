#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
} *start=NULL;

void insert(){
    struct node *temp=(struct node*)malloc(sizeof(struct node)),*ptr;
    ptr=start;
    cin>>temp->data;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display(){
    struct node *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data;
        ptr=ptr->next;
    }
    cout<<endl;
}

void delete_node_value(int value){
    struct node *ptr,*temp;
    ptr=start;
    if(start->data==value){
        temp=start;
        start=start->next;
        free(temp);
    }else{
        while(ptr->data!=value){
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                cout<<"value not in list.\n";
                return;
            }
        }
        temp->next=ptr->next;
        free(ptr);
    }
}

void delete_node_index(int index){
    struct node *ptr;
    ptr=start;
    for(int i=0;i<index;i++){
        ptr=ptr->next;
        if(ptr==NULL){
            return;
        }
    }
    delete_node_value(ptr->data);
}

void delete_after(int value){
    struct node *ptr;
    ptr=start;
    while(ptr->data!=value){
        ptr=ptr->next;
        if(ptr==NULL){
            cout<<"value not in list.\n";
            return;
        }
    }
    if(ptr->next==NULL){
        cout<<"No element exists after it.";
        return;
    }
    delete_node_value(ptr->next->data);
}

void delete_before(int value){
    struct node *ptr,*temp;
    ptr=start;
    while(ptr->data!=value){
        temp=ptr;
        ptr=ptr->next;
        if(ptr==NULL){
            cout<<"value not in list.\n";
            return;
        }
    }
    if(ptr==start){
        cout<<endl<<"No element exists before it.";
        return;
    }
    delete_node_value(temp->data);
}

void insert_after(int value,int after){
    struct node *ptr,*temp=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    while(ptr->data!=after){
        ptr=ptr->next;
        if(ptr==NULL){
            cout<<after<<" doesn't exist in list";
            return;
        }
    }
    temp->data=value;
    temp->next=ptr->next;
    ptr->next=temp;

}

void insert_before(int value,int before){
    struct node *ptr,*temp=(struct node*)malloc(sizeof(struct node));
    ptr=start;
    temp->data=value;
    if(ptr->data==before){
        temp->next=start;
        start=temp;
    }else{
        while(ptr->next->data!=before){
            ptr=ptr->next;
            if(ptr->next==NULL){
                cout<<before<<" doesnt exist in list";
                return;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

int main()
{
    int n,t=1;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    while(t){
        cout<<"\nMENU:\n1. display\n2. insert\n3. insert after\n4. insert before\n5. delete value\n6. delete index\n7. delete after\n8. delete before\n  Press any other number to exit.\n";
        int choice,value,after,before;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            display();
        }else if(choice==2){
            insert();
        }else if(choice==3){
            cout<<"enter value to insert after: ";
            cin>>after;
            cout<<"enter value to insert after "<<after<<": ";
            cin>>value;
            insert_after(value,after);
        }else if(choice==4){
            cout<<"enter value to insert before: ";
            cin>>before;
            cout<<"enter value to insert after "<<before<<": ";
            cin>>value;
            insert_before(value,before);
        }else if(choice==5){
            cout<<"enter value to delete: ";
            cin>>value;
            delete_node_value(value);
        }else if(choice==6){
            cout<<"enter index to delete: ";
            cin>>value;
            delete_node_index(value);
        }else if(choice==7){
            cout<<"enter value to delete after: ";
            cin>>value;
            delete_after(value);
        }else if(choice==8){
            cout<<"enter value to delete before: ";
            cin>>value;
            delete_before(value);
        }else{
            cout<<"Exiting program";
            t--;
        }
    }
    return 0;
}



