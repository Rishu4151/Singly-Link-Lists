#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode 
{
    int value;
    struct ListNode *next;
} ListNode;

ListNode *headNode = NULL;

void appendNode(int value);
void printListInReverse(ListNode *node);

int main() 
{
    int count, value;

    printf("How many elements do you want to add to the linked list? ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) 
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        appendNode(value);
    }

    printf("The linked list in reverse order is: ");
    printListInReverse(headNode);
    printf("\n");

    return 0;
}

void appendNode(int value) 
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;

    if (headNode == NULL) 
    {
        headNode = newNode;
        return;
    }

    ListNode *current = headNode;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    current->next = newNode;
}

void printListInReverse(ListNode *node) 
{
    if (node == NULL)
        return;
    printListInReverse(node->next);
    printf("%d ", node->value);
}