#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float a[10][10], factor;
    int i, j, k, n;
    float sum;
    printf("How many numbers of the elements matrix  of the :");
    scanf("%d", &n);
    printf("Enter the elements of the augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    // forward Elimination
    for (j = 1; j <= n - 1; j++)
    {
        if (a[j][j] == 0.0)
        {
            printf("mathematical error");
            exit(0);
        }
        else
        {
            for (i = j + 1; i <= n; i++)
            {
                factor = a[i][j] / a[j][j];

                for (k = 1; k <= n + 1; k++)
                {
                    a[i][k] = a[i][k] - factor * a[j][k];
                }
            }
        }
    }
    // Back substitution
    float x[10];
    x[n] = a[n][n + 1] / a[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        sum = 0.0;
        for (j = i + 1; j <= n; j++)
            sum = sum + a[i][j] * x[j];

        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }

    for (i = 1; i <= n; i++)
    {
        printf("\n\tx[%1d]=%10.4f", i, x[i]);
    }
    return 0;
}
