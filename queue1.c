#include<stdio.h>
#define max 5
int myqueue[max];
int r = -1;
int f = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    do {
        printf("\n1-Insert\n2-Delete\n3-Print\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
}

void enqueue() {
    int item;
    printf("Enter element you want to insert into the queue: ");
    scanf("%d", &item);

    if (r == max - 1) {
        printf("Queue Overflow! Cannot insert.\n");
    } 
	else 
	{
        if (f == -1) {
            f = 0;
        }
        r = r + 1;
        myqueue[r] = item;
        printf("Element %d inserted successfully.\n", item);
    }
}

void dequeue() {
    int item;
    if (f == -1 || f > r) {
        printf("Queue Underflow! Cannot delete.\n");
    } else {
        item = myqueue[f];
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = f + 1;
        }
        printf("Element %d deleted successfully.\n", item);
    }
}

void display() {
	int i;
    if (f == -1 || f > r) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contents: ");
    	for (i = f; i <= r; i++) {
            printf("%d ", myqueue[i]);
        }
        printf("\n");
    }
}

