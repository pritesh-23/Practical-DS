#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
};

struct node *f = NULL, *r = NULL;

void insert() {
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("Enter data of the node: ");
    scanf("%d", &p->data);
    p->next = NULL;
    
    if (r == NULL) {
        f = p;
        r = p;
    } else {
        r->next = p;
        r = p;
    }
    printf("Node inserted with value: %d\n", p->data);
}

void delete() {
    struct node *q;
    
    if (f == NULL) {
        printf("Queue Underflow\n");
        return;
    } else {
        q = f;
        f = f->next;
        free(q);
        if (f == NULL) {
            r = NULL;
        }
        printf("Node deleted\n");
    }
}

void display() {
    struct node *temp = f;
    
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    
    do {
        printf("\n1 - Insert\n2 - Delete\n3 - Display\n4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}

