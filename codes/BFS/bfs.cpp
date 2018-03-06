#include <bits/stdc++.h>

using namespace std;

void bfs(int n, vector<int>g[], int source){
    bool visited[n+1];
    int distance[n+1];
    for(int i=1;i<=n;i++) {
        visited[i] = false;
    }
        
    queue<int>q;
    q.push(source);
    visited[source] = 1;
    distance[source] = 0;
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<(int)g[u].size();i++){
            int v=g[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                distance[v] = distance[u] + 1;
            }
        }
    }
    for(int i=1
        ;i<=n;i++){
        cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
    }
}
int main(){
    
    vector<int>g[10000]; //this code can handle maximum 10000 nodes
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    for(int i=0;i<numEdges;i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int source;
    cin>>source;
    bfs(numNodes, g, source);
    
    return 0;
}
