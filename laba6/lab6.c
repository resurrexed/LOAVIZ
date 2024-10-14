#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void PrintMatrix(int** matrix, int size)
{
	for(int i=0;i<size;i++)
    	{
        	for(int j=0;j<size;j++)
        	{
            		printf("%d ", matrix[i][j]);
        	}
        	printf("\n"); 
    	}
}
void DeleteVortex(int** matrix, int size, int deleted_vortex)
{
    for(int i=0;i<size;i++)
    {
        if(i==deleted_vortex)
        {
            for(int j=0;j<size;j++)
            {
                matrix[i][j]=0;
                matrix[j][i]=0;
            }
            break;
        }
        else continue;
    }
}
void Identification(int** matrix, int size, int ident_vortex1, int ident_vortex2)
{
    for(int i=0;i<size;i++)
    {
        if(i==ident_vortex2)
        {
            for(int j=0;j<size;j++)
            {
                if(j==ident_vortex1)
                for(int k=0;k<size;k++)
                {
                    if(matrix[i][k]==1) matrix[j][k]=matrix[i][k];
                    if(matrix[k][i]==1) matrix[k][j]=matrix[k][i];
                    matrix[i][k]=0;
                    matrix[k][i]=0;
                }
            }
        }
    }
}
void Intersection(int** matrix1, int** matrix2, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix1[i][j]=matrix1[i][j] & matrix2[i][j];
            matrix1[j][i]=matrix1[i][j];
        }
    }
}
void RingSum(int** matrix1, int** matrix2, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix1[i][j]=matrix1[i][j]^matrix2[i][j];
            matrix1[j][i]=matrix1[i][j];
        }
    }
}
void Merge(int** matrix1, int** matrix2, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix1[i][j]=matrix1[i][j] | matrix2[i][j];
            matrix1[j][i]=matrix1[i][j];
        }
    }
}
int** DecartMult(int** matrix1, int** matrix2, int size)
{
    int** matrix3=malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++) matrix3[i]=(int*) malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            int elem_c=0;
            for(int r=0;r<size;r++)
            {
                elem_c=elem_c | (matrix1[i][r] & matrix2[r][j]);
                 matrix3[i][j]=elem_c;
            }
        }
    }
    return matrix3;
}
int main() 
{
	srand(time(NULL));
    int size=0, counter=0;
    printf("Enter amount of vortex- ");
    scanf("%d", &size);
    int **a= malloc(sizeof(int*)* size);
    int **b= malloc(sizeof(int*)* size);
    for(int i=0;i<size;i++) a[i]= (int*) malloc(sizeof(int) * size);
    for(int i=0;i<size;i++) b[i]= (int*) malloc(sizeof(int) * size);
    for(int i=0;i<size;i++)
    {
        a[i][i]=0;
        b[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
            	a[i][j]=rand() % 2;
            	a[j][i]=a[i][j];
                b[i][j]=rand() % 2;
        		b[j][i]=b[i][j];
    	}
	}
    printf("fisrt matrix\n");
    PrintMatrix(a, size);
    printf("second matrix\n");
    PrintMatrix(b, size);
	int operation;
	do
	{
		printf("Choose graph operation:\n1- Identification of vortex\n2- Tightening the rib\n3- Delete the vortex\n0-Skip\n");
		scanf("%d", &operation);
	}while(operation<0 || operation>3);
	switch(operation)
	{
        case 0:
            break;
		case 1:
            int ident_vortex1, ident_vortex2;
            do{
                printf("Enter two number of vortex to ident starting from zero- ");
                scanf("%d", &ident_vortex1);
                scanf("%d", &ident_vortex2);
            }while((ident_vortex1>size || ident_vortex1<0)&&(ident_vortex2>size || ident_vortex2<0));
            Identification(a, size, ident_vortex1,ident_vortex2);
			PrintMatrix(a, size);
			break;
		case 2:
            int ident_vortex3, ident_vortex4;
            do{
                printf("Enter two number of vortex to tighten rib starting from zero- ");
                scanf("%d", &ident_vortex3);
                scanf("%d", &ident_vortex4);
            }while((ident_vortex3-ident_vortex4==1 || ident_vortex3-ident_vortex4==1)&&(ident_vortex3>size || ident_vortex3<0)&&(ident_vortex4>size || ident_vortex4<0));
            Identification(a, size, ident_vortex3 ,ident_vortex4);
			PrintMatrix(a, size);
			break;
		case 3:
            int deleted_vortex;
            do{
                printf("Enter number vortex to delete starting from zero- ");
                scanf("%d", &deleted_vortex);
            }while(deleted_vortex>size || deleted_vortex<0);
            DeleteVortex(a, size, deleted_vortex);
			PrintMatrix(a, size);
			break;		
	}
    do{
        printf("Choose operation with 2 graphs\n1-Merge\n2-Intersection\n3-Ring Sum\n4-Decart multiplication\n");
        scanf("%d", &operation);
    }while(operation<=0 || operation >4);
	switch(operation)
    {
        case 1:
            Merge(a, b, size);
            PrintMatrix(a, size);            
            break;
        case 2:
            Intersection(a, b, size);
            PrintMatrix(a, size);
            break;
        case 3: 
            RingSum(a, b, size);
            PrintMatrix(a, size);           
            break;
        case 4:
            int** c=DecartMult(a, b, size);
            PrintMatrix(c, size);
            break;
    }
}
