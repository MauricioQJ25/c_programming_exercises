#include <stdio.h>
#include <stdlib.h>

typedef struct  Node{
    int data;
    struct Node* next;
} Node;

Node* push(Node* head, int newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* current = head;
    if (newNode != NULL){
        newNode->data = newData;
        newNode->next = NULL;

        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

void printList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf(" NULL \n");
}

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current != NULL){
        //store next 
        next = current->next;
        // new state pointers
        current->next = prev;
        // move pointers
        prev = current;
        current = next;
    }
    return head = prev;
}


int main(int argc, char* argv[]){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    head = push(head, 11);
    head = push(head, 12);
    head = push(head, 13);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}