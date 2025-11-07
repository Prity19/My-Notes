#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct _node
{
    int coeff;
    int exp;
    struct _node *next;
} Node;
Node *createNode(int co, int expo)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = co;
    newNode->exp = expo;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(Node **head, float co, int expo)
{
    if (co == 0)
        return;
    Node *newNode = createNode(co, expo);
    if (*head == NULL || expo > (*head)->exp)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && expo < temp->exp)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL && temp->exp == expo)
    {
        temp->coeff += co;
        free(newNode);
        return;
    }
    if (prev == NULL)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        newNode->next = temp;
        prev->next = newNode;
    }
}
void display(Node *head)
{
    if (head == NULL)
    {
        printf("Polynmial is empty\n");
        return;
    }
    Node *temp = head;
    int first_term = 1;
    while (temp != NULL)
    {
        if (!first_term)
        {
            if (temp->coeff > 0)
                printf("+");
        }
        else
        {
            if (temp->coeff > 0)
                printf("+");
            first_term = 0;
        }
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
float evaluatePoly(Node *p, float x)
{
    float result = 0;
    while (p)
    {
        result += p->coeff * powf(x, p->exp);
        p = p->next;
    }
    return result;
}
Node *add(Node *p1, Node *p2)
{
    Node *result = NULL;
    while (p1)
    {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2)
    {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}
int main()
{
    int choice, coeff, expo;
    float x;
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;
    while (1)
    {
        printf("MENU\n");
        printf("1.insert term in polynomial 1\n");
        printf("2.insert term in polynomial 2\n");
        printf("3.Print polynomial 1\n");
        printf("4.Print polynomial 2\n");
        printf("5.Add polynomials\n");
        printf("6.Evaluate polynomial 1\n");
        printf("7.Evaluate  polynomial 2\n");
        printf("8.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the coefficient and exponent:");
            scanf("%d %d", &coeff, &expo);
            insertTerm(&poly1, coeff, expo);
            break;
        case 2:
            printf("Enter the coefficient and exponent:");
            scanf("%d %d", &coeff, &expo);
            insertTerm(&poly2, coeff, expo);
            break;
        case 3:
            printf("Polynomial 1:");
            display(poly1);
            break;
        case 4:
            printf("Polynomial 2:");
            display(poly2);
            break;
        case 5:
            result = add(poly1, poly2);
            printf("Sum:");
            display(result);
            break;
        case 6:
            printf("Enter value of x to evaluate polynomial 1:");
            scanf("%f", &x);
            printf("Result:%.2f\n", evaluatePoly(poly1, x));
            break;
        case 7:
            printf("Enter value of x to evaluate polynomial 2:");
            scanf("%f", &x);
            printf("Result:%.2f\n", evaluatePoly(poly2, x));
            break;
        case 8:
            printf("EXITING\n");
            exit(0);
        }
    }
    return 0;
}
