#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() 
{
    srand(time(NULL));
    int size=6;
    int matrix[size][size];
    for(int i=0;i<size;i++)
    {
        matrix[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
            matrix[i][j]=rand() % 2;
            matrix[j][i]=matrix[i][j];
        }
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); 
    }
    int counter=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(matrix[i][j]==1) counter++;
        }
    }
    printf("\nsize is %d\n", counter/2);
    int peak=0;
    for(int i=0;i<size;i++)
    {
       for(int j=0;j<size;j++)
       {
           if(matrix[i][j]==1) peak++;
       }
       if(peak==0) printf("%d peak is isolated\n", i+1);
       else if(peak==1) printf("%d peak is end\n", i+1);
       else if(peak==size) printf("%d peak is dominating\n", i+1);
       peak=0;
    }
}
