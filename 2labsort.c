#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void shell(int *items, int count)
{

  int i, j, gap, k;
  int x, a[5];

  a[0]=9; a[1]=5; a[2]=3; a[3]=2; a[4]=1;

  for(k=0; k < 5; k++) {
    gap = a[k];
    for(i=gap; i < count; ++i) {
      x = items[i];
      for(j=i-gap; (x < items[j]) && (j >= 0); j=j-gap)
        items[j+gap] = items[j];
      items[j+gap] = x;
    }
  }
}

void qs(int *items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
  int i, j;
  int x, y;



  i = left; j = right;

  /* выбор компаранда */
  x = items[(left+right)/2];
  
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;

    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);

  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
}
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int main()
{
    int size=1000;
    srand(time(NULL));
    int items1[size], items2[size], deafult[size];
    for(int i=0;i<size;i++)
    {
        items1[i]=rand() % 100;
        items2[i]=rand() % 100;
        deafult[i]=items2[i];
    }
    clock_t timetest=clock();
    qs(items2, 0, size-1);
    timetest=clock()-timetest;
    printf("Random massive sorted by quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    timetest=clock();
    qsort(deafult, size, sizeof(int), compare_ints);
    timetest=clock()-timetest;
    printf("Random massive sorted deafult by quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    timetest=clock();
    shell(items1, size);
    timetest=clock()-timetest;
    printf("Random massive sorted by shell sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    for(int i=0;i<size;i++)
    {
        items1[i]=i;
        items2[i]=i;
        deafult[i]=items2[i]; 
    }
    timetest=clock();
    qs(items2, 0, size-1);
    timetest=clock()-timetest;
    printf("Increasing massive sorted by quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC);    
    timetest=clock();
    qsort(deafult, size, sizeof(int), compare_ints);
    timetest=clock()-timetest;
    printf("Increasing massive sorted by deafult quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC);   
    timetest=clock();
    shell(items1, size);
    timetest=clock()-timetest;
    printf("Increasing massive sorted by shell sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    for(int i=0;i<size;i++)
    {
        items1[i]=-i;
        items2[i]=-i;
        deafult[i]=items2[i];
    }
    timetest=clock();
    qs(items2, 0, size-1);
    timetest=clock()-timetest;
    printf("Decreasing massive sorted by quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    timetest=clock();
    qsort(deafult, size, sizeof(int), compare_ints);
    timetest=clock()-timetest;
    printf("Decreasing massive sorted by deafult quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    timetest=clock();
    shell(items1, size);
    timetest=clock()-timetest;
    printf("Decreasing massive sorted by shell sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    for(int i=0;i<size;i++)
    {
        if(i<size/2)
        {
            items1[i]=i;
            items2[i]=i;
            deafult[i]=items2[i];
        } 
        else{
            items1[i]=-i;
            items2[i]=-i;
            deafult[i]=items2[i];
        }
    }
    timetest=clock();
    qs(items2, 0, size-1);
    timetest=clock()-timetest;
    printf("Massive with first increase half and second decrease sorted by quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC); 
    timetest=clock();
    qsort(deafult, size, sizeof(int), compare_ints);
    timetest=clock()-timetest;
    printf("Massive with first increase half and second decrease sorted by deafult quick sort in %f s\n", (float)timetest/CLOCKS_PER_SEC);     
    timetest=clock();
    shell(items1, size);
    timetest=clock()-timetest;
    printf("Massive with first increase half and second decrease sorted by shell sort in %f s\n", (float)timetest/CLOCKS_PER_SEC);
    return 0;
}

