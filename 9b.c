#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->array = (int*) malloc(capacity * sizeof(int));
    return q;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == q->capacity - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

// Function to enqueue an element
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->array[q->rear] = data;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->array[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return data;
}

// Function to get the front element
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->array[q->front];
}

// Function to get the rear element
int rear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->array[q->rear];
}

// Function to get the size of the queue
int size(Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

int main() {
    Queue* q = createQueue(5);
    printf("Implementation of Queue using Array \n");
    int choice, data;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                data = front(q);
                if (data != -1) {
                    printf("Front: %d\n", data);
                }
                break;
            case 4:
                data = rear(q);
                if (data != -1) {
                    printf("Rear: %d\n", data);
                }
                break;
            case 5:
                printf("Size: %d\n", size(q));
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}