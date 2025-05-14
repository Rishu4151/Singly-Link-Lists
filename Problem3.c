#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* nextNode;
} ListNode;

ListNode* createNewNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->nextNode = NULL;
    return newNode;
}

void findMthFromEnd(ListNode* head, int m) {
    ListNode *mainPtr = head, *refPtr = head;
    int count = 0;

    while (count < m) {
        if (refPtr == NULL) {
            printf("The list has fewer than %d nodes.\n", m);
            return;
        }
        refPtr = refPtr->nextNode;
        count++;
    }

    while (refPtr != NULL) {
        mainPtr = mainPtr->nextNode;
        refPtr = refPtr->nextNode;
    }

    printf("The %d-th node from the end is: %d\n", m, mainPtr->value);
}

void displayList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->nextNode;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    ListNode* currentNode;
    int nodeCount, m, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    if (nodeCount <= 0) {
        printf("The list must have at least one node.\n");
        return 0;
    }

    printf("Enter the elements of the list: \n");
    for (int i = 0; i < nodeCount; i++) {
        scanf("%d", &value);
        if (head == NULL) {
            head = createNewNode(value);
            currentNode = head;
        } else {
            currentNode->nextNode = createNewNode(value);
            currentNode = currentNode->nextNode;
        }
    }

    printf("Enter the value of m: ");
    scanf("%d", &m);
    displayList(head);
    findMthFromEnd(head, m);

    return 0;
}