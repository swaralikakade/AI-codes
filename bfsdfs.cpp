#include <iostream>
#include <queue>
using namespace std;
#define max 100

class Graph {
    int V,adj[max][max];
public:
    Graph(int V):V(V){
        adj[V][V];
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                adj[i][j] = 0;
            }
        }
    } 

    void addEdge(int v, int w) {
        adj[v][w] = adj[w][v] = 1; 
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; ++i)
            if (adj[v][i] && !visited[i])
                DFSUtil(i, visited);
    }
    
    void DFS() {
        bool visited[V] = {false};

        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFSUtil(i, visited);
    }

    void BFSUtil(queue<int>& queue, bool visited[]) {
        if (queue.empty())
            return;

        int v = queue.front();
        cout << v << " ";
        queue.pop();

        for (int j = 0; j < V; j++) {
            if (adj[v][j] && !visited[j]) {
                visited[j] = true;
                queue.push(j);
            }
        }

        BFSUtil(queue, visited);
    }

    void BFS() {
        bool visited[V] = {false};
        queue<int> queue;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push(i);
                BFSUtil(queue, visited);
            }
        }
    }
};

int main() {
    int V,e,e1,e2;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    Graph g(V);
    
    cout<<"Enter the number of edges: ";
    cin>>e;
    for (int i = 0; i < e; i++) {
        cout<<"Enter the edge "<<i+1<<": ";
        cin>>e1>>e2;
        g.addEdge(e1, e2);
    }

    cout << "Depth First Search: ";
    g.DFS();
    cout << endl;

    cout << "Breadth First Search: ";
    g.BFS();
    cout << endl;

    return 0;
}







