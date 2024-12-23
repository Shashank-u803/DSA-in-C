/*WAP to Implement doubly link list with primitive
operations
a) Create a doubly linked list.
b) Insert a new node to the left of the node.
c) Delete the node based on a specific value
d) Display the contents of the list*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

struct Node*createNode(int value){
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void insert_at_begin(struct Node**head,struct Node**tail,int value){
    struct Node*node=createNode(value);
    if(*head==NULL){
        *head=*tail=node;
        return;
    }
    node->next=*head;
    (*head)->prev=node;
    *head=node;
}

void insert_at_end(struct Node**head,struct Node**tail,int value){
    struct Node*node=createNode(value);
    if(*head==NULL){
        *head=*tail=node;
        return;
    }
    (*tail)->next=node;
    node->prev=*tail;
    *tail=node;
}

void insert_at_pos(struct Node**head,struct Node**tail,int pos,int value){
    struct Node*node=createNode(value);
    if(*head==NULL || pos==1){
        insert_at_begin(head,tail,value);
        return;
    }
    if(pos<=0){
        printf("Invalid position\n");
        return;
    }
    struct Node* temp=*head;
    for(int i=1;i<pos-1;i++){
        if(temp==NULL){
            printf("Position out of bounds\n");
            free(node);
            return;
        }
        temp=temp->next;
    }

    if(temp->next==NULL){
        insert_at_end(head,tail,value);
        return;
    }
    node->next=temp->next;
    node->prev=temp;
    temp->next->prev=node;
    temp->next=node;
}

void delete_front(struct Node**head,struct Node**tail){
    if(*head==NULL){
        printf("linked list is empty\n");
        return;
    }
    if(*head==*tail){
        struct Node*temp=*head;
        *head=*tail=NULL;
        free(temp);
        return;
    }
    struct Node*temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void delete_end(struct Node**head,struct Node**tail){
    if(*head==NULL){
        printf("linked list is empty\n");
        return;
    }
    if(*head==*tail){
        struct Node*temp=*head;
        *head=*tail=NULL;
        free(temp);
        return;
    }
    struct Node*temp=*tail;
    (*tail)=(*tail)->prev;
    (*tail)->next=NULL;
    free(temp);
}

void delete_at_pos(struct Node**head,struct Node**tail,int pos){
    if(*head==NULL){
        printf("linked list is empty\n");
        return;
    }
    if(pos<=0){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        delete_front(head,tail);
        return;
    }
    struct Node*temp=*head;
    for(int i=1;i<pos-1;i++){
        if(temp->next==NULL){
            printf("Position out of bounds\n");
            return;
        }
        temp=temp->next;
    }
    if(temp->next==*tail){
        delete_end(head,tail);
    }
    struct Node*curr=temp->next;
    temp->next=curr->next;
    curr->next->prev=temp;
    free(curr);
}

void search(struct Node**head,int ele){
    struct Node*temp=*head;
    int i=1;
    if(*head==NULL){
        printf("linked list is empty\n");
        return;
    }
    while(temp!=NULL){
        if(temp->data==ele){
            printf("Element %d found in position %d\n",ele,i);
            return;
        }
        i++;
        temp=temp->next;
    }
    printf("Element %d not found\n",ele);
}

void display(struct Node**head){
    if(*head==NULL){
        printf("linked list is empty\n");
        return;
    }
    printf("Null->");
    struct Node*temp=*head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL(tail)\n");
}

void reverse_print(struct Node**tail){
    if(*tail==NULL){
        printf("linked list is empty\n");
        return;
    }
    struct Node*temp=*tail;
    printf("NULL<-");
    while(temp!=NULL){
        printf("%d<-",temp->data);
        temp=temp->prev;
    }
    printf("NULL(head)\n");
}

int main(){
    struct Node *head=NULL,*tail=NULL;
    insert_at_begin(&head,&tail,10);
    display(&head);
    insert_at_begin(&head,&tail,5);
    display(&head);
    insert_at_end(&head,&tail,15);
    display(&head);
    insert_at_end(&head,&tail,20);
    insert_at_end(&head,&tail,25);
    insert_at_end(&head,&tail,30);
    insert_at_end(&head,&tail,35);
    insert_at_end(&head,&tail,40);
    display(&head);
    insert_at_pos(&head,&tail,2,60);
    display(&head);
    insert_at_pos(&head,&tail,80,6);
    delete_front(&head,&tail);
    display(&head);
    delete_end(&head,&tail);
    display(&head);
    delete_at_pos(&head,&tail,3);
    display(&head);
    delete_at_pos(&head,&tail,15);
    search(&head,30);
    search(&head,100);
    display(&head);
    reverse_print(&tail);
    return 0;
}
