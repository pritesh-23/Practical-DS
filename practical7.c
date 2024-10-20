#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createCSLL(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

void traverseCSLL(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct Node *insertBeg(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    return head;
}

struct Node *insertEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

struct Node *deleteBeg(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct Node *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Create\n2. Traverse\n3. Insert at Beginning\n4. Insert at End\n");
        printf("5. Delete from Beginning\n6. Delete from End\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to create node: ");
            scanf("%d", &value);
            head = createCSLL(head, value);
            printf("Node created.\n");
            break;
        case 2:
            printf("CSLL contents: ");
            traverseCSLL(head);
            break;
        case 3:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            head = insertBeg(head, value);
            printf("Node inserted at beginning.\n");
            break;
        case 4:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            head = insertEnd(head, value);
            printf("Node inserted at end.\n");
            break;
        case 5:
            head = deleteBeg(head);
            printf("Node deleted from beginning.\n");
            break;
        case 6:
            head = deleteEnd(head);
            printf("Node deleted from end.\n");
            break;
        case 7:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}