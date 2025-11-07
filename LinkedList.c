#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at end
void insert(struct Node **head) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print List
void printList(struct Node *head) {
    if (!head) {
        printf("List empty\n"); 
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Search Value
void search(struct Node *head) {
    int key, pos = 1, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);

    while (head != NULL) {
        if (head->data == key) {
            printf("Found at position %d\n", pos);
            found = 1;
        }
        head = head->next;
        pos++;
    }
    if (!found)
        printf("Not Found\n");
}

// Delete Middle Node
void deleteMiddle(struct Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Cannot delete middle\n");
        return;
    }

    struct Node *slow = *head, *fast = *head, *prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);
    printf("Middle node deleted.\n");
}

// Find Smallest
int smallest(struct Node *head) {
    int min = head->data;
    while (head) {
        if (head->data < min) min = head->data;
        head = head->next;
    }
    return min;
}

// Find Largest
int largest(struct Node *head) {
    int max = head->data;
    while (head) {
        if (head->data > max) max = head->data;
        head = head->next;
    }
    return max;
}

// Delete Smallest Element
void deleteSmallest(struct Node **head) {
    if (*head == NULL) return;

    int min = smallest(*head);
    struct Node *temp = *head, *prev = NULL;

    if (temp->data == min) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->data != min) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Delete Largest Element
void deleteLargest(struct Node **head) {
    if (*head == NULL) return;

    int max = largest(*head);
    struct Node *temp = *head, *prev = NULL;

    if (temp->data == max) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp && temp->data != max) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

// Reverse
void reverse(struct Node **head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Insert at Position
void insertPos(struct Node **head) {
    int pos, value;
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &pos);

    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete Nth Node
void deleteNth(struct Node **head) {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (*head == NULL) return;

    struct Node *temp = *head;

    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; i < pos && temp; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 🔥 Search Duplicates
void searchDuplicate(struct Node *head) {
    int found = 0;
    struct Node *ptr1 = head, *ptr2;
    while (ptr1) {
        ptr2 = ptr1->next;
        while (ptr2) {
            if (ptr1->data == ptr2->data) {
                printf("Duplicate value found: %d\n", ptr1->data);
                found = 1;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    if (!found)
        printf("No duplicates found.\n");
}

// 🔥 Delete All Duplicates
void deleteDuplicates(struct Node **head) {
    struct Node *ptr1 = *head, *ptr2, *dup;

    while (ptr1 && ptr1->next) {
        ptr2 = ptr1;
        while (ptr2->next) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    printf("Duplicates deleted.\n");
}

int main() {
    struct Node *head = NULL;
    int ch;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n2. Print\n3. Search\n4. Delete Middle\n5. Find Smallest\n6. Find Largest\n7. Delete Smallest\n8. Delete Largest\n9. Reverse\n10. Insert at Position\n11. Delete Nth Node\n12. Search Duplicates\n13. Delete All Duplicates\n14. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(&head); break;
            case 2: printList(head); break;
            case 3: search(head); break;
            case 4: deleteMiddle(&head); break;
            case 5: printf("Smallest = %d\n", smallest(head)); break;
            case 6: printf("Largest = %d\n", largest(head)); break;
            case 7: deleteSmallest(&head); break;
            case 8: deleteLargest(&head); break;
            case 9: reverse(&head); break;
            case 10: insertPos(&head); break;
            case 11: deleteNth(&head); break;
            case 12: searchDuplicate(head); break;
            case 13: deleteDuplicates(&head); break;
            case 14: exit(0);
        }
    }
    return 0;
}
