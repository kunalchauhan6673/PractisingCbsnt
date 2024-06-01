// secand method for eq: x^3 - 2x^2 - 5
#include<stdio.h>
#include<math.h>
#define e 0.001
double f(double x){
    return (x*x*x)-(2*x*x)-5;
}
double secand(double a,double b){
    return ((a*f(b))-(b*f(a)))/(f(b)-f(a));
}
int main(){
    int n;
    double x1,x2,x3;
    printf("Enter the number of max iterations: ");
    scanf("%d",&n);
    printf("\nEnter n1 and n2: ");
    scanf("%lf %lf",&x1,&x2);
    printf("\nThe roots are between %lf and %lf",x1,x2);
    x3 = secand(x1,x2);
    for(int i=0;i<n;i++){
        x1 = x2;
        x2 = x3;
        x3 = secand(x1,x2);
        if(fabs(x3-x2)< e){
            printf("\nThe Iteration is %d and the root is %lf",i,x3);
            printf("\nHence, the root is %lf",x3);
            return 0;
        }
        printf("\nThe Iteration is %d and the root is %lf",i,x3);
    }
    
}
