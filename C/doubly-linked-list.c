#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    struct Node* next;
    struct Node* prev;
    element data;

} Node;

Node* createNode(element data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;

    return newNode;
}

Node* insertFirst(Node* head, element data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node* insertLast(Node* head, element data) {
    Node* newNode = createNode(data);
    Node* temp = head;

    if (head->next != NULL) {
        do {
            temp = temp->next;
        } while (temp->next != NULL);
    }

    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

Node* deleteFirst(Node* head) {
    head = head->next;
    head->prev->next = NULL;
    free(head->prev);
    head->prev = NULL;

    return head;
}

Node* deleteLast(Node* head) {
    Node* temp = head;

    if (head->next != NULL) {
        do {
            temp = temp->next;
        } while (temp->next != NULL);
    }

    temp = temp->prev;
    temp->next->prev = NULL;
    free(temp->next);
    temp->next = NULL;

    return  head;
}

int main(int argc, char* argv[]) {
    Node* head = createNode(30);

    head = insertFirst(head, 20);
    head = insertFirst(head, 10);

    head = insertLast(head, 40);
    head = insertLast(head, 50);

    head = deleteFirst(head);
    head = deleteLast(head);

    return 0;
}
