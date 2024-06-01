#include<stdio.h>
#include<math.h>
#define e 0.0001
double f(double x){
  return (x*x*x)-(2*x)-5;
}
double df(double x){
  return (3*x*x)-2;
}
int main(){
 int n;
 double x1,x2,x0,x;
 printf("Enter the max number of iterations: ");
 scanf("%d",&n);

 do{
    printf("Enter two numbers: ");
    scanf("%lf %lf",&x1,&x2);
    if(f(x1)*f(x2)>=0)
    {
        printf("Invalid values!!");
        continue;
    }
    else{
        printf("\nThe roots lies between %lf and %lf ",x1,x2);
        break;
       }

 }while(1);

 if(fabs(f(x1)) < fabs(f(x2)))
 {
    x0 = x1;
 }
 else if(fabs(f(x1)) > fabs(f(x2)))
 {
    x0 = x2;
 }

 for(int i=1;i<=n;i++){
     x = x0 - (f(x0)/df(x0));

     if(fabs(x-x0) < e)
     {
        printf("\nThe iteration is %d and the root is %lf",i,x);
        printf("\nHence, The root is %lf ",x);
        return 0;
     }
     x0 = x;
     printf("\nThe iteration is %d and the root is %lf",i,x);
 }
 return 0;
}
