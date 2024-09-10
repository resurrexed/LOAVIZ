#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    int mass[20], min=10000, max=-1000;
    for(int i=0;i<20;i++)
    {
        mass[i]=i-5;
        if(max<mass[i])max=mass[i];
        if(min>mass[i])min=mass[i];
        printf("%d ", mass[i]);
    }
    printf("\n%d-%d=%d\n", max, min, max-min);
    int mass2[20];
    srand(time(NULL));
    for(int i=0;i<20;i++)
    {
        mass2[i]=rand() % 100-50;
        printf("%d ", mass2[i]);
    }
    printf("\n");
    int size;
    scanf("%d", &size);
    int *p;
    p=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        *(p+i)=rand() % 100;
        printf("%d ", *(p+i));
    }
    printf("\n");
    int matrix[10][10]={0};
    int sum=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            matrix[i][j]=rand() % 100;
            sum+=matrix[i][j];
            printf("%d\t", matrix[i][j]);
        }
        printf(" %d\n", sum);
        sum=0;
    }
    int amount=2;
    struct students{
        char Name[20];
        char Surname[20];
        char Facult[20];
        int IdCard;
    }stud[amount];
    for(int i=0;i<amount;i++)
    {
        printf("\nEnter %d students name ", i+1);
        scanf("%20s", stud[i].Name);
        printf("\nEnter %d students surname ", i+1);
        scanf("%20s", stud[i].Surname);
        printf("\nEnter %d students faculty ", i+1);
        scanf("%20s", stud[i].Facult);
        printf("\nEnter %d students number of credit card ", i+1);
        scanf("%d", &stud[i].IdCard);
    }
    char searched_name[20], searched_surname[20], searched_facult[20];
    int searched_idcard;
    printf("\nEnter searched students name ");
    scanf("%20s", searched_name);
    printf("\nEnter searched students surname ");
    scanf("%20s", searched_surname);
    printf("\nEnter searched students faculty ");
    scanf("%20s", searched_facult);
    printf("\nEnter searched students number of credit card ");
    scanf("%d", &searched_idcard);
    int finded=0;
    for(int i=0;i< amount;i++)
    {
        if(strcmp(searched_surname, stud[i].Surname)==0)
            if(strcmp(searched_name, stud[i].Name)==0)
                if(strcmp(searched_facult, stud[i].Facult)==0)
                    if(searched_idcard==stud[i].IdCard)
                    {
                        printf("\nFinded student %d in struct", i);
                        finded=1;
                    }
    }
    if(finded==0) printf("\nDon't find");
    return 0;
}
