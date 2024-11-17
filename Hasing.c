#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* chainTable[SIZE]; 
int openAddressingTable[SIZE];  

int hashFunction(int value) {
    return value % SIZE;
}

void insertChaining(int value) {
    int index = hashFunction(value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = chainTable[index];
    chainTable[index] = newNode;
}

void displayChaining() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = chainTable[i];
        printf("Index %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void insertLinearProbing(int value) {
    int index = hashFunction(value);
    while (openAddressingTable[index] != 0) {
        index = (index + 1) % SIZE;
    }
    openAddressingTable[index] = value;
}

void displayLinearProbing() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, openAddressingTable[i]);
    }
}

void insertQuadraticProbing(int value) {
    int index = hashFunction(value);
    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;
        if (openAddressingTable[newIndex] == 0) {
            openAddressingTable[newIndex] = value;
            return;
        }
    }
}

int secondHashFunction(int value) {
    return 7 - (value % 7); 
}

void insertDoubleHashing(int value) {
    int index = hashFunction(value);
    int stepSize = secondHashFunction(value);
    while (openAddressingTable[index] != 0) {
        index = (index + stepSize) % SIZE;
    }
    openAddressingTable[index] = value;
}

int main() {

    printf("Chaining:\n");
    insertChaining(10);
    insertChaining(20);
    insertChaining(30);
    insertChaining(42);
    displayChaining();

    printf("\nLinear Probing:\n");
    for (int i = 0; i < SIZE; i++) {
        openAddressingTable[i] = 0; 
    }
    insertLinearProbing(10);
    insertLinearProbing(21);
    insertLinearProbing(30);
    insertLinearProbing(46);
    displayLinearProbing();

    printf("\nQuadratic Probing:\n");
    for (int i = 0; i < SIZE; i++) {
        openAddressingTable[i] = 0; 
    }
    insertQuadraticProbing(12);
    insertQuadraticProbing(24);
    insertQuadraticProbing(34);
    insertQuadraticProbing(45);
    displayLinearProbing(); 

    printf("\nDouble Hashing:\n");
    for (int i = 0; i < SIZE; i++) {
    }
    insertDoubleHashing(10);
    insertDoubleHashing(22);
    insertDoubleHashing(32);
    insertDoubleHashing(45);
    displayLinearProbing(); 
    return 0;
}