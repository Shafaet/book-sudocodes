#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<28
#define mx 100

void bellman(int n, vector<int>g[], vector<int>cost[], int source){
    int distance[n+1];
    for(int i=1;i<=n;i++){
        distance[i] = infinity;
    }
    distance[source] = 0;
    bool neg_cycle = false;
   
    for(int k=1;k<=n;k++){
        bool updated = false;
        for(int u=1;u<=n;u++){
            for(int i=0;i<(int)g[u].size();i++){
                int v = g[u][i];
                //Relaxation
                if(distance[u] + cost[u][i] < distance[v]){
                    updated = true;
                    distance[v] = distance[u] + cost[u][i];
                }
            }
        }
        
        if(k==n and updated==true){ //update in the n^th iteration
            neg_cycle = true;
        }
    }
    if(neg_cycle)puts("Negative cycle detected");
    else
    {
        for(int i=1;i<=n;i++){
            cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
        }
    }
}

int main(){
    freopen("in", "r", stdin);
    vector<int>g[10000],cost[10000]; 
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    
        
    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    
    int source;
    cin>>source;
    bellman(numNodes, g, cost, source);
    
    
    return 0;
}
