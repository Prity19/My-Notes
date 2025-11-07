#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void push(Node **top, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    return;
}
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int isEmpty(Node *top)
{
    return top == NULL;
}
void enqueue(Node **s1, int value)
{
    push(s1, value);
    printf("%d enqueued to queue\n ", value);
}
int dequeue(Node **s1, Node **s2)
{
    if (isEmpty(*s1) && isEmpty(*s2))
    {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(*s2))
    {
        while (!isEmpty(*s1))
        {
            int value = pop(s1);
            push(s2, value);
        }
    }
    int dequeued = pop(s2);

    return dequeued;
}

void printqueue(Node *s1, Node *s2)
{
    if (isEmpty(s1) && isEmpty(s2))
    {
        printf("Queue is empty\n");
        return;
    }
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    Node *t = s1;
    while (t != NULL)
    {
        push(&temp1, t->data);
        t = t->next;
    }
    t = s2;
    while (t != NULL)
    {
        printf("%d->", t->data);
        t = t->next;
    }
    while (temp1 != NULL)
    {
        printf("%d->", temp1->data);
        temp1 = temp1->next;
    }
    printf("NULL\n");
}
int main()
{
    Node *s1 = NULL;
    Node *s2 = NULL;
    int choice, value;
    while (1)
    {
        printf("MENU\n");
        printf("1.Enqueue\n2.Dequeue\n3.Print Queue\n4.Exit\n");
        printf("Enter ur choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value:");
            scanf("%d", &value);
            enqueue(&s1, value);
            break;
        case 2:
            value = dequeue(&s1, &s2);
            if (value != -1)
                printf("%d dequeued from queue\n", value);
            break;
        case 3:
            printqueue(s1, s2);
            break;
        case 4:
            printf("Exiting\n");
            exit(0);
        }
    }
    return 0;
}
