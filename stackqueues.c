#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    int data;
    struct _node *next;
} Node;
int push(Node **top, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    int pushed = value;
    newNode->next = *top;
    *top = newNode;
    return pushed;
}
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return 0;
    }
    Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return top->data;
}
void display(Node *top)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void enqueue(Node **front, Node **rear, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) // queue empty
    {
        *front = *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}
int dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = *front;
    int dequeuedValue = temp->data;
    *front = (*front)->next;
    free(temp);
    return dequeuedValue;
}
void printQueue(Node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value, popped;
    Node *top = NULL;
    Node *front = NULL;
    Node *rear = NULL;
    while (1)
    {
        printf("MENU\n");
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf("6.ENQUEUE\n7.DEQUEUE\n8.PRINT QUEUE\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value to push:");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            popped = pop(&top);
            if (popped != 0)
                printf("Popped value=%d\n", popped);
            break;
        case 3:
            value = peek(top);
            printf("Top element=%d\n", value);
            break;
        case 4:
            display(top);
            break;
        case 5:
            printf("EXIT\n");
            exit(0);
        case 6:
            printf("enter value to enqueue:");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            break;
        case 7:
            value = dequeue(&front, &rear);
            if (value != -1)
                printf("%d dequeued from queue\n", value);
            break;
        case 8:
            printQueue(front);
            break;
        }
    }
    return 0;
}
