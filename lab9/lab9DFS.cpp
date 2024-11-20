#include <iostream>
#include <ctime>
#include <cstdlib>
#include <new>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

class Matrix {
public:
  Matrix(int size) : size(size), matrix(size, vector<int>(size)), DIST(size, -1) {}

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

  void DFS(int v, int currentDistance)
  {
    if (DIST[v] == -1 || currentDistance < DIST[v]) { // Обновляем расстояние, если найдено более короткое
      DIST[v] = currentDistance;
    }

    for (int i = 0; i < size; ++i) {
        if (matrix[v][i] == 1) {
            if (DIST[i] == -1 || currentDistance + 1 < DIST[i]) { // Обновляем расстояние, если найдено более короткое
                DFS(i, currentDistance + 1);
            }
        }
    }
  }

  void DFSD(int startVertex)
  {
    DFS(startVertex, 0);
    for (int i = 0; i < size; ++i) 
    {
      cout << "Vertex " << i << ": " <<DIST[i] << endl;
    }
  }

private:
  vector<int> DIST;
  int size;
  vector<vector<int>> matrix;
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
  cout<<"Enter vertex to start DFSD(start from zero) ";  
  cin>>sourceVertex;
  cout << "Distances from vertex " << sourceVertex << ":" << endl;
  double start=clock();
  graph.DFSD(sourceVertex);
  double finish=clock(); 
  cout<<"Time of DFSD- "<<(finish-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}
