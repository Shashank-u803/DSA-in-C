/*  WAP to simulate the working of a circular queue of
integers using an array. Provide the following operations:
Insert, Delete & Display
The program should print appropriate messages for
queue empty and queue overflow conditions */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

// Function to check if the queue is full
int isFull(int front, int rear) {
    if ((rear + 1) % MAX == front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(int front, int rear) {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element into the queue
void insert(int queue[], int *front, int *rear, int value) {
    if (isFull(*front, *rear)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // If the queue is empty
    if (*front == -1) {
        *front = *rear = 0;
    } else {
        // Circular increment of rear
        *rear = (*rear + 1) % MAX;
    }

    queue[*rear] = value;
    printf("%d inserted into the queue\n", value);
}

// Function to delete an element from the queue
void delete(int queue[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue Underflow! No element to delete\n");
        return;
    }

    int deletedValue = queue[*front];
    printf("%d deleted from the queue\n", deletedValue);

    // If there is only one element left in the queue
    if (*front == *rear) {
        *front = *rear = -1; // Queue is now empty
    } else {
        // Circular increment of front
        *front = (*front + 1) % MAX;
    }
}

// Function to display the elements of the queue
void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    int queue[MAX]; // Queue array
    int front = -1, rear = -1; // Initialize front and rear to -1

    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(queue, &front, &rear, value);
                break;

            case 2:
                delete(queue, &front, &rear);
                break;

            case 3:
                display(queue, front, rear);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
