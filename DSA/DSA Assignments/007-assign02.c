#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void compute(int T[])
{
    T[0]=0;
    T[1]=1;
    T[2]=1;
    for(int i=3;i<30;i++)
    {
        *(T+i)=*(T+i-1) + *(T+i-3);
    }
}

void problem1()
{
    int T[30];
    compute(T);
    for(int j=0;j<30;j++)
    {
        printf("%d\n",*(T+j));
    }
}

void reversal(char *str,int *n)
{
    char temp;
    for(int i=0;i<(*n)/2;i++)
    {
        temp=*(str+i);
        *(str+i)=*(str + *n-i-1);
        *(str + *n-i-1)=temp;
    }
    
}

void problem2()
{
    int *n=(int*)malloc(sizeof(int));
    printf("Enter the length of the string\n");
    scanf("%d",n);
    char str[*n];
    printf("Enter the string\n");
    scanf("%s",str);
    printf("The string before reversal\n");
    printf("%s\n",str);
    reversal(str,n);
    printf("The string after reversal\n");
    printf("%s\n",str);

}

void swap(int *l,int *m)
{
    *l= *l ^ *m;
    *m= *l ^ *m;
    *l= *l ^ *m;
}

void problem3()
{
    int *x=(int*)malloc(sizeof(int));
    int *y=(int*)malloc(sizeof(int));
    printf("Enter two numbers\n");
    scanf("%d %d",x,y);
    swap(x,y);
    printf("%d\n %d\n",*x,*y);

} 

typedef struct Faculty
{
    char name[25];
    float salary;
}faculty;

void increment_salary(faculty *f)
{
    (f->salary)+=0.2 * (f->salary);
    
}

void problem4()
{
   faculty f;
   printf("Enter the name of the faculty\n");
   scanf("%s",f.name);
   printf("Enter your salary\n");
   scanf("%f",&(f.salary));
   increment_salary(&f);
   printf("After increment the final salary is %0.2f\n",f.salary);
}

typedef struct details
{
    char firstname[20];
    char lastname[20];
    int roll_no;
    int course_id[5];

} detail;

detail std[50];
int k=0;

void addStudent()
{
	printf("Enter your First name\n");
	scanf("%s",std[k].firstname);
	printf("Enter your last  name\n");
	scanf("%s",std[k].lastname);
	printf("Enter your roll no\n");
	scanf("%d",&std[k].roll_no);
	int l=0;
	for(int j=0;j<k;j++)
	{
		if(std[k].roll_no==std[j].roll_no)
		l++;
	}
	if(l>0)
	printf ("The Roll number you have entered is already existing\n");
	else
	{
		printf("Enter which courses you have choosen\n");
		printf("Enter 1 if have choosen the course otherwise Enter 0 \n");
		printf("Have you registered for DSA?\n");
		int temp;
		scanf("%d",&temp);
		if(temp==1)
		std[k].course_id[0]=1;
		printf("Have you registered for BEC?\n");
		scanf("%d",&temp);
		if(temp==1)
		std[k].course_id[1]=1;
		printf("Have you registered for M2?\n");
		scanf("%d",&temp);
		if(temp==1)
		std[k].course_id[2]=1;
		printf("Have you registered for SS?\n");
		scanf("%d",&temp);
		if(temp==1)
		std[k].course_id[3]=1;
		printf("Have you registered for ENGLISH?\n");
		scanf("%d",&temp);
		if(temp==1)
		std[k].course_id[4]=1;
		k++;
	}
}

void findStudent()
{	
	int temp;
	printf("Enter your Roll Number \n");
	scanf("%d",&temp);
	int l=0;
	for(int i=0;i<k;i++)
	{
		if(temp==std[i].roll_no)
		{
			printf("First name is %s : \n",std[i].firstname);
			printf("Last name is %s : \n",std[i].lastname);
			printf("Roll no is %d :\n",std[i].roll_no);
			for(int j=0;j<5;j++)
			{
				if(std[i].course_id[j]==1)
				{
				if(j==0) printf("DSA\n");
				if(j==1) printf("BEC\n");
				if(j==2) printf("M2\n");
				if(j==3) printf("SS\n");
				if(j==4) printf("ENGLISH\n");
				}
			}
		}
	}
}

void finsStudents()
{	int temp;
	printf("Plese select an appropiate number to know who have registered for a particular course \n");
	printf("0 for DSA\n");
	printf("1 for BEC\n");
	printf("2 for M2\n");
	printf("3 for SS\n");
	printf("4 for ENGLISH\n");	
	scanf("%d",&temp);
	if(temp>=0 && temp<=4)
	{
		for(int i=0;i<k;i++)
		{
		if(std[i].course_id[temp]==1)
			printf("%s %s have registered for the course\n",std[i].firstname,std[i].lastname);
		}
	}
}

void PrintCourseSummary()
{		for(int temp=0;temp<5;temp++)
		{
			printf("The students who registered for course with course id %d are \n",temp);
			for(int i=0;i<k;i++)
			{			
				if(std[i].course_id[temp]==1)
				printf("%s %s\n",std[i].firstname,std[i].lastname);
			}
		}
}

void problem5()
{
    while(1)
    {
        printf("Please select appropriate no. for your task\n");
        printf("1- To quit\n");
        printf("2- To add student details\n");
        printf("3- To print student details using roll no\n");
        printf("4- To print student details for a particular course\n");
        printf("5-To print the total no of students in each course\n");
        int c;
        scanf("%d",&c);
        if(c==1)
            break;
        switch(c)
        {
            case 2: addStudent();
                    break;
            case 3: findStudent();
                    break;
            case 4: finsStudents();
                    break;
            case 5: PrintCourseSummary();
                    break;
            default:printf("You have entered an invalid number\n");
                    break;
        }    
    }
    printf("Thank You! I hope you have got the required details\n");
}

int main()
{
    problem1();
    problem2();
    problem3();
    problem4();
    problem5();
    
}