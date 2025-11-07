#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert Node at End
void insert() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node newnode = (struct Node)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node inserted.\n");
}

// Print List
void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search Node
void search() {
    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found.\n");
}

// Delete Middle Node
void deleteMiddle() {
    if (head == NULL || head->next == NULL) {
        printf("Not enough elements.\n");
        return;
    }

    struct Node *slow = head, *fast = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    printf("Middle element %d deleted.\n", slow->data);
    free(slow);
}

// Find Smallest Element
void smallest() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int min = head->data;
    struct Node *temp = head->next;

    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    printf("Smallest element = %d\n", min);
}

// Find Largest Element
void largest() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int max = head->data;
    struct Node *temp = head->next;

    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    printf("Largest element = %d\n", max);
}

// Sort Ascending
void sortAscending() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// Count Nodes
void countNodes() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", count);
}

// Delete Smallest Node
void deleteSmallest() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    int min = head->data;

    struct Node *p = head->next;
    while (p != NULL) {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }

    while (temp != NULL && temp->data != min) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Smallest element deleted.\n");
}

// Delete Largest Node
void deleteLargest() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;
    int max = head->data;

    struct Node *p = head->next;
    while (p != NULL) {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }

    while (temp != NULL && temp->data != max) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Largest element deleted.\n");
}

// Reverse Linked List
void reverse() {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed.\n");
}

// Insert at Position
void insertPos() {
    int pos, value;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node newnode = (struct Node)malloc(sizeof(struct Node));
    newnode->data = value;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position.\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    printf("Inserted.\n");
}

// Delete at Position
void deletePos() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        printf("Deleted.\n");
        return;
    }

    struct Node *prev;
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted.\n");
}

// MAIN MENU
int main() {
    int choice;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert Node\n");
        printf("2. Print List\n");
        printf("3. Search Node\n");
        printf("4. Delete Middle Node\n");
        printf("5. Find Smallest Element\n");
        printf("6. Find Largest Element\n");
        printf("7. Sort Ascending\n");
        printf("8. Count Nodes\n");
        printf("9. Delete Smallest Element\n");
        printf("10. Delete Largest Element\n");
        printf("11. Reverse List\n");
        printf("12. Insert at Position\n");
        printf("13. Delete at Position\n");
        printf("14. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: printList(); break;
            case 3: search(); break;
            case 4: deleteMiddle(); break;
            case 5: smallest(); break;
            case 6: largest(); break;
            case 7: sortAscending(); break;
            case 8: countNodes(); break;
            case 9: deleteSmallest(); break;
            case 10: deleteLargest(); break;
            case 11: reverse(); break;
            case 12: insertPos(); break;
            case 13: deletePos(); break;
            case 14: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
}
