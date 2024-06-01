// Simpson 3/8th method for f = 1/1+ x^2 
// for a = 0 and b = 6, with 6 intervals, sum = 1.3507
#include<stdio.h>
#include<math.h>
double f(double x){
    return 1/(1+x*x);
}
int main(){
    int n, pos=1;
    double i,a,b,sum=0,h;
    printf("Enter the value of a and b: ");
    scanf("%lf %lf",&a,&b);
    printf("Enter the number of intervals: ");
    scanf("%d",&n);
    
    h=(b-a)/n;
    sum = f(a) + f(b);
    for(i=a+h;i<b;i=i+h){
       if(pos%3 ==0)
       {
           sum = sum + 2 * f(i);
           
       }
        else
         {
             sum = sum + 3 * f(i);
             
         }
         pos++;
    }
    sum = (3*h*sum)/8;
    printf("Value of the integral = %lf",sum);
}
