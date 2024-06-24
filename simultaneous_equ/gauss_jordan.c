#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void printMatrix(float a[MAX][MAX], int n);

int main()
{
    float a[MAX][MAX], ratio;
    int i, j, k, n;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the augmented matrix row-wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Applying Gauss-Jordan Elimination
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error: Division by zero\n");
            exit(0);
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }
        // Print matrix at each step (optional)
        printMatrix(a, n);
    }

    // Obtaining the solution
    float x[MAX];
    for (i = 0; i < n; i++)
    {
        x[i] = a[i][n] / a[i][i];
    }

    // Displaying the solution
    printf("\nThe solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %0.4f\n", i, x[i]);
    }

    return 0;
}

void printMatrix(float a[MAX][MAX], int n)
{
    int i, j;
    printf("\nMatrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%0.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
