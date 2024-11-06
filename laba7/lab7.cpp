#include <iostream>
#include <cstdlib>
#include <new>
#include <ctime>
#include <stack>
#include <vector>
using namespace std;
class Matrix {
private:
  int size;
  vector<vector<int>> matrix; 
public:
  vector<bool> NUM;
  vector<bool> visited;
  Matrix(int size) : size(size), matrix(size, std::vector<int>(size)), NUM(size, false), visited(size, false) {}
  void GenerateMatrix(int random) 
  {
    for(int i=0;i<size;i++)
    {
      matrix[i][i]=0;
      for(int j=i+1;j<size;j++)
      {
        if(random < rand() % 101) matrix[i][j]=0;
        else matrix[i][j]=1;
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
      break;
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
  int size, start,random;
  cout<<"Enter number of value and chance to generate the rib in % ";
  cin>>size>>random;
  Matrix graph(size);
  graph.GenerateMatrix(random);
  graph.PrintMatrix();
  cout<<endl;
  cout<<"DFS recursive"<<endl;
  graph.Check_false();
  cout<<'\n'<<"Enter vertex for DFS"<<endl;
  cin>>start;
  cout<<"DFS without recursive"<<endl;
  graph.DFS(start-1);
  cout<<endl;
  for(int i=0;i<size;i++)
  {
    if(graph.visited[i]==false) 
    {
      cout<<endl;
      graph.DFS(i);
    }
  }
  return 0;
}
