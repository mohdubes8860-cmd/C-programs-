#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for employee node
struct Employee {
    int id;
    char name[50];
    struct Employee *prev, *next;
};

struct Employee *head = NULL;

// Function to insert at the front
void insertFront(int id, char name[]) {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("Employee inserted at the front.\n");
}

// Function to delete from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Employee *temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // If only one node
    if (temp->prev == NULL) {
        printf("Deleted Employee: %d, %s\n", temp->id, temp->name);
        free(temp);
        head = NULL;
    } else {
        printf("Deleted Employee: %d, %s\n", temp->id, temp->name);
        temp->prev->next = NULL;
        free(temp);
    }
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Employee *temp = head;
    printf("\nEmployee List (Front → End):\n");
    printf("ID\tName\n");
    while (temp != NULL) {
        printf("%d\t%s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char name[50];

    while (1) {
        printf("\n--- Employee Doubly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Delete from end\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]s", name);  // read string with spaces
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
