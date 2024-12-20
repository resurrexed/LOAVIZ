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
  Matrix(int size) : size(size), matrix(size, vector<int>(size)), NUM(size, false) {}
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
  void BFS(int start) {
    queue<int> q;
    q.push(start);
    NUM[start] = true;

    while (!q.empty()) {
      int v = q.front();
      q.pop();
      cout << v + 1 << " ";

      for (int i = 0; i < size; i++) {
        if (matrix[v][i] == 1 && !NUM[i]) {
          NUM[i] = true;
          q.push(i);
        }
      }
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
private:
  int size;
  vector<vector<int>> matrix;
  vector<bool> NUM;
};
int main()
{
  srand(time(NULL));
  int size;
  cout<<"Enter amount of vertex ";
  cin>>size;
  Matrix graph(size);
  graph.GenerateMatrix();
  graph.PrintMatrix();
  cout<<endl;
  double start=clock();
  graph.BFS(0);
  double finish=clock();
  cout<<std::fixed<<endl;
  cout<<"Time of BFS- "<<(finish-start)/CLOCKS_PER_SEC<<endl;
  return 0;
}
