#include <iostream>
#include <cstdlib>
#include <new>
#include <ctime>
#include <stack>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
#include <queue>

class Matrix {
private:
  int size;
  vector<vector<int>> matrix;
  vector<bool> NUM; 
public:
  Matrix(int size) : size(size), matrix(size, std::vector<int>(size)), NUM(size, false) {}
  void GenerateMatrix() 
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
  void PrintMatrix()
  {
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  void Check_false() {
    for (int i = 0; i < size; i++) {
      if (!NUM[i]) {
        Proxod(i);
      }
    }
  }
  void Proxod(int v) {
    NUM[v] = true;
    std::cout << v + 1 << " ";

    for (int i = 0; i < size; i++) {
      if (matrix[v][i] == 1 && !NUM[i]) {
        Proxod(i);
      }
    }
  }
  void DFS(int start)
  {
    vector<bool> visited(size, false);
    stack<int> st;
    
    // Помещаем начальную вершину в стек
    st.push(start);
    
    while (!st.empty())
    {
        // Получаем вершину с вершины стека
        int current = st.top();
        st.pop();
        
        // Если вершина еще не посещена
        if (!visited[current])
        {
            // Отмечаем вершину как посещенную
            visited[current] = true;
            
            // Выводим номер вершины
            cout << current + 1 << " ";
            
            // Просматриваем все смежные вершины
            for (int i = size - 1; i >= 0; i--)
            {
                // Если есть ребро и вершина не посещена
                if (matrix[current][i] == 1 && !visited[i])
                {
                    st.push(i);
                }
            }
        }
    }
  }
};

int main()
{
  srand(time(NULL));
  int size;
  cout<<"Enter number of value ";
  cin>>size;
  Matrix graph(size);
  graph.GenerateMatrix();
  graph.PrintMatrix();
  graph.Check_false();
  cout<<endl;
  graph.DFS(0);
  return 0;
}
