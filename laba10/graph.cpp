#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <new>
#include <vector>
#include <queue>
#include <iomanip>
#include <climits>
using namespace std;
class Matrix {
public:
  Matrix(int size, int weighted, int directed) : size(size), directed(directed), weighted(weighted), matrix(size, vector<int>(size)), NUM(size, false), DIST(size, -1) {}
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
    q.push(start);
    DIST[start]=0;
    while(!q.empty())
    {
      start=q.front();
      q.pop();
      for(int i=0;i<size;i++)
      {
        if(matrix[start][i]>0 && DIST[i]==-1)
        {
          q.push(i);
          DIST[i]=DIST[start]+matrix[start][i];
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
    int radius=INT_MAX, diameter=0;
    for(int i=0;i<size;i++)
    {
      if(DIST[i] < radius) radius=DIST[i];
      if(DIST[i] > diameter) diameter=DIST[i];
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
  int directed=0, weighted=0, size, start;
  if(argc>1)
  {
    for(int i=0;i<argc; ++i)
    {
      if (argv[i]=="-directed") directed=stoi(argv[i+1]);
      if (argv[i]=="-weighted") weighted=stoi(argv[i+1]);
    }
    if(directed > 1) directed = 1;
    if(weighted > 1) weighted = 1;
  }
  else
  {
    cout<<"We will consider our graph to be undirected and unweighted"<<endl;
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
  graph.Radius_Diameter();
}
