#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;  // Initialize top as NULL

// Function prototypes
void push();
void pop();
void display();
int isEmpty();

int main() {
    int choice;
    printf("STACK IMPLEMENTATION USING LINKED LIST\n");
    do {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push() {
    int value;
    printf("Enter a value to be pushed: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));  // Create a new node
    if (newNode == NULL) {
        printf("Memory allocation failed! Stack Overflow.\n");
        return;
    }
    newNode->data = value;  // Set the data of the new node
    newNode->next = top;  // Point the new node to the current top node
    top = newNode;  // Update the top pointer to the new node
    printf("%d pushed onto stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("STACK UNDERFLOW\n");
        return;
    }
    Node* temp = top;  // Store the top node in a temporary variable
    printf("The popped element is %d\n", top->data);
    top = top->next;  // Update the top pointer to the next node
    free(temp);  // Free the memory of the popped node
}

// Function to display the stack
void display() {
    if (isEmpty()) {
        printf("EMPTY STACK\n");
        return;
    }
    Node* temp = top;
    printf("ELEMENTS IN THE STACK:\n");
    while (temp != NULL) {
        printf("Data: %d, Address: %p\n", temp->data, (void*)&temp->data);  
        temp = temp->next;  // Move to the next node
    }
    printf("\n");
}