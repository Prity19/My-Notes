#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;
Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
Node *Tree()
{
    int data;
    printf("Enter node data(-1 for no node):");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    Node *newNode;
    newNode = createNode(data);
    printf("Left node for %d\n", data);
    newNode->lchild = Tree();
    printf("Right node for %d\n", data);
    newNode->rchild = Tree();
    return newNode;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}
int main()
{
    int choice;
    Node *root = NULL;
    while (1)
    {
        printf("/nMENU\n");
        printf("1.Create binary tree\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = Tree();
            printf("Created binary tree successfully:\n");
            break;
        case 2:
            printf("Inorder:");
            inorder(root);
            break;
        case 3:
            printf("Preorder:");
            preorder(root);
            break;
        case 4:
            printf("Postorder:");
            postorder(root);
            break;
        case 5:
            printf("EXITING\n");
            exit(0);
        }
    }
    return 0;
}
