// regularFalsi method for eq: x^3 - 2x^2 - 5
#include<stdio.h>
#include<math.h>
#define e 0.001
double f(double x){
    return (x*x*x)-(2*x*x)-5;
}
double rf(double a,double b){
    return ((a*f(b))-(b*f(a)))/(f(b)-f(a));
}
int main(){
    int n;
    double x1,x2,x;
    printf("Enter the number of max iterations: ");
    scanf("%d",&n);
    do{
        printf("\nEnter n1 and n2: ");
        scanf("%lf %lf",&x1,&x2);
        if(f(x1)*f(x2)>=0)
        {
            printf("Invalid Roots");
            continue;
        }
        else
        {
            printf("\nThe roots are %lf and %lf",x1,x2);
            break;
        }
    }while(1);
    for(int i=0;i<n;i++){
        x = rf(x1,x2);
        if(f(x)*f(x1)<0) // iska matlab x positive h, replace x2 with x
        {
            x2 = x;
        }
        else {
            x1 = x;
        }
        double x4 = rf(x1,x2);
        if(fabs(x4-x)< e){
            printf("\nThe Iteration is %d and the root is %lf",i,x);
            printf("\nHence, the root is %lf",x);
            return 0;
        }
        printf("\nThe Iteration is %d and the root is %lf",i,x);
    }
    
}
