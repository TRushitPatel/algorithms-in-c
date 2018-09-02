#include<stdio.h>
#include<string.h>

int b[30][30];

void print( char X[],int x,int y)
{
	if(x==0 || y==0)
		return;
	else if(b[x][y]==0)
	{
		print(X,x-1,y-1);
		printf("%c",X[x-1]);
	}
	else if(b[x][y]==1)
		print(X,x-1,y);
	else
		print(X,x,y-1);
}
void LCS_length(char X[],char Y[])
{
	int x=strlen(X);
	int y=strlen(Y);
	char Z[10];
	int c[x+1][y+1];
	int i,j;

	for(i=0;i<=x;i++)
		c[i][0]=0;
	for(j=0;j<=y;j++)
		c[0][j]=0;
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			}
		}
	}
	// c-table


    //strcpy(X,X);
    for(j=strlen(X);j>=0;j--)
        Z[j+1]=X[j];
    Z[0]=0;


    printf("\n\nmatrix:\n    ");
    for(i=0;i<y;i++)
        printf("%c ",Y[i]);
    printf("\n");

	for(i=0;i<=x;i++)
	{

		printf("%c ",Z[i]);
		for(j=0;j<=y;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}

	//Traceback
	printf("\nSO LCS for given string is:");
	print(X,x,y);

}
int main()
{
	char X[10],Y[10];
	printf("Enter two string for which you have to find LCS");
	scanf("%s%s",X,Y);

	LCS_length(X,Y);
	return 0;
}
/*
AGGTAB

GXTXAYB
*/
