#include <iostream>
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
} *start=NULL;

void display(int rev){
    struct node *ptr;
    if(start==NULL){
        cout<<"list is empty\n";
        return;
    }
    ptr=start;
    if(rev==0){
    while(ptr!=NULL){
        cout<<"%d ",ptr->data;
        ptr=ptr->next;
    }
    cout<<"\n";
    }else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        while(ptr!=NULL){
            cout<<ptr->data;
            ptr=ptr->prev;
        }
        cout<<"\n";
    }
}

void insert_end(int val){
    struct node *ptr,*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(start==NULL){
        temp->prev=NULL;
        start=temp;
    }else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        temp->prev=ptr;
        ptr->next=temp;
    }
}

void insert_begin(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    if(start==NULL){
        temp->next=NULL;
    }else{
        temp->next=start;
        start->prev=temp;
    }
    start=temp;
}

void insert_at(int index,int val){
    struct node *ptr,*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    ptr=start;
    for(int i=0;i<index-1;i++){
        ptr=ptr->next;
        if(ptr==NULL){
            cout<<"invalid index";
            return;
        }
    }
    temp->next=ptr->next;
    ptr->next=temp;
}

void delete_end(){
    struct node *ptr,*temp;
    if(start==NULL){
        cout<<"list is empty\n";
    }else{
        ptr=start;
        while(ptr->next!=NULL){
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        free(ptr);
    }
}
void delete_begin(){
    struct node *ptr;
    if(start==NULL){
        cout<<"list is empty\n";
    }else{
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
}}

void delete_value(int val){
    struct node *ptr,*temp;
    if(start==NULL){
        cout<<"list is empty";
    }else{
        ptr=start;
        while(ptr->data!=val){
            temp=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                cout<<"value not in list";
                return;
            }
        }
        temp->next=ptr->next;
        free(ptr);
    }
}

int main()
{
    int t=1;
    while(t){
        cout<<"MENU: \n1. display \n2. insert end \n3. insert begin \n4. delete end \n5. delete begin \n6. insert at \n7. delete value\n  press any other key to exit\n";
        int choice,value,index;
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int c;
                cout<<"enter:\n 0->print in order\n 1->print in reverse\n";
                cin>>c;
                display(c);
                break;
            case 2:
                cout<<"enter value to insert: ";
                cin>>value;
                insert_end(value);
                break;
            case 3:
                cout<<"enter value to insert: ";
                scanf("%d",&value);
                insert_begin(value);
                break;
            case 4:
                delete_end();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                cout<<"enter index to insert at: ";
                cin>>index;
                cout<<"enter value to insert: ";
                cin>>value;
                insert_at(index,value);
                break;
            case 7:
                cout<<"enter value to delete: ";
                cin>>value;
                delete_value(value);
                break;
            default:
                cout<<"exiting menu";
                t--;
        }
    }
    return 0;
}





