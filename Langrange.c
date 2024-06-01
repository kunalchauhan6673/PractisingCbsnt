// Lagrange method
#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j;
    printf("enter the number of terms: ");
    scanf("%d",&n);
    double X[n],Y[n],x,sum=0,term;
    
    printf("Enter the values of X: ");
    for(i=0;i<n;i++){
        scanf("%lf",&X[i]);
    }
    printf("Enter the values of Y: ");
    for(i=0;i<n;i++){
        scanf("%lf",&Y[i]);
    }
    printf("Enter the value of x for which you need to find y: ");
    scanf("%lf",&x);
    
    for(i=0;i<n;i++){
        term = 1;
        for(j=0;j<n;j++){
            if(i!=j){
                term = term * ((x-X[j])/(X[i]-X[j]));
            }
        }
         sum = sum + term * Y[i];
    }
    printf("\nValue of Y at X = %lf is %lf",x,sum);
    return 0;
}
