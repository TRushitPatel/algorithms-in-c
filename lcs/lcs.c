#include<stdio.h>

int max(int a, int b);
int z[10][10];

int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     {z[m-1][n-1]+=1;return 1 + lcs(X, Y, m-1, n-1);}
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}


int max(int a, int b)
{
    return (a > b)? a : b;
}


int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
int i,j;
  int m = strlen(X);
  int n = strlen(Y);

    printf("Length of LCS is %d\n\n", lcs( X, Y, m, n ) );
    printf("   ");
    for(i=0;i<m;i++)
        printf("%2c ",X[i]);
    printf("\n\n");
    for(i=0;i<n;i++){
        printf("%2c ",Y[i]);
        for(j=0;j<m;j++)
            printf("%2d ",z[i][j]);
            printf("\n\n");
    }
  return 0;
}
