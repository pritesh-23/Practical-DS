#include <stdio.h>  
#include <stdlib.h>  
  
struct node {  
    int data;  
    struct node *next;  
};  
struct node *Top = NULL;    
  
void push(int num) {  
    struct node *p;  
    p=(struct node *)malloc(sizeof(struct node));  
  
    if (p== NULL) {  
        printf("Stack Overflow\n");  
        return;  
    }  
    p->data = num;  
    p->next = Top;  
    Top =p;    
}  
  
void pop() {  
    struct node *t;  
    if (Top == NULL) {  
        printf("Stack Underflow\n");  
    } else {  
        t = Top;  
        Top = Top->next;   
        free(t); t = NULL;  
    }  
}  
  
void print() {  
    struct node *temp = Top;  
    if (Top == NULL) {  
        printf("Stack is empty\n");  
        return;  
    }  
    printf("Elements of stacks are:\n");  
    while (temp != NULL) {  
        printf("%d\n", temp->data);  
        temp = temp->next;  
    }  
}  
  
int main() {  
    int choice;  
    int value;  
  
    do {  
        printf("Select the the operation:  1) Push 2) Pop 3) print 4) Exit \n");  
        scanf("%d", &choice);   
        switch (choice) {  
        case 1:  
            printf("Enter the value: ");  
            scanf("%d", &value);  
            push(value);  
            break;  
        case 2: pop();  
            break;  
        case 3:  
            print();  
            break;  
        case 4:  
            printf("Exit successfully\n");  
            break;  
        default:  
            printf("Invalid choice\n");  
        }  
    } while (choice != 4);  
  
    return 0;  
} 