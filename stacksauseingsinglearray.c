#include <stdio.h>
#define MAX 10

int arr[MAX];
int top1 = -1;      // Stack1 top
int top2 = MAX;     // Stack2 top

// Push into Stack1
void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[++top1] = x;
    printf("Pushed %d into Stack1\n", x);
}

// Push into Stack2
void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[--top2] = x;
    printf("Pushed %d into Stack2\n", x);
}

// Pop from Stack1
void pop1() {
    if (top1 == -1) {
        printf("Stack1 Underflow!\n");
        return;
    }
    printf("Popped %d from Stack1\n", arr[top1--]);
}

// Pop from Stack2
void pop2() {
    if (top2 == MAX) {
        printf("Stack2 Underflow!\n");
        return;
    }
    printf("Popped %d from Stack2\n", arr[top2++]);
}

// Display Stack1
void display1() {
    if (top1 == -1) {
        printf("Stack1 is empty!\n");
        return;
    }
    printf("Stack1 elements: ");
    for (int i = top1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Display Stack2
void display2() {
    if (top2 == MAX) {
        printf("Stack2 is empty!\n");
        return;
    }
    printf("Stack2 elements: ");
    for (int i = top2; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    push1(10);
    push1(20);
    push1(30);

    push2(100);
    push2(200);
    push2(300);

    display1();
    display2();

    pop1();
    pop2();

    display1();
    display2();

    return 0;
}
