// to fit curve for the power of functioin .
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int i, n;
    float x[100], y[100], sumx = 0, sumy = 0, sumxx = 0, sumxy = 0, a, b, A;
    printf("Enter the number of data sets:");
    scanf("%d", &n);
    printf("Input x and y :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
        x[i] = log(x[i]);
        y[i] = log(y[i]);
    }

    for (i = 1; i <= n; i++)
    {
        sumx += x[i];
        sumxy += x[i] * y[i];
        sumxx += pow(x[i], 2);
        sumy += y[i];
    }
    A = (sumy * sumxx - sumxy * sumx) / (n * sumxx - sumx * sumx);
    b = (sumxy * n - sumy * sumx) / (n * sumxx - sumx * sumx);
    a = exp(A);
    printf("the required equation is y=%fx^%f ", a, b);
    return 0;
}
