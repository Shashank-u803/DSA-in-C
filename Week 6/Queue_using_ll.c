//WAP to Implement Single Link List to simulate Queue Operations.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=value;
    node->next=NULL;
    return node;
}

struct Node *front=NULL,*rear=NULL;

void enqueue(int value){
    struct Node*newNode=createNode(value);
    if(front==NULL && rear==NULL){
        front=newNode;
        rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}

void deque(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty");
        return;
    }
    struct Node*temp=front;
    front=front->next;
    free(temp);
}

void front_(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty");
        return;
    }
    printf("front element:%d\n",front->data);
}

void rear_(){
   if(front==NULL && rear==NULL){
        printf("Queue is empty");
        return;
    }
    printf("rear element:%d\n",rear->data); 
}

void display(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty");
        return;
    }
    for(struct Node*temp=front;temp!=NULL;temp=temp->next){
        printf("%d,",temp->data);
    }
    printf("\n");
}

int main(){
    for(int i=1;i<16;i++){
        enqueue(i);
    }
    deque();
    deque();
    front_();
    rear_();
    display();
    return 0;
}
