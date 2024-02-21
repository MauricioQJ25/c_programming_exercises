#include<stdio.h>
#include<stdlib.h>

//Queue 10 elements
// isEmpty
// push
// pop
// isFull
// printQueue

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;
int elements = 0;

void push(int newData){
    if( elements >= 10){
        printf("Queue is full \n");
        return;
    }
    Node* newNode = (Node *)malloc(sizeof(Node)); 
    
    if (newNode != NULL){
        newNode->data= newData;
        newNode->next = top;
        top = newNode;
        elements++;
    }
    else{
        printf("Not able to allocate memory\n");
    }
}

void printQueue(){
    Node* current = NULL;
    current = top;
    if (elements == 0){
        printf("Queue is empty \n");
        return;
    }
    else{
        printf(" top -> ");
        do{
            printf(" %d -> ", current->data);
            current = current->next;
        }while(current != NULL );
    }
    printf(" \n");
}

void pop(){
    if(elements > 0){
        Node* current = top;
        top = top->next;
        free(current);
        elements--;
    }
    else{
        printf("Queue is empty \n");
    }
}

void isFull(){
    if(elements >=10){
        printf("Queue is full \n");
        return;
    }else{
        printf("Queue is not full \n");
        return;
    }
}

void isEmpty(){
    if(elements == 0){
        printf("Queue is Empty \n");
        return;
    }else{
        printf("Queue is not Empty\n");
        return;
    }
}

int main(int argc, char*  argv[]){
    printQueue();
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);
    push(14);
    push(14);
    push(14);
    push(14);
    push(14);
    push(14);
    push(14);
    push(14);
    push(15);
    printQueue();
    pop();
    pop();
    pop();
    printQueue();
    pop();
    pop();
    pop();

    isFull();
    isEmpty();
    return 0;
}