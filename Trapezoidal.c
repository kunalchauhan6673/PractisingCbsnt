// Trapezoidal method for f = x^3 
// for a = 0 and b = 1, with 5 intervals, sum = 0.26
#include<stdio.h>
#include<math.h>
double f(double x){
    return x*x*x;
}
int main(){
    int n;
    double i,a,b,sum=0,h;
    printf("Enter the value of a and b: ");
    scanf("%lf %lf",&a,&b);
    printf("Enter the number of intervals: ");
    scanf("%d",&n);
    
    h=(b-a)/n;
    sum = f(a) + f(b);
    for(i=a+h;i<b;i=i+h){
        sum = sum + 2 * f(i);
    }
    sum = (h*sum)/2;
    printf("Value of the integral = %lf",sum);
}
