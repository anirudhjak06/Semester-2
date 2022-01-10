#include<stdio.h>
#include<stdlib.h>

void heapify(int a[],int n,int i)
{
    int parent=(i-1)/2;
    if(a[i]<a[parent])
    {
        int temp=a[i];
        a[i]=a[parent];
        a[parent]=temp;
        heapify(a,n,parent);
    }  
}

void insert_node(int a[],int n,int key)
{
        a[n-1]=key;
        heapify(a,n,n-1);
}

void problem1()
{
    int n=6;
    int *a=(int*)malloc(n*sizeof(int));
    a[0]=1;
    a[1]=3;
    a[2]=6;
    a[3]=5;
    a[4]=9;
    a[5]=8; 
    int key[100],q,m=7;
    for(int i=0;i<100;i++)
    {
        printf("Enter an element to insert\n");
        scanf("%d",&key[i]);
        int k=m;
        a=realloc(a,k*sizeof(int));
        insert_node(a,k,key[i]);
        for(int i=0;i<k;i++)
        {
            printf("%d ",a[i]);
        }
        m++;
        printf("\nEnter 0 to quit\nElse Enter any value other than 0\n");
        scanf("%d",&q);
        if(q==0)
        {
            break;
        }
        else
        {
            continue;
        }
        
    }
    
}

void max_heapify(int ar[],int size,int i)
{
    int left=2*i,right=2*i+1,largest=i;
    if(left<size && ar[left]>ar[i])
    {
        largest=left;
    }
    else
    {
        largest=i;
    }
    if(right<size && ar[right]>ar[i])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp;
        temp=ar[i];
        ar[i]=ar[largest];
        ar[largest]=temp;
    max_heapify(ar,size,largest);
    //to heapify the tree in form of binary tree
    }
}

void build_maxheap(int ar[],int size)
{
    //iteratively calls max_heapify function to heapify the tree
    for(int i=size/2;i>=1;i--)
    {
        max_heapify(ar,size,i);
    }
}

void heap_extract_max(int ar[],int size)
{
    if(size<1)
    {   
        return;
    }
    int max=ar[0];
    ar[0]=ar[size-1];
    size=size-1;
    build_maxheap(ar,size);
    max_heapify(ar,size,0);
    printf("%d ",max);
   heap_extract_max(ar,size);
   //recursively calls the function to get maximum element in max.heap
}
  
void problem2()
{
    int ar[]={25,14,16,13,10,8,12};
    int size=sizeof(ar)/sizeof(int);
    build_maxheap(ar,size);
    heap_extract_max(ar,size);
}

int main()
{
    //problem1();
    problem2();
}