//regula fasi method means that method of the false position.
#include <stdio.h>
#include <math.h>
float fn(float x)
{
    return (pow(x, 3) - 3 * pow(x, 2) + 3 * x - 2);
}

int main()
{
    float a, b, c, req_pre;
    int count = 0;
    printf("Please enter the intial guess\n");
    scanf("%f\n%f", &a, &b);
    printf("Enter the reqired precion");
    scanf("\t%f", &req_pre);
    c = (a * fn(b) - b * fn(a)) / (fn(b) - fn(a));
    while (fabs(fn(c)) > req_pre)
    {
        printf("a=%f,b=%f,c=%f,f_x=%f\n", a, b, c, fn(c));
        if (fn(c) * fn(a) > 0)
            a = c;
        else
            b = c;
        c = (a * fn(b) - b * fn(a)) / (fn(b) - fn(a));
        count += 1;
    }
    printf("x=%f,f_x=%f\n", c, fn(c));
    printf("The required number of the iteration is :%d", count);
    return 0;
}