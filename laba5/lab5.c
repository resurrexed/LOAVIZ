#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() 
{
    srand(time(NULL));
    int size=0, counter=0;
    scanf("%d", &size);
    int **matrixs= malloc(sizeof(int*)* size);
    for(int i=0;i<size;i++) matrixs[i]= (int*) malloc(sizeof(int) * size);
    for(int i=0;i<size;i++)
    {
        matrixs[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
            matrixs[i][j]=rand() % 2;
            matrixs[j][i]=matrixs[i][j];
        }
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ", matrixs[i][j]);
        }
        printf("\n"); 
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(matrixs[i][j]==1) counter++;
        }
    }
    counter=counter/2;
    printf("\nsize is %d\n", counter);
    int peak=0;
    for(int i=0;i<size;i++)
    {
       for(int j=0;j<size;j++)
       {
           if(matrixs[i][j]==1) peak++;
       }
       if(peak==0) printf("%d peak is isolated\n", i+1);
       else if(peak==1) printf("%d peak is end\n", i+1);
       else if(peak==size) printf("%d peak is dominating\n", i+1);
       peak=0;
    }
    int j_b=0;
    int **matrixi= malloc(sizeof(int*)* size);
    for(int i=0;i<counter;i++) matrixi[i]= (int*) malloc(sizeof(int) * counter);
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<counter; j++)
            matrixi[i][j]=0;
    }
    for(int i=0; i<size; i++)
        for(int j=i+1; j<size; j++)
            if(matrixs[i][j])
            {
                matrixi[i][j_b]=1;
                matrixi[j][j_b]=1;
                j_b++;
            }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<counter;j++) printf("%d ", matrixi[i][j]);
        printf("\n");
    }
    printf("size is %d\n", counter);
     for(int i=0;i<size;i++)
    {
       for(int j=0;j<counter;j++)
       {
           if(matrixi[i][j]==1) peak++;
       }
       if(peak==0) printf("%d peak is isolated\n", i+1);
       else if(peak==1) printf("%d peak is end\n", i+1);
       else if(peak==counter) printf("%d peak is dominating\n", i+1);
       peak=0;
    }
}
