//Program to find the root of the non-linear equation using the Newton raphson method
//solution of the x^3-10....
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
/*float f(float x)
{
    return (x*x+7*x-10);
}
float df(float x)
{
    return (2*x+7);
}*/
#define f(x) (x*x+7*x-10)
#define df(x) (2*x+7)
int main()
{
    float a, b, req_pre;
    int count = 0,n=100;
    printf("Please enter the intial guess:\t");
    scanf("%f", &a);
    printf("Enter the reqired precion:\t");
    scanf("\t%f", &req_pre);
    b = a - (f(a) / df(a));

    while (fabs(f(a)) > req_pre)
    {
        printf("a=%f,b=%f,f_x=%f\n", a, b, f(b));
        a = b;
        b = a - (f(a) / df(a));
        count += 1;
        if (count>n){
            printf("not the convergent solution exist ");
            exit (0);
        }
    }
    printf("x=%f,f_x=%f\n", b, f(b));
    printf("The required solution is %f\n",b);
    printf("The required number of the iteration is :%d", count);
    return 0;
}
