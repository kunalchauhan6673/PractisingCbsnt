#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j,fact;
    double dtable[100][100],x,y,u,u1;
    
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("\nEnter the values of X: ");
    for(i=0;i<n;i++){
        scanf("%lf",&dtable[i][0]);
    }
    printf("\nEnter the values of Y: ");
    for(i=0;i<n;i++){
        scanf("%lf",&dtable[i][1]);
    }
    // finding the difference table 
    for(j=2;j<n+1;j++){
        for(i=0;i<=n-j+1;i++){
            dtable[i][j]=dtable[i+1][j-1]-dtable[i][j-1];
            // for i = 0, j=2 => d[0][2] = d[1][1] - d[0][1]
        }
    }
    // printing the difference table
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            printf("| %lf ",dtable[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the X for which you want to find Y: ");
    scanf("%lf",&x);
    
    
    // newton's backward interpolation 
    // finding u
    u = (x - dtable[n-1][0])/(dtable[1][0]-dtable[0][0]);
    // initial y,y1,k
    y = dtable[n-1][1];
    u1= u;
    fact = 1;
    j=2; // represents column, whch will be used everywhere inside i loop, in place of j
    for(i = n-2;i>=0;i--){
        y = y + (u1 * dtable[i][j])/fact;
        // update k, u1
        fact*=j;
        u1 = u1*(u+(j-1));
        j++;
    }
    printf("\nValue of Y at X = %lf is %lf",x,y);
    return 0;
}
