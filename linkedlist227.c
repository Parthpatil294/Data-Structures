

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void insertBefore(struct Node** head, int newData, int targetData) {
    struct Node* newNode = createNode(newData);
    struct Node* temp = *head;


    if (*head == NULL) {
        *head = newNode;
        return;
    }


    while (temp != NULL && temp->data != targetData) {
        temp = temp->next;
    }


    if (temp != NULL) {
        newNode->next = temp;
        newNode->prev = temp->prev;


        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        } else {
            *head = newNode;
        }
        temp->prev = newNode;
    } else {
        printf("Node with value %d not found.\n", targetData);
    }
}


void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;


    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }


    if (temp != NULL) {

        if (temp->prev == NULL && temp->next == NULL) {
            *head = NULL;
        }

        else if (temp->prev == NULL) {
            *head = temp->next;
            (*head)->prev = NULL;
        }

        else if (temp->next == NULL) {
            temp->prev->next = NULL;
        }

        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        free(temp);
    } else {
        printf("Node with value %d not found.\n", value);
    }
}


void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;


    displayList(head);


    insertBefore(&head, 10, 0);
    insertBefore(&head, 20, 10);
    insertBefore(&head, 30, 10);


    displayList(head);


    deleteNode(&head, 20);


    displayList(head);


    deleteNode(&head, 100);

    return 0;
}
