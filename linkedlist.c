#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// a) Function to create a linked list by inserting elements at the end
void createList(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// b1) Function to delete the first element
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    *head = (*head)->next;
    free(temp);
}

// b2) Function to delete a specified element by value
void deleteSpecified(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;

    // If the head node is the element to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the element was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
}

// b3) Function to delete the last element
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;

    // If there's only one element
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    // Find the second last node
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// c) Function to display the contents of the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Create list (insert at end)\n");
        printf("2. Delete first element\n");
        printf("3. Delete specified element\n");
        printf("4. Delete last element\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                createList(&head, data);
                break;
            case 2:
                deleteFirst(&head);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteSpecified(&head, data);
                break;
            case 4:
                deleteLast(&head);
                break;
            case 5:
                printf("Linked List: ");
                displayList(head);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
