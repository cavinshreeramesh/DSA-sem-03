#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct CQueue{
    node *head;
    node *tail;
} CQueue;

CQueue *queue=(CQueue*)malloc(sizeof(CQueue));
void enqueue(int d){
    node *ptr,*n_n=(node*)malloc(sizeof(node));
    n_n->data=d;
    if(queue->head==NULL){
        n_n->next=n_n;
        queue->head=n_n;
        queue->tail=n_n;
    }else{
        n_n->next=queue->head;
        queue->tail->next=n_n;
        queue->tail=n_n;
    }
}

void dequeue(){
    node *temp=queue->head;
    queue->head=queue->head->next;
    queue->tail->next=queue->head;
    free(temp);
}

void Josephus_solution(int k){
    if(queue->head==queue->tail){
        cout<<"Last element left: ";
        cout<<queue->head->data;
        return;
    }
    for(int i=0;i<k-1;i++){
        queue->head=queue->head->next;
        queue->tail=queue->tail->next;
    }
    dequeue();
    Josephus_solution(k);
}

int main()
{
    int t,n,d,k;
    cout<<"Enter number of elements:";
    cin>>t;
    while(t--){
        cout<<"Enter element:";
        cin>>d;
        enqueue(d);
    }
    cout<<"Every k element should be deleted. Enter k: ";
    cin>>k;
    Josephus_solution(k);
    return 0;
}





