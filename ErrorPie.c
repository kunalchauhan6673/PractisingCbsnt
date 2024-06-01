// error in the value of pie
#include<stdio.h>
#include<math.h>
#define pie 3.14
int main(){
    double relativeError, absoluteError, percentError;
    double epie = 22.0/7;
    absoluteError = fabs(pie - epie);
    relativeError = absoluteError/pie;
    percentError = relativeError * 100;
    printf("The Absolute error is %lf,\nThe relative error is %lf,\nThe Percentage Error is %lf", absoluteError, relativeError, percentError);
    return 0;
}
