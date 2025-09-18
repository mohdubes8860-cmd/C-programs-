#include <stdio.h>
#include <stdlib.h>

// Define stack node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("Pushed: %d\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Peek operation
void peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Traverse stack
void traverse() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);

    traverse();
    peek();

    pop();
    traverse();

    pop();
    traverse();

    pop();
    traverse();

    return 0;
}
