 #include<stdio.h>
 #include<string.h>
 char * A="AGGTAB";
 char * B="GXTXAYB";
 int L[11][11];
 int count;

    int lcs_length(int n,int m)
    {
	//A = AA; B = BB;
    int i,j;

	for (i = 0; i < 10; i++)
	    for (j = 0; j <10; j++)
            L[i][j] = -1;

    return subproblem(0, 0);
    }

    int subproblem(int i, int j)
    {

        count++;
        if (L[i][j] < 0 && (i<7 && j<6))
        {
            if (A[i] == '\0' || B[j] == '\0')
                L[i][j] = 0;
            else if (A[i] == B[j])
            {
                L[i][j] = 1 + subproblem(i+1, j+1);
                printf("%d  ",L[i][j]);
            }
            else
                L[i][j] = max(subproblem(i+1, j), subproblem(i, j+1));
        }
	return L[i,j];
    }


    int max(int i,int j)
    {
        return i>j ?i:j;
    }

    int main()
    {
        //char *AA="AGGTAB",*BB="GXTXAYB";

        int m=strlen(A),i,j;
        int n=strlen(B);

         lcs_length(m,n);
        printf("\n     ");

        for (i = 0; i <= m; i++)
           printf("%7c",B[i]);
        printf("\n");

        for (i = 0; i <= m; i++)
            {

                printf("%7c ",A[i]);
                for (j = 0; j <= m; j++)
                {printf("%5d ",L[i][j]);}
                printf("\n");
            }
            printf("\ncount=%d",count);
        return 0;
    }
