
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  clock_t start, end; // объявляем переменные для определения времени выполнения

  int i=0, j=0, r;
  int size=4000;
  int** a=malloc(size*sizeof(int*));
  int** b=malloc(size*sizeof(int*));
  int** c=malloc(size*sizeof(int*));
  for(i=0;i<size;i++)
  {
    a[i]=(int*)malloc(size*sizeof(int));
    b[i]=(int*)malloc(size*sizeof(int));
    c[i]=(int*)malloc(size*sizeof(int));
  }
  srand(time(NULL)); // инициализируем параметры генератора случайных чисел
  while(i<size)
  {
    while(j<size)
    {
      a[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
      j++;
    }
    i++;
  }
  srand(time(NULL)); // инициализируем параметры генератора случайных чисел
  i=0; j=0;
  while(i<size)
  {
    while(j<size)
    {
      b[i][j]=rand()% 100 + 1; // заполняем массив случайными числами
      j++;
    }
    i++;
  }
    int elem_c=0;
  printf("do some calculating");
  start=clock();
  for(i=0;i<size;i++)
  {
    for(j=0;j<size;j++)
    {
      elem_c=0;
      for(r=0;r<size;r++)
      {
        elem_c=elem_c+a[i][r]*b[r][j];
        c[i][j]=elem_c;
      }
    }
  }
  end=clock()-start;
  printf("Time of multiplying matrix is %f", (float)end/CLOCKS_PER_SEC);
  return(0);
}

