#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition1(int a[],int p,int r)
{
    int x=a[r];
    int i= (p-1);
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]>=x  && a[j]>0 )
        {
            i++;
            swap(&a[i],&a[j]);
        }
        else if(a[j]<=x  && a[j]<0 )
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return (i+1);
}

void quicksort1(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition1(a,p,r);
        quicksort1(a,p,q-1);
        quicksort1(a,q+1,r);
    }
}

void problem1()
{
    int a[]={-7,3,80,12,-35,28,-54,61,12,3,9,-5,35,52,-96,29,-12,27,37,-42,53,48,63,-51,-75,19,-11,2,-81,55,-14,41,-29,97,-245};
    int n=sizeof(a)/sizeof(a[0]);
    int c1=0,c2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            c1++;
        }
        if(a[i]>0)
        {
            c2++;
        }
    }
    quicksort1(a,0,n-1);
    printf("\nPositive numbers in decreasing order\n");
    printArray(a,c2);
    printf("\nNegative numbers in increasing order\n");
    for(int i=c2;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void printwords(char para[])
{
   
        int count=0;
        for(int i=0;para[i]!='\0';i++)
        {
            if(para[i]!=' ' && para[i]!=',' && para[i]!='.')
            {
                printf("%c",para[i]);
                count=0;
            }    
            if(para[i]==' ' && count==0)
            {
                printf("\n");
                count++;
            }    
                
                
            
        }
}


void printsort(char para[])
{
    
    int j=0,count=0;
    char newstring[100][100];
    for(int i=0;i<strlen(para);i++)
    {
        if(para[i]==' ' || para[i]==',' || para[i]=='.' || para[i]=='\0')
        {
            newstring[count][j]='\0';
            count++;
            j=0;
        }
        else
        {
            newstring[count][j]=para[i];
            j++;
        }
    }
    int check;
    for (int i = 0; i < count; i++) {
    if (strchr(newstring[i], '-') != NULL) {
        printf(" %s\n", newstring[i]);
        check=i;
    }
    }
    
    char temp;

   int i1, j1;
   int n = strlen(newstring[check]);

   for (i1 = 0; i1 < n-1; i1++) {
      for (j1 = i1+1; j1 < n; j1++) {
         if (newstring[check][i1] > newstring[check][j1]) {
            temp = newstring[check][i1];
            newstring[check][i1] = newstring[check][j1];
            newstring[check][j1] = temp;
         }
      }
   }
   
   printf("String after sorting  - %s \n", newstring[check]);

}
  

void problem2()
{
    char arr[]="A stochastic fractal is built out of probabilities and randomness. It is statistically self-similar. We\
will look at both deterministic and stochastic techniques for generating fractal patterns. A line is\
self-similar. A line looks the same at any scale, but it’s not a fractal. A fractal is characterized\
by having a fine structure at small scales, you’ll continue to find fluctuations, and cannot be\
described with Euclidean geometry. If you can say, it’s a line, then it’s not a fractal. Another\
fundamental component of fractal geometry is recursion. Fractal has a recursive definition.\
We’ll start with recursion before developing techniques and code examples for building fractal\
patterns. " ;
    
    printwords(arr); 
    printsort(arr);

}

void insertion(float a[],int n)
{
    for(int j=0;j<n;j++)
    {
        float key=a[j];
        int i=j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i--;
            a[i+1]=key;
        }
    } 
}  

int atleast3(int x){
    int count=0;
    while((x/10)!=0){
        if((x % 10)%2 != 0) count++;
        x/=10;
    }
    if((x % 2) !=0) count++;
    return count;
   
}

void problem3()
{
    FILE *fp1;
    fp1=fopen("007-input.txt","w");
    srand((unsigned int)time(NULL));
    float k,f,r;  
    for(int i=0;i<1000;i++)
    {
        f=10 + rand()%51;
        r=10000 + rand()%100000;
        r=r*0.0001;
        k=r+f;
        fprintf(fp1,"%f\n",k);
    }
    fclose(fp1);
    float a[1000];
    int i=0;
    fp1=fopen("007-input.txt","r");
    fscanf(fp1,"%f",&a[i]);
    while(!feof(fp1))
    {
        fscanf(fp1,"%f",&a[i]);
        i++;
    }
    fclose(fp1);
    insertion(a,1000); 
    FILE *fp2;
    fp2=fopen("007-output.txt","w");
    for(int i=999;i>=0;i--)
    {
        if(a[i]>15.000000 && a[i]<46.999999)
        {
            fprintf(fp2,"%f\n",a[i]);
        }
    }
    float b[1000];
    fprintf(fp2,"\n\n\n");
    for(int i=0;i<1000;i++)
    {
        b[i]=a[i]*1000000;  
        int c=atleast3(b[i]);
        if(c>=3)
        {
            fprintf(fp2,"%f\t %d\n",b[i],c);
        }
              
    }
    fclose(fp2);

} 

int main()
{
    problem2();
    problem1();
    problem3();
}   
