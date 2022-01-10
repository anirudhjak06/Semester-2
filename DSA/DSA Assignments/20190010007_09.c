#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newitem(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return(node);
}

void inOrder(struct node* node)
{    
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

void toreflect(struct node* node)
{    
    if (node==NULL)
        return;
    else
    {
        struct node* temp;
        toreflect(node->left);
        toreflect(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

struct node* newNode(int data)
{    
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int is_1_or_0(struct node* temp)
{   
    int ptrleft = 0, ptrright = 0;
    if(temp == NULL || (temp->left == NULL && temp->right == NULL))
        return 1;
    else
    {
        if(temp->left != NULL)
            ptrleft = temp->left->data;
        if(temp->right != NULL)
            ptrright = temp->right->data;
        if((temp->data == ptrleft + ptrright) && is_1_or_0(temp->left) && is_1_or_0(temp->right))
            return 1;
        else
            return 0;
    }
}
    
void problem1()
{
    printf("\nQuestion 1\n");
    struct node *root = newitem(8);
    root->left = newitem(3);
    root->right = newitem(10);
    root->left->left = newitem(1);
    root->left->right = newitem(6);
    root->left->right->left = newitem(4);
    root->left->right->right = newitem(7);
    root->right->right = newitem(14);
    root->right->right->left = newitem(13);

    printf("\nInorder traversal of the constructed tree is\n");
    inOrder(root);     
    toreflect(root);
    printf("\nInorder traversal of the mirror tree is\n");
    inOrder(root);
}

int problem2()
{     
    printf("\n\nQuestion 2\n");
    struct node *root2 = newNode(13);
    root2->left = newNode(8);
    root2->right = newNode(5);
    root2->left->left = newNode(2);
    root2->left->right = newNode(6);
    root2->right->left = newNode(5);
    
    printf("\nThe answer for the first figure is \n");
    if(is_1_or_0(root2))
        printf("1\n\n");
    else
        printf("0\n\n");

    struct node *root1 = newNode(2);
    root1->left = newNode(0);
    root1->right = newNode(2);
    root1->left->left = newNode(1);
    root1->left->right = newNode(0);
    root1->right->left = newNode(2);
    root1->right->right = newNode(3);
    
    printf("The answer for the second figure is \n");
    if(is_1_or_0(root1))
        printf("1\n\n");
    else
        printf("0\n\n");    
}

int main()
{
    problem1();
    problem2();
}

