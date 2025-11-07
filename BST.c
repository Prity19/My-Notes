#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;
Node *create(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
Node *insertRec(Node *root, int value)
{
    if (root == NULL)
        return create(value);
    if (value < root->data)
        root->lchild = insertRec(root->lchild, value);
    else if (value > root->data)
        root->rchild = insertRec(root->rchild, value);
    else
        printf("Duplicate value inserted\n");
    return root;
}
Node *insertIterate(Node *root, int value)
{
    Node *newNode = create(value);
    if (root == NULL)
        return newNode;

    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (value < curr->data)
            curr = curr->lchild;
        else if (value > curr->data)
            curr = curr->rchild;
        else
        {
            printf("Value %d already exists", value);
            free(newNode);
            return root;
        }
    }
    if (value < parent->data)
        parent->lchild = newNode;
    else
        parent->rchild = newNode;

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}
void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}
int main()
{
    int value, choice;
    Node *root = NULL;
    while (1)
    {
        printf("MENU\n");
        printf("1.Insert recursively\n2.Insert iteratively\n3.inorder traversal\n4.preorder traversal\n5.postorder traversal\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to insert recursivelu:");
            scanf("%d", &value);
            root = insertRec(root, value);
            break;
        case 2:
            printf("Enter the value to insert iteratively:");
            scanf("%d", &value);
            root = insertIterate(root, value);
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            preorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("EXITING\n");
            exit(0);
        }
    }
    return 0;
}
