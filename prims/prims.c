#include <stdio.h>
#include <limits.h>
#include<stdbool.h>


#define V 5
//min from not includeds
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
   int v = 0;

   for (v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

//  print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
   int i = 1;
   printf("Edge   Weight\n");
   for (i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V])
{
     int parent[V];
     int key[V];
     int i = 0;
     bool mstSet[V];
     int count = 0;
     int v = 0;

     // Initialize all keys as INFINITE
     for (i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

     // Always include first 1st vertex in MST.
     key[0] = 0;
     parent[0] = -1;

     // The MST will have V vertices
     for (count = 0; count < V-1; count++)
     {

        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;


        for (v = 0; v < V; v++)

          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     // print the constructed MST
     printMST(parent, V, graph);
}


// driver program to test above function
int main()
{

   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primMST(graph);

    return 0;
}
