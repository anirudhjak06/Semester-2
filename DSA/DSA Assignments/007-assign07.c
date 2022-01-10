
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define STACKSIZE 100
#define MAX 100

int pop();
int precedence(char symbol);
int isEmpty();
void infix_to_prefix();
int checker(char symbol);
void push(long int symbol); 

char prefix_string[20], infix_string[20], postfix_string[20];
int top;
long int stack[20];

int problem3()
{
    int count,length;
    char temp;
    top = -1;
    printf("\nEnter an Expression in Infix format:\t");
    scanf("%[^\n]s", infix_string);
    infix_to_prefix();
    length = strlen(postfix_string) - 1;
    strncpy(prefix_string, postfix_string, 20);
    /*for(count = 0; count < length; count++, length--)
    {
        temp = prefix_string[count];
        prefix_string[count] = prefix_string[length];
        prefix_string[length] = temp;
    }*/
    printf("\nExpression in Prefix Format: \t%s\n\n", prefix_string);
    return 0;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return (stack[top--]);
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}


int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infix_to_prefix()
{
    unsigned int count, temp = 0;
    char next;
    char symbol;
    for (count = 0; count < strlen(infix_string); count++)
    {
        symbol = infix_string[count];
        if (!checker(symbol))
        {
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix_string[temp++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix_string[temp++] = pop();
                push(symbol);
                break;
            default:
                postfix_string[temp++] = symbol;
            }
        }
    }
    while (!isEmpty())
    {
        postfix_string[temp++] = pop();
    }
    postfix_string[temp] = '\0';
}


int checker(char symbol)
{
    if (symbol == '\t' || symbol == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(long int symbol)
{
    if (top > 20)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top = top + 1;
    stack[top] = symbol;
}
struct stack
{
    int top;
    int items[STACKSIZE];
};

void push1(struct stack *ps, int x)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("Error: stack overflown");
        getchar();
        exit(0);
    }
    else
    {
        ps->top += 1;
        int top = ps->top;
        ps->items[top] = x;
    }
}

bool isEmpty1(struct stack *ps)
{
    return (ps->top == -1) ? true : false;
}

int pop1(struct stack *ps)
{
    int temp;
    if (ps->top == -1)
    {
        printf("\nError: stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        int top = ps->top;
        temp = ps->items[top];
        ps->top -= 1;
        return temp;
    }
}

void print(int arr[], int n)
{
    int i = 0;
    struct stack s;
    s.top = -1;
    int element, next;
    push1(&s, arr[0]);
    printf("\nNext greater element for each element in the array\n\n");
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        if (isEmpty1(&s) == false)
        {
            element = pop1(&s);
            while (element < next)
            {
                printf("%d --> %d\n", element, next);
                if (isEmpty1(&s) == true)
                    break;
                element = pop1(&s);
            }
            if (element > next)
                push1(&s, element);
        }
        push1(&s, next);
    }

    while(isEmpty1(&s) == false)
    {
        element = pop1(&s);
        next = -1;
        printf("%d --> %d \n", element, next);
    }
}

int problem1()
{
    int n, x;
    printf("Enter length of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    print(arr, n);
    return 0;
} 
char s[MAX];
int top3 = -1;
void push3(int elem)
{
    s[++top3] = elem;
}

int pop3()
{
    if (top3 >= 0)
        return (s[top3--]);
}

int peek3()
{
    if (top3 >= 0)
        return (s[top3]);
    return -1;
}

int qpush(int arr2[], int end, int v)
{
    arr2[end++] = v;
    return end;
}

int qpop(int arr1[], int end, int v)
{

    for (int i = 0; i <= end - 1; i++)
    {
        arr1[i] = arr1[i + 1];
    }
    return end--;
}

int problem2()
{
    int n, x, expected = 1;
    int start1 = 0, start2 = 0, end2 = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    int end1 = n;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (expected == arr1[i])
        {
            end2 = qpush(arr2, end2, expected);
            expected++;
        }
        else
        {
            x = peek3();
            if (x == -1 || x > arr1[i])
            {
                push3(arr1[i]);
            }
            else
            {
                flag = 1;
                printf("No");
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Yes");
    }
}


int main()
{
    problem1();
    //problem2();
    //problem3();
}




