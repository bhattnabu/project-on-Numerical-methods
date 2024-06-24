#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void  matprint( float a[10],int r){
    int i;
    printf("\n");
    for(i=1;i<=r;i++){
        printf("[");
            printf("%+15.1f",a[i]);
        printf("]\n");
        }
}
int main()
{
    float a[10][10], pre, x[10], b[10], e[10], emax, bmax;
    int i, j, n;
    printf("Enter the size of the matrix:\t");
    scanf("%d", &n);
    printf("Enter the reqired precision :\t");
    scanf("%f", &pre);
    printf("\nEnter the elements of the matrix whose eigen value is to be found:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter the intial guess for the column matrix:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }
    do
    {
        for (i = 1; i <= n; i++)
        {
            b[i] = 0;
            for (j = 1; j <= n; j++)
            {
                b[i] = b[i] + a[i][j] * x[j];
            }
        }
             matprint(b, n);
        bmax = fabs(b[1]);
        for (i = 2; i <= n; i++)
        {
            if (bmax < fabs(b[i]))
                bmax = fabs(b[i]);
        }
        for (i = 1; i <= n; i++)
        {
            b[i] = b[i] / bmax;
        }
        for (i = 1; i <= n; i++)
        {
            e[i] = 0;
            e[i] = fabs(fabs(b[i]) - fabs(x[i]));
        }
        emax = e[1];
        for (i = 1; i <= n; i++)
        {
            if (emax < e[i])
                emax = e[i];
        }


        for (i = 1; i <= n; i++)
            x[i] = b[i];
    } while (emax > pre);
    printf("\nThe required eigen value is %f ", bmax);
    printf("\nthe required eigen vector is:\n");
    for (i = 1; i <= n; i++)
        printf("%f\t", b[i]);
    return 0;
}
