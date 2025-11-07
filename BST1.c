#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST (Recursive)
struct node* insert(struct node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search in BST (Recursive)
int search(struct node* root, int key) {
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Traversals
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find minimum node (used in deletion)
struct node* findMin(struct node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node in BST
struct node* deleteNode(struct node* root, int key) {
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Count Leaf Nodes
int countLeaf(struct node* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Smallest Leaf Node
int smallestLeaf(struct node* root) {
    if(root == NULL)
        return 999999;

    if(root->left == NULL && root->right == NULL)
        return root->data;

    int leftMin = smallestLeaf(root->left);
    int rightMin = smallestLeaf(root->right);

    return (leftMin < rightMin) ? leftMin : rightMin;
}

// Largest Leaf Node
int largestLeaf(struct node* root) {
    if(root == NULL)
        return -999999;

    if(root->left == NULL && root->right == NULL)
        return root->data;

    int leftMax = largestLeaf(root->left);
    int rightMax = largestLeaf(root->right);

    return (leftMax > rightMax) ? leftMax : rightMax;
}

// Main Menu
int main() {
    struct node* root = NULL;
    int ch, value;

    while(1) {
        printf("\n\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Smallest Leaf Node\n");
        printf("9. Largest Leaf Node\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value))
                    printf("Value Found.\n");
                else
                    printf("Value Not Found.\n");
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                printf("Total Leaf Nodes = %d\n", countLeaf(root));
                break;

            case 8:
                printf("Smallest Leaf Node = %d\n", smallestLeaf(root));
                break;

            case 9:
                printf("Largest Leaf Node = %d\n", largestLeaf(root));
                break;

            case 10:
                exit(0);
            
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
