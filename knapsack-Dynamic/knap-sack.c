
#include<stdio.h>
int val[] = {3,4,5,6};
int wt[] = {2,3,4,5};
int K[20][20];
int  W =5 ;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int knapsack(int n)
{
   int i, w,j;



    printf("\t    KNAPSACK USING DYNAMIC APPROACH\n\n");
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
    printf("  w   v\n");
    for(i=0;i<=n;i++)
        printf("%3d %3d\n",wt[i],val[i]);
     printf("\n\nMATRIX:\n\n");



     printf("    ");
   for(i=0;i<=W;i++)
        printf("%3d ",i);
         printf("\n\n");

   for(i=0;i<=n;i++)
   {
        printf("%3d ",i);
       for(j=0;j<=W;j++)
        printf("%3d ",K[i][j]);
       printf("\n");
   }

   return K[n][W];
}

void backtrack(n)
{
    int i=n,j=W;
    while(i>0 && j>0)
    ///if(above cell <= left side value)
    if(K[i-1][j]<=K[i-1][j-wt[i-1]])
        j-=wt[i-1],i--,printf("\nitem no=%d =>%d %d",i,wt[i],val[i]);
    else
        i--;
    ///else
}
int main()
{

    int n = sizeof(val)/sizeof(val[0]);
    printf("\nMaximum value:%d", knapsack(n));
    backtrack(n);
    return 0;
}
