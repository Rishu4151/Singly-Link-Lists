#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode 
{
    int value;
    struct ListNode *next;
} ListNode;

ListNode *head = NULL;

void displayList();
int isListEmpty();
void addNode(int value, int position);
void removeNode(int position);
int getNodeCount();

int main() 
{
    int option, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display the list\n");
        printf("2. Check if the list is empty\n");
        printf("3. Add a node\n");
        printf("4. Remove a node\n");
        printf("5. Count the total number of nodes\n");
        printf("6. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &option);

        switch (option) 
        {
            case 1:
                displayList();
                break;
            case 2:
                printf(isListEmpty() ? "The list is empty.\n" : "The list is not empty.\n");
                break;
            case 3:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                printf("Enter the position to add (0 for beginning): ");
                scanf("%d", &position);
                addNode(value, position);
                break;
            case 4:
                printf("Enter the position to remove (0 for beginning): ");
                scanf("%d", &position);
                removeNode(position);
                break;
            case 5:
                printf("Total number of nodes: %d\n", getNodeCount());
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void displayList() 
{
    ListNode *current = head;
    if (!current) {
        printf("The list is empty.\n");
        return;
    }
    printf("List elements: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int isListEmpty() 
{
    return head == NULL;
}

void addNode(int value, int position) 
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;

    if (position == 0) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode *current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) 
    {
        current = current->next;
    }

    if (!current) 
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void removeNode(int position) 
{
    if (isListEmpty()) 
    {
        printf("The list is empty.\n");
        return;
    }

    ListNode *current = head;
    if (position == 0) 
    {
        head = head->next;
        free(current);
        return;
    }

    ListNode *previous = NULL;
    for (int i = 0; current != NULL && i < position; i++) 
    {
        previous = current;
        current = current->next;
    }

    if (!current) 
    {
        printf("Position out of bounds.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

int getNodeCount() 
{
    int count = 0;
    ListNode *current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}