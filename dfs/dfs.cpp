#include<stdio.h>
#define SIZE 5
/*input
0 1 0 0 1
1 0 0 1 0
0 0 0 0 0
0 1 0 0 0
1 0 0 0 0
*/

struct vertex
{
	int prd;
	int d_time,f_time;
	int colour;//0=und 1=dis 2=complete
}v[SIZE];

int time=0;

int adja_mat[SIZE][SIZE];

int S[SIZE];
int top=-1;
int isempty()
{
	if(top==-1 )
		return 1;
	return 0;
}
int isfull()
{
	if(top==SIZE-1)
		return 1;
	return 0;
}
int pop()
{
	if(isempty())
		printf("under flow");
	else
	return S[top--];
}
void push(int temp)
{
	if(isfull())
		printf("full");

		S[++top]=temp;
}
///printing adjacent array

	/*printf("adja of %d",u);
	for(i=0;i<adja_size;i++)
		printf("%d ",adja[i]);
*/
void dfs(int u)
{

	int i,j;
	int adja[SIZE];
	int adja_size;


	v[u].d_time=++time;

	v[u].colour=1;//discoverd
    //printf("\n");

	//find adjacent
	for(i=0,j=0;i<SIZE;i++)
		if(adja_mat[u][i]==1)
			adja[j++]=i;
	adja_size=--j;


	//for each element in adjacent list

	for(i=0;i<=adja_size;i++)
		{
			if(v[adja[i]].colour==0  )//white undiscovered
			{
				v[adja[i]].colour=1;//grey dis
				printf("discovered:%d\n",adja[i]);
				v[adja[i]].prd=u;//predecessor

				dfs(adja[i]);
			}
		}
		v[u].colour=2;//complete
		printf("completed:%d\n",u);

		v[u].f_time=++time;

}
int main()
{
	int i,j,u;
	time=0;
	//for(i=0;i<SIZE;i++)
		//adja[i]=-1;

	printf("\t\tDFS\n\nEnter %d * %d sized adja_mat: \n",SIZE,SIZE);
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			scanf("%d",&adja_mat[i][j]);

	for(i=0;i<SIZE;i++)
	{
		v[i].colour=0;
		v[i].d_time=-1;
		v[i].prd=-1;
    }
    time=0;
    printf("\ndiscovered:0 \n");
    for(i=0;i<SIZE;i++)
    {
       if(v[i].colour==0)

        dfs(i);
    }


	printf("\n\nnode    c disc_time  found_t   predecessor\n");
	for(i=0;i<SIZE;i++)
		printf("%d==>\t%d %d  %10d  %7d\n",i,v[i].colour,v[i].d_time,v[i].f_time,v[i].prd);


	return 0;
}
