#include<stdio.h>
int Max=11;
int deno[11];
int mat[20][20];
int no_deno;

void making_change()
{
int i,j,temp;

    for(i=0;i<=Max;i++)
        mat[i][0]=0;
    for(i=0;i<=no_deno;i++)
        mat[0][i]=0;


    for(i=1;i<=no_deno;i++)
        for(j=1;j<=Max;j++)
            if(i==1 && j<deno[i])//not possible
                mat[i][j]=0;
            else if(i==1)
                mat[i][j]=1+mat[i][j-deno[i]];
            else if(j<deno[i])
                mat[i][j]=mat[i-1][j];
            else
            {
                temp=1+mat[i][j-deno[i]];
                if(mat[i-1][j]>temp)
                    mat[i][j]=temp;
                else
                      mat[i][j]= mat[i-1][j];
            }


    printf("   ");
    for(i=0;i<=Max;i++)
        printf("%2d ",i);
        printf("\n");
    for(i=0;i<=no_deno;i++)
        {

        printf("%2d ",deno[i]);
        for(j=0;j<=Max;j++)
            printf("%2d ",mat[i][j]);
            printf("\n");

}
}


void backtrack()
{

    int i=no_deno,j=Max;
    printf("\ncoins:");
    while(i>1 && j>1 )
            if(mat[i-1][j] >(mat[i][j-deno[i]])+1)
                printf("%d ",deno[i]),j=j-deno[i];
            else
                i--;




}
int main()
{

    int i;
    printf("\tMAKING CHANGE USING DYNAMIC APPROACH\n\nEnter the value which minimum change to be found for:");
    scanf("%d",&Max);


    printf("enter the number of denominations:");
    scanf("%d",&no_deno);
deno[0]=0;
    printf("Enter the denomination:");
    for(i=1;i<=no_deno;i++)
        scanf("%d",&deno[i]);
    printf("\n\n MATRIX:\n");

   // no_deno++;
    making_change();

    backtrack();

return 0;

}
