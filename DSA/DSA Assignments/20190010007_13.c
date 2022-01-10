#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

struct edge
{
	int u;
	int v;
};

int n;
int adj[MAX][MAX];

int predecessor[MAX];
int status[MAX];
int length[MAX];

void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();

void maketree(int r, struct edge tree[MAX])
{
	int current, i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		predecessor[i] = NIL;
		length[i] = infinity;
		status[i] = TEMP;
	}
	length[r] = 0;
	while (1)
	{
		current = min_temp();

		if (current == NIL)
		{
			if (count == n - 1)
				return;
			else
			{
				printf("\nGraph is not connected, No spanning tree possible\n");
				exit(1);
			}
		}

		status[current] = PERM;
		if (current != r)
		{
			count++;
			tree[count].u = predecessor[current];
			tree[count].v = current;
		}

		for (i = 0; i < n; i++)
			if (adj[current][i] > 0 && status[i] == TEMP)
				if (adj[current][i] < length[i])
				{
					predecessor[i] = current;
					length[i] = adj[current][i];
				}
	}
}

int min_temp()
{
	int i;
	int min = infinity;
	int k = -1;

	for (i = 0; i < n; i++)
	{
		if (status[i] == TEMP && length[i] < min)
		{
			min = length[i];
			k = i;
		}
	}

	return k;
}

void create_graph()
{
	int i, mm, origin, destin, wt;
	printf("\nEnter number of vertices : ");
	scanf("%d", &n);
	printf("Enter the no of edges : ");
	scanf("%d", &mm);
	for (i = 0; i < mm; i++)
	{
		printf("\nEnter edge %d ( 0 0 ) to quit : ", i + 1);
		scanf("%d %d", &origin, &destin);
		if ((origin == 0) && (destin == 0))
			break;
		printf("\nEnter weight for this edge : ");
		scanf("%d", &wt);
		if (origin >= n || destin >= n || origin < 0 || destin < 0)
		{
			printf("\nInvalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin] = wt;
			adj[destin][origin] = wt;
		}
	}
}

void display()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%4d", adj[i][j]);
		printf("\n");
	}
}

int main()
{
	int wt_tree = 0;
	int i, root, j;
	int spanning_tree[MAX][MAX];
	struct edge tree[MAX];

	create_graph();
	printf("\nAdjacency matrix of the following is\n");
	display();
	printf("\nEnter the starting node : ");
	scanf("%d", &root);

	maketree(root, tree);

	printf("\nThe Minimum Spanning Tree for the above graph is : \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			spanning_tree[i][j] = 0;
		}
	}
	printf("\nAdjacency list of the spanning tree is\n\n");
	for (i = 1; i <= n - 1; i++)
	{
		printf("%d-> ",tree[i].u);
		printf("%d\n",tree[i].v);
		
		wt_tree += adj[tree[i].u][tree[i].v];
	}
	printf("\n\t\t\tOR\n\nAdjacency matrix of the spanning tree is\n\n");
	for (int j = 1; j <= n - 1; j++)
	{
		spanning_tree[tree[j].u][tree[j].v] = adj[tree[j].u][tree[j].v];
		spanning_tree[tree[j].v][tree[j].u] = adj[tree[j].u][tree[j].v];
		wt_tree += adj[tree[j].u][tree[j].v];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", spanning_tree[i][j]);
		}
		printf("\n");
	}
	printf("\nWeight of spanning tree is : %d\n\n", wt_tree);
	return 0;
}
