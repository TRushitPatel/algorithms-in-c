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
	int distance;
	int colour;//0=und 1=dis 2=complete
}v[SIZE];

int adja[SIZE];
int adja_size;

int adja_mat[SIZE][SIZE];

int Q[SIZE];
int front=-1,last=-1;
int isempty()
{
	if(front==-1 || front>last)
		return 1;
	return 0;
}
int isfull()
{
	if(last==SIZE-1)
		return 1;
	return 0;
}
int DQ()
{
	if(isempty())
		printf("under flow");
	else
	return Q[front++];
}
void NQ(int temp)
{
	if(isfull())
		printf("full");
	if(front=-1)
		front++;

		Q[++last]=temp;
}

void find_adjacent(int u)
{

	int i=0,j=0;
	for(i=0;i<SIZE;i++)
		adja[i]=-1;

	for(i=0,j=0;i<SIZE;i++)
		if(adja_mat[u][i]==1)
			adja[j++]=i;
	adja_size=--j;
	//printf("adja of %d",u);
	//for(i=0;i<adja_size;i++)
		//printf("%d ",adja[i]);
}

int main()
{
	int i,j,u,source=1;
	for(i=0;i<SIZE;i++)
		adja[i]=-1;

	printf("\t\tBFS\n\nEnter %d * %d sized adja_mat: \n",SIZE,SIZE);
	for(i=0;i<SIZE;i++)
		for(j=0;j<SIZE;j++)
			scanf("%d",&adja_mat[i][j]);

	for(i=0;i<SIZE;i++)
	{
		v[i].colour=0;
		v[i].distance=-1;
		v[i].prd=-1;
	}

	v[source].distance=0;
	v[source].prd=-1;
	v[source].colour=1;
	printf("\ndiscovered:%d\n",source);

	NQ(source);


	while(!isempty())
	{
		u=DQ();
		find_adjacent(u);

		for(i=0;i<=adja_size;i++)
		{
			if(v[adja[i]].colour==0  )//white undiscovered
			{
				v[adja[i]].colour=1;//grey dis
				printf("discovered=%d\n",adja[i]);

				v[adja[i]].distance=v[u].distance+1;//dist updated

				v[adja[i]].prd=u;//predecessor

				NQ(adja[i]);
			}
		}
		v[u].colour=2;//complete
		printf("completed:%d\n",u);
		}


		printf("\n\nnode\tc distance  predecesor\n");
	for(i=0;i<SIZE;i++)
		printf("%d==>\t%d %5d %7d\n",i,v[i].colour,v[i].distance,v[i].prd);


	return 0;
}
