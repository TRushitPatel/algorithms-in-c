# include<stdio.h>

float weight[20], profit[20], capacity;
float ratio[20];
void knapsack(int n)
{
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nAnswer:\n");
    for (i = 1; i <= n; i++)
      printf("%d\t", i);

    printf("\n");

   for (i = 0; i < n; i++)
      printf("%.2f\t", x[i]);

   printf("\n\nMaximum profit: %f\n\n", tp);

}

int main() {

   int num, i, j;
   float  temp;

   printf("\t   KNAPSACK USING GREEDY APPROACH\n\nEnter the no. of objects: ");
   scanf("%d", &num);

   printf("\nweight and value:");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\ncapacity ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num);
   return(0);
}
