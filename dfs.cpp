#include<bits/stdc++.h>
using namespace std;

const int N= 1e5;
int visited[N] ={0};

vector<int> adj_list[N];

void DFS(int node)
{
    cout<<node<<" ";
    visited[node]=1;
    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            DFS(adj_node);
        }
        
    }  
}

int main()
{
    cout<<"enter number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    

    cout<<"enter the edges"<<endl;
    for(int n=0; n<edges; n++)
    {
        int v,u;
        cin>>v>>u;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }
    
    cout<<"give starting point node"<<endl;
    
    int source;
    cin>> source ;
    DFS(source);
    
    return 0;
}


/*

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1e5;
int visited[N] = {0};
vector<int> adj_list[N];

void recursiveBFS(queue<int> & q){
    if(q.empty()) 
    {
        return ;
    }
    
    int node = q.front();
    q.pop();
    cout<< node <<" ";
    
    for(int adj_node: adj_list[node])
    {
        if(!visited[adj_node])
        {
            q.push(adj_node);
            visited[adj_node] = 1;
        }
    }
    
    recursiveBFS(q);
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=1;
    
    recursiveBFS(q);
}

void DFS(int node)
{
    cout<<node<<" ";
    visited[node]=1;
    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            DFS(adj_node);
        }
    }  
}

int main() {
    cout<<"Enter number of nodes and edges : "<<endl;
    int nodes, edges;
    cin>>nodes>>edges;
    
    cout<<"Enter the edges format(u v) : "<<endl;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    cout<<"Enter starting point node: "<<endl;
    int source;
    cin>>source;
    
    cout<<"BFS traversal"<<endl;
    BFS(source);
    cout << endl;
    
    cout<<"DFS traversal"<<endl;
    DFS(source);
    cout << endl;

    return 0;
}


*/