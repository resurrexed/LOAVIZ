#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
struct Node { 
    int data; 
    struct Node *left; 
    struct Node *right; 
};
struct Node *root;
struct Node *CreateTree(struct Node *root, struct Node *r, int data)
{
	if (r == NULL)
	{
		r = (struct Node *)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;
        // if(data == root->data) return r;
        if (data < root->data)	root->left = r;
		else root->right = r;
		return r;
	}
    //if (data== r->data) return root;
    if (data < root->data) CreateTree(r, r->left, data);
	else CreateTree(r, r->right, data);
	return root;
}
void print_tree(struct Node *r, int l)
{
	
	if (r == NULL)
	{
		return;
	}
	
	print_tree(r->right, l + 1);
	for(int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left,  l+1);
}
struct Node *FINDinTREE(struct Node *root, struct Node *r, int searched_data) // Сложность в среднем log2(n) в худшем n
{
   if(r==NULL) return NULL;
   if(searched_data == r->data) return r;
   else if(searched_data > root->data) FINDinTREE(r, r->right, searched_data);
   else FINDinTREE(r, r->left, searched_data);
}
int counter(struct Node *root, struct Node *r, int searched_data, int chet)
{
    if(r==NULL) return chet;
    if(searched_data == r->data) 
    {
        chet++;
        counter(r, r->right, searched_data, chet);
    }
    else if(searched_data > root->data) counter(r, r->right, searched_data, chet);
    else counter(r, r->left, searched_data, chet);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int D, start = 1, lenght=0;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);
        lenght++;
	}

	print_tree(root, lenght);
    struct Node *find=FINDinTREE(root, root, 10);
    if(find) printf("Найдено! - %d\n", find->data);
    else printf("Не найдено\n");
    int c= counter(root, root, 10, 0);
    printf("counters of number- %d\n", c);
	return 0;
}

