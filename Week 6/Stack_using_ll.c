// 6b) WAP to Implement Single Link List to simulate Stack Operations.
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=value;
    node->next=NULL;
    return node;
}

struct Node* top=NULL;

void push(int data){
    struct Node* newNode=createNode(data);
    newNode->next=top;
    top=newNode;
}

void pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node*temp=top;
    top=top->next;
    free(temp);
}

void peek(){
    if(top==NULL){
        printf("Empty stack!\n");
        return;
    }
    printf("Peek element:%d\n",top->data);
}

void display(){
    if(top==NULL){
        printf("Empty stack\n");
        return;
    }
    for(struct Node*temp=top;temp!=NULL;temp=temp->next){
        printf("%d,",temp->data);
    }
    printf("\n");
}

int main(){
    for(int i=15;i>0;i--){
        push(i);
    }
    pop();
    pop();
    display();
    return 0;
}
