#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int** CreateMatrix(int size)
{
    int** matrix=malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++) matrix[i]=(int*) malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        matrix[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
            	matrix[i][j]=rand() % 2;
            	matrix[j][i]=matrix[i][j];
    	}
	}
    return matrix;
}
void NullMatrix(int size, int** matrix)
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++) matrix[i][j]=0;
}
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
    for(int i=deleted_vortex;i<size-1;i++)
    {
            for(int j=0;j<size;j++)
            {
                matrix[i][j]=matrix[i+1][j];
            }
    }
    for(int i=0;i<size;i++)
    {
            for(int j=deleted_vortex;j<size-1;j++)
            {
                matrix[i][j]=matrix[i+1][j];
            }
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
    DeleteVortex(matrix, size, ident_vortex2);
}
int** Intersection(int** matrix1, int** matrix2, int size1, int size2)
{
    int size;
    if(size1>size2) size=size2;
    else size=size1;
    int** matrix3=CreateMatrix(size);
    NullMatrix(size, matrix3);
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix3[i][j]=matrix1[i][j] & matrix2[i][j];
            matrix3[j][i]=matrix3[i][j];
        }
    }
    return matrix3;
}
int** RingSum(int** matrix1, int** matrix2, int size1, int size2)
{
    int size;
    if(size1>size2) size=size1;
    else size=size2;
    int** matrix3=CreateMatrix(size);
    NullMatrix(size, matrix3);
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix3[i][j]=matrix1[i][j]^matrix2[i][j];
            matrix3[j][i]=matrix3[i][j];
        }
    }
    return matrix3;
}
int** Merge(int** matrix1, int** matrix2, int size1, int size2)
{
    int size;
    if(size1>size2) size=size1;
    else size=size2;
    int** matrix3=CreateMatrix(size);
    NullMatrix(size, matrix3);
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            matrix3[i][j]=matrix1[i][j] | matrix2[i][j];
            matrix3[j][i]=matrix3[i][j];
        }
    }
    return matrix3;
}
int** DecartMult(int** matrix1, int** matrix2, int size1, int size2)
{
    int size=size1*size2;
    int** matrix3=CreateMatrix(size);
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size1; ++k) {
                for (int l = 0; l < size2; ++l) {
                    if ((matrix1[i][k] && j == l) || (matrix2[j][l] && i == k)) {
                        matrix3[i * size2 + j][k * size2 + l] = 1;
                    }
                }
            }
        }
    }
    return matrix3;
}
int main() 
{
	srand(time(NULL));
    int size1=0, size2=0, counter=0;
    printf("Enter amount of vortex- ");
    scanf("%d", &size1);
    printf("Enter amount of vortex- ");
    scanf("%d", &size2);
    int **a=CreateMatrix(size1);
    int **b=CreateMatrix(size2);
    printf("fisrt matrix\n");
    PrintMatrix(a, size1);
    printf("second matrix\n");
    PrintMatrix(b, size2);
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
            }while((ident_vortex1>size1 || ident_vortex1<0)&&(ident_vortex2>size1 || ident_vortex2<0));
            Identification(a, size1, ident_vortex1,ident_vortex2);
            size1--;
			PrintMatrix(a, size1);
			break;
		case 2:
            int ident_vortex3, ident_vortex4;
            do{
                printf("Enter two number of vortex to tighten rib starting from zero- ");
                scanf("%d", &ident_vortex3);
                scanf("%d", &ident_vortex4);
            }while((ident_vortex3>size1 || ident_vortex3<0)&&(ident_vortex4>size1 || ident_vortex4<0)&&(a[ident_vortex3][ident_vortex4]==1));
            Identification(a, size1, ident_vortex3 ,ident_vortex4);
            size1--;
			PrintMatrix(a, size1);
			break;
		case 3:
            int deleted_vortex;
            do{
                printf("Enter number vortex to delete starting from zero- ");
                scanf("%d", &deleted_vortex);
            }while(deleted_vortex>size1 || deleted_vortex<0);
            DeleteVortex(a, size1, deleted_vortex);
            size1--;
			PrintMatrix(a, size1);
			break;		
	}
    do{
        printf("Choose operation with 2 graphs\n1-Merge\n2-Intersection\n3-Ring Sum\n4-Decart multiplication\n");
        scanf("%d", &operation);
    }while(operation<=0 || operation >4);
    int size3=0;
    if(size1>size2) size3=size1;
    else size3=size2;
	switch(operation)
    {
        case 1:
            int** c=Merge(a, b, size1, size2);
            PrintMatrix(c, size3);            
            break;
        case 2:
            int** d=Intersection(a, b, size1, size2);
            if(size1>size2) size3=size2;
            else size3=size1;
            PrintMatrix(d, size3);
            break;
        case 3: 
            int** e=RingSum(a, b, size1, size2);
            PrintMatrix(e, size3);           
            break;
        case 4:
            int** f=DecartMult(a, b, size1, size2);
            PrintMatrix(f, size1*size2);
            break;
    }
}
