#include <stdio.h>
#include <conio.h>
#include <math.h>
//#define f(x,y,z) 1+x*z
//#define g(x,y,z) (-x*y)
#define f(x, y, z) 1 + x *z
#define g(x, y, z) -x *y
int main()
{
    float x0, y0, z0, xn, yn, zn, h, k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    int i, n;
    //printf("\nDiff. Equations: dy/dx = 1+xz, dz/dx = -xy\n\n");
    printf("\nDiff. Equations: dy/dx = x-z, dz/dx = x+y^2\n\n");
    printf("Enter Initial Condition\n");
    printf("x0, y0, z0 : ");
    scanf("%f %f %f", &x0, &y0, &z0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter no of step size: ");
    scanf("%d", &n);
    h = (xn - x0) / n;
    printf("\nx0\t\ty0\t\tyn\t\tzn\n");
    printf(".........................................................\n");
    for (i = 0; i < n; i++)
    {
        k1 = h * (f(x0, y0, z0));
        l1 = h * (g(x0, y0, z0));
        k2 = h * (f((x0 + h / 2), (y0 + k1 / 2), (z0 + l1 / 2)));
        l2 = h * (g((x0 + h / 2), (y0 + k1 / 2), (z0 + l1 / 2)));
        k3 = h * (f((x0 + h / 2), (y0 + k2 / 2), (z0 + l2 / 2)));
        l3 = h * (g((x0 + h / 2), (y0 + k2 / 2), (z0 + l2 / 2)));
        k4 = h * (f((x0 + h), (y0 + k3), (z0 + l3)));
        l4 = h * (g((x0 + h), (y0 + k3), (z0 + l3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        yn = y0 + k;
        zn = z0 + l;
        printf("%0.4f\t\t%0.4f\t\t%0.4f\t\t%.4f\n", x0, y0, yn, zn);
        x0 = x0 + h;
        y0 = yn;
        z0 = zn;
    }
    printf("\nValue of y at x = %0.4f is %0.4f", xn, yn);
    printf("\nValue of z at x = %0.4f is %0.4f", xn, zn);
    getch();
    return 0;
}