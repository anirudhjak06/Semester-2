#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int Smatrix(int m, int mat[m][m])
{
    int array[m + 1][m + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                array[i][j] = 0;
            else
                array[i][j] = array[i - 1][j] + array[i][j - 1] - array[i - 1][j - 1] +
                            mat[i - 1][j - 1];
        }
    }

    int s = 0,e = 0,st = 0,en = 0, c = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            for (int p = 0; p < m; p++)
            {
                for (int q = p; q< m; q++)
                {
                    int sums = array[j + 1][q + 1] - array[j + 1][p] - array[i][q + 1] + array[i][p];
                    if (sums == 1)
                    {
                        c++;
                        s = i;
                        e = j;
                        st = p;
                        en = q;
                    }
                }
            }
        }
    }
    return c;
}

int main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    int arr[n][n];
    printf("\nEnter the array elements : \n");
    printf("Hit Enter after each line containing %d elements :\n",n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
    printf("Output : %d\n", Smatrix(n, arr));
}