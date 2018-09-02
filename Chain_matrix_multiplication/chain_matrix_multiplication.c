#include<stdio.h>
#define SIZE 6
int m[SIZE+1][SIZE+1],s[SIZE+1][SIZE+1],p[SIZE+1];
//input=30 35 15 5 10 20 25
void Print(int i,int j)
{

    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        Print(i,s[i][j]);
        Print(1+s[i][j],j);
        printf(")");

    }
}


void calculation()
{
        int i,j;
        for(i=0;i<SIZE+1;i++)
            for(j=0;j<SIZE+1;j++)
                m[i][j]=0,s[i][j]=0;
        for(j=0;j<SIZE+1;j++)//column
        {
            for(i=j-1;i>=0;i--)//row

                m[i][j]=mini(i,j);
        }

            printf("\n\n      MATRIX M:\t\t\t\t      MATRIX S:\n\n");

            for(i=1;i<SIZE+1;i++)
            {
                for(j=1;j<SIZE+1;j++)
                    printf("%7d",m[i][j]);
                printf("\t");
                for(j=1;j<SIZE+1;j++)
                    printf("%d ",s[i][j]);
                 printf("\n\n");
            }
            /*
        printf("\n\n\tMATRIX S:\n");

            for(i=1;i<SIZE+1;i++)
            {
                for(j=1;j<SIZE+1;j++)
                    printf("%d",s[i][j]);
                 printf("\n\n");
            }*/

}
int mini(int i,int j)
{
    int k,temp,minimum=99999;
    for(k=i;k<j;k++)
    {
        temp=   m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
        if(minimum>temp)
            minimum  =temp, s[i][j]=k ;
    }
    return minimum;
}

int main()
{
int i;
printf("\t\tCHAIN MATRIX MULTIPLICATION\n");
for(i=0;i<SIZE+1;i++)
    scanf("%d",&p[i]);

calculation();
printf("     OPTIMAL PARENTHESIS :\n\n     ");

Print(1,SIZE);
printf("\n\n");
return 0;
}
