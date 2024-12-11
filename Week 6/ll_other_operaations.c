/*6a) WAP to Implement Single Link List with following
operations: Sort the linked list, Reverse the linked list,
Concatenation of two linked lists*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL)
        return;
    struct Node* i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = *head2;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 4);
    insertAtEnd(&list1, 2);

    insertAtEnd(&list2, 7);
    insertAtEnd(&list2, 6);
    insertAtEnd(&list2, 5);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    sortList(&list1);
    printf("Sorted List 1: ");
    printList(list1);

    reverseList(&list1);
    printf("Reversed List 1: ");
    printList(list1);

    concatenateLists(&list1, &list2);
    printf("Concatenated List: ");
    printList(list1);

    return 0;
}
