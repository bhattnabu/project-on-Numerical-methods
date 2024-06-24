#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void printmat(float mat[100][100], int r, int c)
{
    int i, j;
    printf("\n");
    for (i = 0; i < r; i++)
    {
        printf(" [");
        for (j = 0; j < c; j++)
            printf("  %+15.1f", mat[i][j]);
        printf(" ]\n");
    }
}

int main()
{
    int n, d, i, j, k;
    float x[100], y[100], m[100][100], r;

    // Input Data
    printf("Enter the number of data sets: ");
    scanf("%d", &n);
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &d);

    // Ensure n > d
    if (n <= d)
    {
        printf("The number of data points must be greater than the degree of the polynomial.\n");
        exit(0);
    }

    printf("Enter the elements of x and y:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }

    // Initialize Augmented Coefficient Matrix
    for (i = 0; i <= d; i++)
    {
        m[i][d + 1] = 0;
        for (j = 0; j <= d; j++)
        {
            m[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                m[i][j] += pow(x[k], i + j);
            }
        }
        for (k = 0; k < n; k++)
        {
            m[i][d + 1] += pow(x[k], i) * y[k];
        }
    }

    // Gauss-Jordan Elimination
    printmat(m, d + 1, d + 2); // Debug Print
    for (j = 0; j <= d; j++)
    {
        for (i = 0; i <= d; i++)
        {
            if (j != i)
            {
                r = m[i][j] / m[j][j];
                for (k = 0; k <= d + 1; k++)
                {
                    m[i][k] = m[i][k] - r * m[j][k];
                }
            }
        }
        printmat(m, d + 1, d + 2); // Debug Print
    }

    // Print the coefficients of the polynomial
    printf("\ny = f(x) = ");
    for (i = 0; i <= d; i++)
    {
        x[i] = m[i][d + 1] / m[i][i];
        printf(" %+.4f x^(%d)", x[i], i);
        if (i < d)
        {
            printf(" +");
        }
    }
    printf("\n");

    getch();
    return 0;
}
