#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N] = {0};
vector<int> adj_list[N];

void recursiveBFS(queue<int>& q) {
    if (q.empty()) return;

    int node = q.front();
    q.pop();
    cout << node << " "; // Print the current node

    // Visit all adjacent nodes of the current node
    for (int adj_node : adj_list[node]) {
        if (!visited[adj_node]) {
            q.push(adj_node); // Enqueue the adjacent node
            visited[adj_node] = 1; // Mark the adjacent node as visited
        }
    }

    recursiveBFS(q); // Recursively call BFS on the updated queue
}

void BFS(int start) {
    queue<int> q;
    q.push(start); // Enqueue the starting node
    visited[start] = 1; // Mark the starting node as visited

    recursiveBFS(q);
}

int main() {
    cout << "Enter number of nodes and edges: ";
    int nodes, edges;
    cin >> nodes >> edges;

    // Input the edges
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // For undirected graph
    }

    cout << "Enter starting point node: ";
    int source;
    cin >> source;

    cout << "BFS traversal: ";
    BFS(source);

    return 0;
}
