#include <iostream>
#include <ctime>
#include <cstdlib>
#include <new>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
class Matrix {
public:
  Matrix(int size) : size(size), matrix(size, vector<int>(size)), NUM(size, false), DIST(size, -1) {}
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
        if(matrix[start][i]==1 && DIST[i]==-1)
        {
          q.push(i);
          DIST[i]=DIST[start]+1;
        }
      }
    }
    for (int i = 0; i < size; ++i) 
    {
      cout << "Vertex " << i << ": " << DIST[i] << endl;
    }
  }
private:
  int size;
  vector<vector<int>> matrix;
  vector<int> DIST;
  vector<bool> NUM;
};
int main()
{
  cout<<std::fixed<<endl;
  srand(time(NULL));
  int size, sourceVertex;
  cout<<"Enter amount of vertex ";
  cin>>size;
  Matrix graph(size);
  graph.GenerateMatrix();
  graph.PrintMatrix();
  cout<<endl;
  cout<<"Enter vertex to start BFSD(start from zero) ";  
  cin>>sourceVertex;
  cout << "Distances from vertex " << sourceVertex << ":" << endl;
  double start=clock();
  graph.BFSD(sourceVertex);
  double finish=clock();  
  cout<<"Time of BFSD- "<<(finish-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}
