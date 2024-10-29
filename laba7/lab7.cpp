#include <iostream>
#include <cstdlib>
#include <new>
#include <ctime>
#include <stack>
#include <vector>
using namespace std;
class Matrix{
  int size;
  int** matrix;
  bool* NUM;
  int counter=0;
public:
  void Check_false();
  void SetSize(int size);
  void CreateMatrix();
  void PrintMatrix();
  void Proxod(int v);
  void DFS(int start);
};
void Matrix::SetSize(int size)
{
  this->size=size;
}
void Matrix::CreateMatrix()
{
  matrix=new int*[size];
  NUM=new bool[size];
  for(int i=0;i<size;i++) 
  {
    matrix[i]=new int[size];
    NUM[i]=false;
  }
  for(int i=0;i<size;i++)
  {
    for(int j=i+1;j<size;j++)
    {
      matrix[i][j]=rand() % 2;
      matrix[j][i]=matrix[i][j];
    }
  }
}
void Matrix::PrintMatrix()
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
void Matrix::Check_false()
{
  for(int i=0; i<size;i++)
  {
    while(NUM[i]==false)
    {
        Matrix::Proxod(i);
    }
  }
}
void Matrix::Proxod(int v)
{
  NUM[v]=true;
  cout<<v+1<<" ";
  for(int i=0;i<size;i++)
  {
    if(matrix[v][i]==1 && NUM[i]==false)
    {
      Matrix::Proxod(i);  
    }
  }
}
void Matrix::DFS(int start)
{
    // Вектор для хранения информации о посещенных вершинах
    vector<bool> visited(size, false);
    
    // Стек для хранения вершин
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
int main()
{
  srand(time(NULL));
  Matrix matrix;
  matrix.SetSize(5);
  matrix.CreateMatrix();
  matrix.PrintMatrix();
  cout<<endl;
  matrix.Check_false();
  cout<<endl;
  matrix.DFS(0);
  return 0;
}
