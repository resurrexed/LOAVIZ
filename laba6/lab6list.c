#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
};
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) 
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) 
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
void GenerateGraph(struct Graph* graph, int vert)
{
    int counter=0;
    do{
        int src, dest;
        src= rand() % vert;
        do{
            dest=rand() % vert;
        }while(src==dest);
        struct Node* newNode = createNode(dest);
        newNode->next = graph->adjLists[src];
        graph->adjLists[src] = newNode;
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
        counter++;
    }while(counter<vert);
}
void PrintGraph(struct Graph* graph)
{
    printf("adj list\n");
    for(int v=0; v<graph->numVertices;v++)
    {
        struct Node* temp=graph->adjLists[v];
        printf("%d--->", v);
        while(temp)
        {
            printf("%d->", temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    srand(time(NULL));
    int vertex=0;
    printf("Enter amount of vertex- ");
    scanf("%d", &vertex);
    struct Graph* graph = createGraph(vertex);
    GenerateGraph(graph, vertex);
    PrintGraph(graph);
}
