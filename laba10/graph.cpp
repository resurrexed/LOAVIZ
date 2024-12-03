#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <new>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
using namespace std;
class Matrix {
public:
  Matrix(int size, int weighted, int directed) : size(size), directed(directed), weighted(weighted), matrix(size, vector<int>(size)), NUM(size, false), DIST(size, INT_MAX) {}
  void PrintMatrix(){
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  void GenerateMatrix() {
    if(directed==0 && weighted==0)
    {
      for(int i=0;i<size;i++)
      {
        matrix[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
          matrix[i][j]=rand() % 2;
          matrix[j][i]=matrix[i][j];
        }
      }
    }
    else if(directed==1 && weighted==0)
    {
      for (int i = 0; i < size; i++) 
      {
        for (int j = 0; j < size; j++) 
        {
          if (i == j) 
          {
              matrix[i][j] = 0;
          } 
          else 
          {
              matrix[i][j] = rand() % 2;
          }
        }
      }
    }
    else if(directed==0 && weighted==1)
    {
      for(int i=0;i<size;i++)
      {
        matrix[i][i]=0;
        for(int j=i+1;j<size;j++)
        {
          matrix[i][j]=rand() % 10;
          matrix[j][i]=matrix[i][j];
        }
      }
    }
    else
    {
      for (int i = 0; i < size; i++) 
      {
        for (int j = 0; j < size; j++) 
        {
          if (i == j) 
          {
              matrix[i][j] = 0;
          } 
          else 
          {
              matrix[i][j] = rand() % 10;
          }
        }
      }
    }
  }
 void BFSD(int start) 
{
    queue<int> q;
    vector<bool> inQueue(size, false);  // Массив для отслеживания вершин в очереди
    
    // Инициализация расстояний
    for(int i = 0; i < size; i++) {
        DIST[i] = INT_MAX;
    }
    
    q.push(start);
    inQueue[start] = true;
    DIST[start] = 0;

    while(!q.empty())
    {
        start = q.front();
        q.pop();
        inQueue[start] = false;  // Вершина больше не в очереди

        for(int i = 0; i < size; i++)
        {
            // Если есть ребро и можно улучшить расстояние
            if(matrix[start][i] > 0 && DIST[start] + matrix[start][i] < DIST[i])
            {
                DIST[i] = DIST[start] + matrix[start][i];
                q.push(i);
            }
        }
    }
}
void PrintBFSD()
  {
    for (int i = 0; i < size; ++i) 
    {
      cout << "Vertex " << i << ": " << DIST[i] << endl;
    }
  }
  void Radius_Diameter()
  {
    int radius = INT_MAX;
    int diameter = 0;
    
    // Для каждой вершины
    for(int i = 0; i < size; i++)
    {
        BFSD(i);
        
        int eccentricity = 0;
        for(int j = 0; j < size; j++)
        {
            if(DIST[j] != INT_MAX && DIST[j] > eccentricity && i!=j)
            {
              eccentricity = DIST[j];
              cout<<eccentricity<<endl;
                if(eccentricity < radius && eccentricity!=-1)
                  radius = eccentricity;
                if(eccentricity > diameter)
                  diameter = eccentricity;
            }
        }
      
    }
    
    cout << "Radius of the graph: " << radius << endl;
    cout << "Diameter of the graph: " << diameter << endl;
  }
private:
  int size;
  vector<vector<int>> matrix;
  vector<int> DIST;
  vector<bool> NUM;
  int weighted;
  int directed;
};
int main(int argc, char *argv[])
{
  //srand(time(NULL));
  int directed=0, weighted=0, size, start;
  if(argc>1)
  {
    for(int i=0;i<argc; ++i)
    {
      if (strcmp(argv[i],"-directed")==0) directed=1;
      if (strcmp(argv[i],"-weighted")==0) weighted=1;
    }
  }
  else
  {
    cout<<"We will consider our graph to be undirected and unweighted\n(run program with \n-direct for directed graph\n -weighted for weighted graph)"<<endl;
  }
  cout<<"Please enter size of matrix"<<endl;
  cin>>size;
  Matrix graph(size, weighted, directed);
  graph.GenerateMatrix();
  graph.PrintMatrix();
  cout<<"Enter vertex for start BFSD"<<endl;
  cin>>start;
  graph.BFSD(start);
  graph.PrintBFSD();
  //graph.Radius_Diameter();
}
