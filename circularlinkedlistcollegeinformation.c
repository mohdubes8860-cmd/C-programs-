#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a circular linked list node
struct College {
    int id;
    char name[50];
    struct College* next;
};

struct College* last = NULL;  // pointer to last node

// Function to insert at the front
void insertFront(int id, char name[]) {
    struct College* newNode = (struct College*)malloc(sizeof(struct College));
    newNode->id = id;
    strcpy(newNode->name, name);

    if (last == NULL) {
        // First node → points to itself
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("College inserted at the front.\n");
}

// Function to delete from the end
void deleteEnd() {
    if (last == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct College* temp = last->next;

    // Only one node
    if (last == last->next) {
        printf("Deleted College: %d, %s\n", last->id, last->name);
        free(last);
        last = NULL;
        return;
    }

    // Traverse to the node before last
    while (temp->next != last) {
        temp = temp->next;
    }

    printf("Deleted College: %d, %s\n", last->id, last->name);
    temp->next = last->next;  // link back to head
    free(last);
    last = temp;
}

// Function to display the list
void displayList() {
    if (last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct College* temp = last->next;  // start from head
    printf("\nCollege List (Circular):\n");
    printf("ID\tName\n");
    do {
        printf("%d\t%s\n", temp->id, temp->name);
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    int choice, id;
    char name[50];

    while (1) {
        printf("\n--- College Circular Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete from end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter College ID: ");
                scanf("%d", &id);
                printf("Enter College Name: ");
                scanf(" %[^\n]s", name);
                insertFront(id, name);
                break;

            case 2:
                deleteEnd();
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
