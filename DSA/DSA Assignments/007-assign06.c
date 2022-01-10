#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair
{
    int key;
    int data;
}pair;

pair H[10];
int n = 10;
int hashfunction(int keyval)
{
    int index = keyval%10;
    int i=0;
    if(H[index].key!=-1)
    {
        while(H[(keyval+i*i)%10].data!=0)
        {
            i++;
        }
    }
    return (keyval + i*i)%10;
}

int hashbase(int keyval,int i)
{
    int index = (keyval+(i*i))%10;
    return index;
}

void delete(int keyval)
{
    for(int i=0; i<10; i++)
    {
        int index = hashbase(keyval,i);
        if(H[index].key==keyval)
        {
            H[index].key = -1;
            H[index].data = 0;
            break;
        }
    }
}

int search(int keyval)
{
    printf("The element with key value %d ",keyval);
    int index;
    for(int i=0;i<n;i++)
    {
        index = hashbase(keyval,i);
        if(H[index].key==keyval)
        return 1;
    }
    return 0;
}

void insert(pair p)
{
    int index = hashfunction(p.key);
    H[index].data = p.data;
    H[index].key = p.key;
}

void display()
{
    printf("\nDisplaying the hash table\n\n");
    printf("key -> value\n");
    for(int i=0;i<n;i++)
    {
        if(H[i].key!=-1)
        printf("%d -> %d \n",H[i].key,H[i].data);
    }
    printf("\n");
}

void problem1()
{

    for(int i=0;i<10;i++)
    {
        H[i].data = 0;
        H[i].key = -1;
    }
    pair arr[3];
    arr[0].key=12;
    arr[0].data=10;
    arr[1].key=122;
    arr[1].data=4; 
    arr[2].key=82;
    arr[2].data=5;
    for(int i=0;i< 3; i++)
    {
        insert(arr[i]);
    }
    display(); 
    delete(122);
    printf("Hash table after deleting the element 122 is \n");
    display();

    if(search(38)) 
        printf("is found\n");
    else 
        printf("is not found\n");

    if(search(12)) 
        printf("is found\n");
    else 
        printf("is not found\n");
}

typedef struct Node
{
   int data;
   struct Node *left,*right,*middle;
}Node;

Node* newNode(int data) 
{ 
   Node *temp = (Node *)malloc(sizeof(Node)); 
   temp->data = data; 
   temp->left = temp->right = temp->middle = NULL; 
   return temp; 
}

void MiniMax(Node *node, int *min, int *max, int h) 
{ 
    if (node == NULL) 
        return; 
    if (h< *min)  
        *min = h; 
    else if (h > *max) 
        *max = h; 
  
    MiniMax(node->left, min, max, h-1); 
    MiniMax(node->middle, min, max, h); 
    MiniMax(node->right, min, max, h+1); 
} 

void pvertic(Node *node, int i, int h) 
{ 
    if (node == NULL) 
        return; 
  
    if (h==i) 
        printf("%d ",node->data);
   
    pvertic(node->left, i, h-1); 
    pvertic(node->middle,i, h);
    pvertic(node->right,i, h+1);
} 


void vertical(Node *root) 
{ 
    int min = 0, max = 0; 
    MiniMax(root, &min, &max, 0);    
    for(int i=min;i<= max;i++) 
    { 
        pvertic(root,i, 0);
        printf("\n"); 
    } 
}

void problem2()
{
    Node *root = newNode(1); 
    root->left = newNode(2);
    root->middle = newNode(3); 
    root->right = newNode(4); 
    root->left->left = newNode(5); 
    root->left->middle = newNode(6); 
    root->left->right = newNode(7); 
    root->middle->left = newNode(8);
    root->middle->middle = newNode(9);
    root->middle->right = newNode(10);
    root->right->left = newNode(11);
    root->right->middle = newNode(12);
    root->right->right = newNode(13);
    root->right->right->left = newNode(14); 
    root->right->right->middle = newNode(15); 
    root->right->right->right = newNode(16); 

    printf("In vertical order\n");
    vertical(root);
   
}

int main()
{
    problem1();
    //problem2();
}