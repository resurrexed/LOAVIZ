#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
struct Node {
    int vertex;
    struct Node* next;
}Node;
struct Graph {
    int numVertices;
    struct Node** adjLists;
}Graph;
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
int UniqeEdge(struct Graph* graph, int src, int dest)
{
    struct Node* temp=graph->adjLists[src];
    while(temp)
    {
        if(temp->vertex ==dest) return 0;
        temp=temp->next;
    }
    temp= graph->adjLists[dest];
    while(temp)
    {
        if(temp->vertex == src) return 0;
        temp=temp->next;
    }
    return 1;
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
    while(counter<vert)
    {
        int src, dest;
        src= rand() % vert;
        dest=rand() % vert;
        if(src!=dest && UniqeEdge(graph, src, dest))
        {
            struct Node* newNode = createNode(dest);
            newNode->next = graph->adjLists[src];
            graph->adjLists[src] = newNode;
            newNode = createNode(src);
            newNode->next = graph->adjLists[dest];
            graph->adjLists[dest] = newNode;
            counter++;
        }
    }
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
