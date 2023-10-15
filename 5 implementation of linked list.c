#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
} *start=NULL;

void insert(){
    struct node *temp=(struct node*)malloc(sizeof(struct node)),*ptr;
    ptr=start;
    scanf("%d",&temp->data);
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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
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
                printf("value not in list.\n");
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
            printf("value not in list.\n");
            return;
        }
    }
    if(ptr->next==NULL){
        printf("No element exists after it.");
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
            printf("value not in list.\n");
            return;
        }
    }
    if(ptr==start){
        printf("No element exists before it.");
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
            printf("%d doesn't exist in list",after);
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
                printf("%d doesnt exist in list",before);
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
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        insert();
    }
    while(t){
        printf("\nMENU:\n1. display\n2. insert\n3. insert after\n4. insert before\n5. delete value\n6. delete index\n7. delete after\n8. delete before\n  Press any other number to exit.\n");
        int choice,value,after,before;
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1){
            display();
        }else if(choice==2){
            insert();
        }else if(choice==3){
            printf("enter value to insert after: ");
            scanf("%d",&after);
            printf("enter value to insert after %d: ",after);
            scanf("%d",&value);
            insert_after(value,after);
        }else if(choice==4){
            printf("enter value to insert before: ");
            scanf("%d",&before);
            printf("enter value to insert after %d: ",before);
            scanf("%d",&value);
            insert_before(value,before);
        }else if(choice==5){
            printf("enter value to delete: ");
            scanf("%d",&value);
            delete_node_value(value);
        }else if(choice==6){
            printf("enter index to delete: ");
            scanf("%d",&value);
            delete_node_index(value);
        }else if(choice==7){
            printf("enter value to delete after: ");
            scanf("%d",&value);
            delete_after(value);
        }else if(choice==8){
            printf("enter value to delete before: ");
            scanf("%d",&value);
            delete_before(value);
        }else{
            printf("Exiting program");
            t--;
        }
    }
    return 0;
}


