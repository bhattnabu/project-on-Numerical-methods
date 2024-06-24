#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    float a[10][10], ratio;
    int i, j, n, k;
    printf("Enter the order of the matrix for the inverse :\t");
    scanf("%d", &n);
    printf("\nEnter the elements of the matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);
    }
    //Augmented form of the given matrix as the jordan method:::
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                a[i][j + n] = 1;
            else
                a[i][j + n] = 0;
        }
    }
    /*applying the jordan elimination in the given matrix*/
    for (j = 1; j <= n; j++)
    {
        if (a[j][j] == 0)
        {
            printf("The principal of pivoting is not clear :::");
            exit(0);
        }
        for (i = 1; i <= n; i++)
        {
            if (i != j)
            {
                ratio = a[i][j] / a[j][j];
                for (k = 1; k <= 2 * n; k++)
                {
                    a[i][k] = a[i][k] - ratio * a[j][k];
                }
            }
        }
    }
    //converting the principal elements of diagonal  to unit for unit matrix....
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }
    }
    printf(" The inverse matrix of the given matrix ::::\n");
    for (i = 1; i <= n; i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            printf("%.3f\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}