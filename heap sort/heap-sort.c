#include<stdio.h>
#include<malloc.h>
#include<time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 

  
    if (l < n && arr[l] > arr[largest])
        largest = l;
	if (r < n && arr[r] > arr[largest])
        largest = r;

	if (largest != i)
    {
       arr[i]=arr[i]+arr[largest]-(arr[largest]=arr[i]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
   	clock_t start,end;
    start=clock();
	//***********************************
    // Build heap (rearrange array)
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (i=n-1; i>=0; i--)
    {
        // Move current root to end
	arr[0]=arr[0]+arr[i]-(arr[i]=arr[0]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
	//**************************************
	end=clock();
	printf("\n%d\t%f",n,(double)(end-start)/CLOCKS_PER_SEC);

   
}


int * rand_generate(int arr[],int SIZE)
{
        int i;
        arr=(int *)malloc(SIZE*sizeof(int ));
    	for(i=0;i<SIZE;i++)
		arr[i]=rand();
		return arr;

}

int * best(int arr[],int SIZE)
{
        int i;
        arr=(int *)malloc(SIZE*sizeof(int ));
    	for(i=0;i<SIZE;i++)
		arr[i]=i;
		return arr;

}

int * worst(int arr[],int SIZE)
{
        int i;
        arr=(int *)malloc(SIZE*sizeof(int ));
    	for(i=0;i<SIZE;i++)
		arr[i]=SIZE-i;
		return arr;

}
int main()
{

	int *arr;
	int temp;
	int i,j;
	int SIZE[]={1000,5000,8000,10000,50000,100000};
	int n=sizeof(SIZE)/sizeof(SIZE[0]);
	
    //RENDOM data
    printf("\t\tHEAP SORT ANALYSIS:\n\n	RANDOM:");
    printf("\nSIZE\ttime");
   	for(i=0;i<n;i++)
    {
        arr=rand_generate(arr,SIZE[i]);
        heapSort(arr,SIZE[i]);
    }
    //SORTED
    printf("\n\nSORTED:");
    for(i=0;i<n;i++)
    {
        arr=best(arr,SIZE[i]);
        heapSort(arr,SIZE[i]);
    }
    //REVERSELY SORTED
    printf("\n\nREVERSELY SORTED:");
    for(i=0;i<n;i++)
    {
        arr=worst(arr,SIZE[i]);
        heapSort(arr,SIZE[i]);

    }
	return 0;

}


