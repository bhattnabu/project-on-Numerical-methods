#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x){
    return (1/sqrt(1+x));
}
int main(){
    int subinterval,i;
    float upper,lower,stepsize,integration=0,k;
    printf("Enter the lower the interval:");
    scanf("%f",&lower);
    printf("Enter the upper the interval:");
    scanf("%f",&upper);
    printf("Enter the subinterval the interval:");
    scanf("%d",&subinterval);
    //calculation of stepsize
    stepsize=(upper-lower)/subinterval;
    integration=f(upper)+f(lower);
    for(i=1;i<=subinterval-1;i++){
        k=i*stepsize+lower;
        if(i%3==0)
        integration=integration+2*f(k);
        else
        integration+=3*f(k);
    }
    integration=(integration*3*stepsize)/8;
    printf("The required area is %.3f",integration);
    return 0;
}


