#include <stdio.h>
#include <stdlib.h>
struct node{
    int c;
    int p;
    struct node *next;
} *poly1=NULL,*poly2=NULL,*result=NULL;

struct node* create(struct node *start,int coeff,int power){
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->c=coeff;
    temp->p=power;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return start;
}

void display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("%dx^%d +",ptr->c,ptr->p);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->c,ptr->p);
}

struct node* add(struct node *start1,struct node *start2,struct node *result){
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    while((ptr1!=NULL)&&(ptr2!=NULL)){
        if(ptr1->p>ptr2->p){
            result=create(result,ptr1->c,ptr1->p);
            ptr1=ptr1->next;
        }else if(ptr1->p<ptr2->p){
            result=create(result,ptr2->c,ptr2->p);
            ptr2=ptr2->next;
        }else{
            result=create(result,(ptr1->c+ptr2->c),ptr1->p);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL){
        while(ptr1!=NULL){
            result=create(result,ptr1->c,ptr1->p);
            ptr1=ptr1->next;
        }
    }else if(ptr2!=NULL){
        while(ptr2!=NULL){
            result=create(result,ptr2->c,ptr2->p);
            ptr2=ptr2->next;
        }
    }
    return result;
}

int main()
{
    int n1,n2,i,c_i,p_i;
    printf("Enter no of terms of polynomial 1: ");
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        printf("enter coefficent: ");
        scanf("%d",&c_i);
        printf("enter power: ");
        scanf("%d",&p_i);
        poly1=create(poly1,c_i,p_i);
    }
    printf("Enter no of terms of polynomial 2: ");
    scanf("%d",&n2);
    for(i=0;i<n2;i++){
        printf("enter coefficent: ");
        scanf("%d",&c_i);
        printf("enter power: ");
        scanf("%d",&p_i);
        poly2=create(poly2,c_i,p_i);
    }
    display(poly1);
    display(poly2);
    result=add(poly1,poly2,result);
    display(result);
    return 0;
}

