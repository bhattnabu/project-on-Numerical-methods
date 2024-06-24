#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
float f( int x){
    return  (x*sin(x));
}

void main(){
    int subinterval, i;
    float lower, upper, integration = 0, stepsize, k;
    printf("Enter the lower inteval:");
    scanf("%f",&lower);
    printf("Enter the upper inteval:");
    scanf("%f",&upper);
    printf("Enter the subinterval:");
    scanf("%d",&subinterval);
stepsize=(upper-lower);
integration=f(upper)+f(lower);
for(i=1;i<=subinterval;i++){
    k=lower+i*stepsize;
    integration+=2*f(k);
}
integration=(integration*stepsize)/2;
printf("the required value of the area is %.4f",integration);

}
