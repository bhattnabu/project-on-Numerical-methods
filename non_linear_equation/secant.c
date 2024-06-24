// Program to find the solutions of the non linear equation using secant method....
// eqation is xsinx+cosx....
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (((1 / pow(x, 5)) + cos(x) + 0.5));
}
int main()
{
    float a, b, c, req_pre;
    int count = 0;
    printf("Enter the initial guesses:\n ");
    scanf("%f,%f", &a, &b);
    printf("Enter the reqired precision :\t");
    scanf("%f", &req_pre);
    c = (a * f(b) - b * f(a) / f(b) - f(a));
    if (f(a) == f(b))
    {
        printf("Mathmatical error.");
    }
    else
    {
        while (fabs(f(c)) > req_pre)
        {

            printf("a=%f,b=%f,c=%f,f_n=%f\n", a, b, c, f(c));
            a = b;
            b = c;
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            count++;
        }
        printf("x=%f,f_n=%f\n", c, f(c));
        printf("The reqired number of the iteration is %d", count);
    }
    return 0;
}