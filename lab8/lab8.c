#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
struct node
{
	int vertex;  // полезная информация
	struct node *next; // ссылка на следующий элемент 
}node;
struct node *head = NULL, *last = NULL, *f = NULL;
void queue_push(int v)
{
  struct node *p = NULL;
	p = (struct node*)malloc(sizeof(struct node));
	if (head == NULL && p != NULL)	// если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // список уже есть, то вставляем в конец
	{
		last->next = p;
		last = p;
	}
  p->vertex=v;
	return; 
}
struct node *queue_pop(void)
{
   struct node *struc = head;
   struct node *delitem;
   head=struc->next;
   delitem=struc;
   free(struc);
   return delitem; 
}
int queue_front()
{
  return head->vertex;
}
int queue_empty()
{
  if(head==NULL) return 1;
  else return 0;
}
void BFS(int start, int** matrix, int size, bool* NUM) 
{
  queue_push(start);
  NUM[start] = true;

  while (!(queue_empty())) {
    int v = queue_front();
    queue_pop();
    printf("%d ", v+1);
    for (int i = 0; i < size; i++) {
      if (matrix[v][i] == 1 && !NUM[i]) {
        NUM[i] = true;
        queue_push(i);
      }
    }
  }
}
int main()
{
  srand(time(NULL));
  int size, random;
  printf("Enter amount of vertex and percent to generate the rib ");
  scanf("%d %d", &size, &random);
  int** matrix=malloc(sizeof(int*)*size);
  for(int i=0;i<size;i++) matrix[i]=(int*) malloc(sizeof(int)* size);
  bool* NUM=malloc(sizeof(bool)*size);
  for(int i=0;i<size;i++) NUM[i]=false;
  printf("Create matrix and massive\n");
  for(int i=0;i<size;i++)
  {
    matrix[i][i]=0;
    for(int j=i+1;j<size;j++)
    {
      if(random < rand() % 101) matrix[i][j]=0;
      else matrix[i][j]=1;
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
  printf("\n");
  float start = clock();
  BFS(0, matrix, size, NUM);
  float finish=clock();
  printf("\nTime of BFS %f", (finish-start)/CLOCKS_PER_SEC);
}
