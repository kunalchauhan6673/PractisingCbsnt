// X | 1931 | 1941 | 1951 | 1961 | 1971 | 1981 | 
// Y |  12  |  15  |  20  |  27  |  39  |  52  |
// find 1934, y=? ans: 12.23...
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
    
    // finding u
    u = (x - dtable[0][0])/(dtable[1][0]-dtable[0][0]);
    // initial y,y1,k
    y = dtable[0][1];
    u1= u;
    fact = 1;
    for(i = 2;i<=n;i++){
        y = y + (u1 * dtable[0][i])/fact;
        // update k, u1
        fact*=i;
        u1 = u1*(u-(i-1));
    }
    printf("\nValue of Y at X = %lf is %lf",x,y);
    return 0;
}
