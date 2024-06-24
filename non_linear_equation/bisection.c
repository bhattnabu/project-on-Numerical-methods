// Program to find the roots of the given non-linear equations using bisection method
// the equation used here is xsinx+cosx....
#include <stdio.h>
#include <math.h>
float fun(float x)
{
    return (x*x-1);
}
int main()
{
    float a, b, c, re_pre;
    int count = 0;
    printf("Enter the number of the range :");
    scanf("%f,%f", &a, &b);
    printf("Enter the reqired precision");
    scanf("%f", &re_pre);
    c = (a + b) / 2;
    while (fabs(fun(c)) > re_pre){
        printf("a=%.5f,b=%.5f,c=.5%f,f_n=%.5f\n", a, b, c, fun(c));
        if (fun(a) * fun(c) > 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
        c = (a + b) / 2;
        count++;
    }
    printf("x=%.5f,f_n=%.5f", c, fun(c));
    printf("The number of the iteration is %d ", count);
    return 0;
    }
