#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

#define initial 1
#define waiting 2
#define visited 3

int n, flag, v, gap = 0, pd, kk;
int adj[MAX][MAX];
int daj[MAX][MAX];
int state[MAX];

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void insert_queue(int vertex)
{
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int isEmpty_queue()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue()
{
    int delete_item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }

    delete_item = queue[front];
    front = front + 1;
    return delete_item;
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v] = waiting;
    printf("BFS: ");
    while (!isEmpty_queue())
    {
        v = delete_queue();
        printf("%d ", v);
        state[v] = visited;
        for (i = 0; i < n; i++)
        {
            if (flag == 1)
            {
                if (adj[v][i] == 1 && state[i] == initial)
                {
                    insert_queue(i);
                    state[i] = waiting;
                }
            }
            else
            {
                if (daj[v][i] == 1 && state[i] == initial)
                {
                    insert_queue(i);
                    state[i] = waiting;
                }
            }
        }
    }
    printf("\n");
}
void BF_Traversal()
{
    for (v = 0; v < n; v++)
        state[v] = initial;

    if (gap == 0)
    {
        printf("Type any element from where to start the path: \n");
        scanf("%d", &v);
        BFS(v);
    }
    if (gap == 1)
    {
        BFS(pd);
    }
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (top == MAX)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;
    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

void DFS(int v)
{
    int i, flg;
    push(v);
    state[v] = visited;
    printf("DFS: ");
    printf("%d ", v);
    while (!isempty())
    {
        flg = 0;
        v = peek();
        for (i = 0; i < n; i++)
        {
            if (flag == 1)
            {
                if (adj[v][i] == 1 && state[i] == initial)
                {
                    flg = 1;
                    push(i);
                    state[i] = visited;
                    printf("%d ", i);
                    break;
                }
            }
            else
            {
                if (daj[v][i] == 1 && state[i] == initial)
                {
                    flg = 1;
                    push(i);
                    state[i] = visited;
                    printf("%d ", i);
                    break;
                }
            }
        }
        if (flg == 0)
        {
            pop();
        }
    }
    printf("\n");
}

void DF_Traversal()
{
    for (v = 0; v < n; v++)
        state[v] = initial;

    if (gap == 0)
    {
        printf("Type any element from where to start the path: \n");
        scanf("%d", &v);
        DFS(v);
    }
    if (gap == 1)
    {
        DFS(pd);
    }
}

void create_and_display_graph()
{
    int count, max_edge, numbers[MAX], i, j, or = 0, de = 0, b = 0, arr[MAX], f, x = 0,mm;
    int save[18] = {0, 1, 0, 3, 1, 0, 1, 2, 2, 4, 3, 1, 5, 6, 6, 2, -1, -1};
    if (kk == 0)
    {
        printf("Enter number of nodes for the graph : ");
        scanf("%d", &n);
        printf("\nPlease enter numbers from 0 to 100. If you still want to input a number more than 100 change the definiton of MAX in macros.\n\n");
    }
    else
    {
        n = 7;
        printf("\n");
    }
    max_edge = n * (n - 1);
    for (i = 0; i < 100; i++)
    {
        numbers[i] = 0;
    }
    for (count = 1; count <= max_edge; count++)
    {
        if (kk == 0)
        {
            printf("Enter the no of nodes\n");
            scanf("%d",&mm);
            for(int i=0;i<mm;i++)
            {
            printf("Enter edge %d( -1 -1 to quit ) : ", count);
            scanf("%d %d", & or, &de);
            }
        }
        if (kk == 1)
        {
            or = save[x];
            de = save[x + 1];
            printf("Edge %d : %2d %2d\n", count, or, de);
            x += 2;
        }
        if ((or == -1) && (de == -1))
        {
            break;
        }
        else if (or >= n || de >= n || or < 0 || de < 0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            adj[or][de] = 1;
            daj[or][de] = 1;
            daj[de][or] = 1;
            for (i = 0; i < 100; i++)
            {
                if (i == or || i == de)
                {
                    numbers[i] = 1;
                }
            }
        }
    }
    f = 0;
    printf("\nDirected Graph:\n\n");
    printf(" ");
    for (i = 0; i < 100; i++)
    {
        if (numbers[i] == 1)
        {
            printf(" %2d", i);
            arr[f] = i;
            f++;
        }
    }
    printf("\n");
    f = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[f]);
        f++;
        for (j = 0; j < n; j++)
        {
            printf("%2d ", adj[i][j]);
        }
        printf("\n");
    }
    f = 0;
    printf("\nUndirected Graph:\n\n");
    printf(" ");
    for (i = 0; i < 100; i++)
    {
        if (numbers[i] == 1)
        {
            printf(" %2d", i);
            arr[f] = i;
            f++;
        }
    }
    printf("\n");
    f = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[f]);
        f++;
        for (j = 0; j < n; j++)
        {
            printf("%2d ", daj[i][j]);
        }
        printf("\n");
    }
    
}

void dir_BFS()
{
    printf("\nType Of Grammar : DIRECTED\n\t\t\t  BFS\n\n");
    BF_Traversal();
}

void dir_DFS()
{
    printf("\n\t\tType Of Grammar : DIRECTED\n\t\t\t  DFS\n\n");
    DF_Traversal();
}

void undir_BFS()
{
    printf("\n\t\tType Of Grammar : UNDIRECTED\n\t\t\t  BFS\n\n");
    BF_Traversal();
}

void undir_DFS()
{
    printf("\n\t\tType Of Grammar : UNDIRECTED\n\t\t\t  DFS\n\n");
    DF_Traversal();
}

int main()
{
    int n, m = 0;
    char ch[10], gh;
    char ph[] = "Directed";
    printf("\nLet's create the graph. Do you want to use the graph given in the assignment without actually typing everything[y/n]? ");
    scanf("%c", &gh);
    if (gh == 'y')
    {
        kk = 1;
        create_and_display_graph();
    }
    else
    {
        printf("\nPlease enter the DIRECTED graph (with arrows).\n\n");
        kk = 0;
        create_and_display_graph();
    }
    while (1)
    {
        printf("\nType any case (0:Quit || 1:Type of the Grammar || 2:BFS || 3:DFS\n");
        scanf("%d", &n);
        if (n == 0)
        {
            printf("Thank You, Good Bye!\n");
            break;
        }
        if (n == 1)
        {
            printf("\nWhile answering the following question you have two options: 'Undirected' or 'Directed'. Type it as it is.\n\nThe graph is ");
            scanf("%s", ch);
            if (strcmp(ch, ph) == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (flag == 1 && n == 2)
        {
            gap = 0;
            dir_BFS();
        }
        if (flag == 1 && n == 3)
        {
            gap = 0;
            dir_DFS();
        }
        if (flag == 0 && n == 2)
        {
            gap = 0;
            undir_BFS();
        }
        if (flag == 0 && n == 3)
        {
            gap = 0;
            undir_DFS();
        }
    }
}
