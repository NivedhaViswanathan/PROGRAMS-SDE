#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
    int V;           
    list<int> *adj;     
public: 
    Graph(int V);               
    void addEdge(int v, int w); 
    void longestPathLength();   
    pair<int, int> bfs(int u);  
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);    
    adj[w].push_back(v);   
} 
  
pair<int, int> Graph::bfs(int u) 
{ 
    int dis[V]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
  
            if (dis[v] == -1) 
            { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    for (int i = 0; i < V; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
} 
 
void Graph::longestPathLength() 
{ 
    pair<int, int> t1, t2; 
    t1 = bfs(0); 
    t2 = bfs(t1.first); 
  
    cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second; 
} 
  
int main() 
{ 
    int n,i;
    cout<<"Enter n : ";
    cin>>n;
    Graph g(n);
    cout<<"enter links"<<endl;
    for(i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b); 
    }
    
  
    g.longestPathLength(); 
    return 0; 
} 

