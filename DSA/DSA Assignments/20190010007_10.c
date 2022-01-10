#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
int delimit = -9999;
int pr = 0, in = 0, po = 0, no = 0, deo = 0, zo = 0, deo_2;
int preo[31], ino[31], posto[31], c[31], neo[31], deor[31], zeo[31];

typedef struct node
{
	struct node *left;
	struct node *right;
	int data;
} node;

node *tree = NULL;
node *temp = NULL;

node *insert(int c[], int n)
{
	node *tree = NULL;
	if (c[n] != delimit)
	{
		tree = (node *)malloc(sizeof(node));
		tree->left = insert(c, 2 * n + 1);
		tree->data = c[n];
		tree->right = insert(c, 2 * n + 2);
	}
	return tree;
}

void printPostorder(node *node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	posto[po] = node->data;
	po++;
}

void printInorder(node *node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	ino[in] = node->data;
	in++;
	printInorder(node->right);
}

void printPreorder(node *node)
{
	if (node == NULL)
		return;
	preo[pr] = node->data;
	pr++;
	printPreorder(node->left);
	printPreorder(node->right);
}

void display(node *root, int space)
{
	if (root == NULL)
		return;
	space += COUNT;
	display(root->right, space);
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);
	display(root->left, space);
}

void print(node *root)
{
	display(root, 0);
}

int getLevelUtil(struct node *node, int data, int level)
{
	if (node == NULL)
		return 0;

	if (node->data == data)
		return level;

	int downlevel = getLevelUtil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = getLevelUtil(node->right, data, level + 1);
	return downlevel;
}

int getLevel(struct node *node, int data)
{
	return getLevelUtil(node, data, 1);
}

void checkNode(node *node)
{
	if (node == NULL)
		return;
	if (node->left != NULL || node->right != NULL)
	{
		if (node->left == NULL && node->right != NULL)
		{
			printf("%d\t\tN/A\t\t%d\n", node->data, (node->right)->data);
		}
		if (node->right == NULL && node->left != NULL)
		{
			printf("%d\t\t%d\t\tN/A\n", node->data, (node->left)->data);
		}
		else
		{
			printf("%d\t\t%d\t\t%d\n", node->data, (node->left)->data, (node->right)->data);
		}
	}
	checkNode(node->left);
	checkNode(node->right);
}

void singleNode(node *node)
{
	if (node == NULL)
		return;
	if (node->left != NULL || node->right != NULL)
	{
		if (node->left == NULL && node->right != NULL)
		{
			deor[deo] = node->data;
			deo++;
		}
		if (node->right == NULL && node->left != NULL)
		{
			deor[deo] = node->data;
			deo++;
		}
		else
		{
			zeo[zo] = node->data;
			zo++;
		}
	}
	else
	{
		neo[no] = node->data;
		no++;
	}
	singleNode(node->left);
	singleNode(node->right);
}

void searchNode(node *node, int val)
{
	if (node == NULL)
		return;
	if ((node->data) == val)
	{
		if (node->left == NULL && node->right != NULL)
		{
			deo_2 = (node->right)->data;
			return;
		}
		if (node->right == NULL && node->left != NULL)
		{
			deo_2 = (node->left)->data;
			return;
		}
	}
	searchNode(node->left, val);
	searchNode(node->right, val);
}

void problem1()
{
	node *pree = NULL;
	node *iree = NULL;
	node *poree = NULL;
	int i, n, m;
	printf("Enter the total number of elements that the tree must have: ");
	scanf("%d", &n);
	m = (2 * n) + 2;
	printf("Enter the numbers: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (i = n; i < m; i++)
	{
		c[i] = delimit;
	}
	tree = insert(c, 0);
	printf("Original tree: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
	printf("\nPREODER traversal of binary tree is: ");
	printPreorder(tree);
	for (i = 0; i < pr; i++)
	{
		printf("%d ", preo[i]);
	}
	for (i = pr; i < m; i++)
	{
		preo[i] = delimit;
	}
	pree = insert(preo, 0);
	printf("\n(Tilt your head to your left to see the printed level-order tree for preOrder traversal of the given tree)");
	print(pree);
	printf("\nINORDER traversal of binary tree is: ");
	printInorder(tree);
	for (i = 0; i < in; i++)
	{
		printf("%d ", ino[i]);
	}
	for (i = in; i < m; i++)
	{
		ino[i] = delimit;
	}
	iree = insert(ino, 0);
	printf("\n(Tilt your head to your left to see the printed level-order tree for InOrder traversal of the given tree)");
	print(iree);
	printf("\nPOSTORDER traversal of binary tree is: ");
	printPostorder(tree);
	for (i = 0; i < po; i++)
	{
		printf("%d ", posto[i]);
	}
	for (i = po; i < m; i++)
	{
		posto[i] = delimit;
	}
	poree = insert(posto, 0);
	printf("\n(Tilt your head to your left to see the printed level-order tree for PostOrder traversal of the given tree)");
	print(poree);
}
void problem2()
{
	int key, x;
	printf("Please enter the element you wish to find the level of ");
	scanf("%d", &key);
	x = getLevel(tree, key);
	if (x != 0)
	{
		printf("Level of %d is %d\n", key, x);
	}
	else
	{
		printf("The element you entered was not found in the tree. Please enter a valid element.\n");
	}
}

void problem3()
{
	int i, max, j, p, temp, val;
	printf("\t\tTABULAR REPRESENTATION OF A TREE\n\n");
	printf("Have a look at the Original tree:");
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
	printf("\nITEM\t    LEFT CHILD\t   RIGHT CHILD\n");
	if (pr == 1)
	{
		printf("%d\t\tN/A\t\tN/A\n", tree->data);
		return;
	}
	checkNode(tree);
}

void problem4()
{
	int key, i, m, val, j, k;
	printf("\n\n\t\tINSERTION OF A NODE\n\n");
	printf("Have a look at the Original tree:");
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
	printf("Enter the element for insertion: ");
	scanf("%d", &key);
	c[pr] = key;
	m = (2 * pr) + 3;
	for (i = pr + 1; i < m; i++)
	{
		c[i] = delimit;
	}
	tree = insert(c, 0);
	printf("Have a look at the New tree:");
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
	printf("\n\n\t\tDELETION OF A NODE\n\n");
	printf("Have a look at the Original tree:");
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
	printf("\n*NOTE*  Do not enter any integer which has occured more than once in the tree.\n\n");
	printf("Enter the element for deletion: ");
	scanf("%d", &val);
	singleNode(tree);
	for (i = 0; i < no; i++)
	{
		if (neo[i] == val)
		{
			for (j = 0; j < pr + 1; j++)
			{
				if (c[j] == val)
				{
					c[j] = delimit;
					break;
				}
			}
			break;
		}
	}
	for (i = 0; i < deo; i++)
	{
		if (deor[i] == val)
		{
			searchNode(tree, deor[i]);
			for (j = 0; j < pr + 1; j++)
			{
				if (c[j] == val)
				{
					for (k = 0; k < pr + 1; k++)
					{
						if (c[k] == deo_2)
						{
							c[k] = delimit;
							break;
						}
					}
					c[j] = deo_2;
					break;
				}
			}
			break;
		}
	}
	for (i = 0; i < zo; i++)
	{
		if (zeo[i] == val)
		{
			printf("\nSince you have a selected a node with two children,\nthe leftmost (leaf) node will be substitued in place of the node you selected\n\n");
			for (j = 0; j < pr + 1; j++)
			{
				if (c[j] == val)
				{
					for (k = 0; k < pr + 1; k++)
					{
						if (c[k] == neo[0])
						{
							c[k] = delimit;
							break;
						}
					}
					c[j] = neo[0];
					break;
				}
			}
			break;
		}
	}
	tree = insert(c, 0);
	printf("Have a look at the New tree:");
	printf("\n(Tilt your head to your left to see the printed binary tree)");
	print(tree);
    printf("\n---------------------------------------------------------------------\n");
    printf("\n\t\tTHE END\n\n");
}

int main()
{
	problem1();
	problem2();
	problem3();
	problem4();
}
