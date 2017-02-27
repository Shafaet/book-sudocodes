#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<28
#define mx 100

void floyd_warshall(int numNodes, int g[][mx]){
    for(int k=1;k<=numNodes;k++){
        for(int i=1;i<=numNodes;i++){
            for(int j=1;j<=numNodes;j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){
    //freopen("in", "r", stdin);
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    int g[mx][mx];
    
    for(int i=1;i<=numNodes;i++){
        for(int j=1;j<=numNodes;j++){
            if(i==j) g[i][j]=0;
            else g[i][j]=infinity;
        }
    }
    
    for(int i=0;i<numEdges;i++){
        int u, v, w;
        cin>>u>>v>>w;
        g[u][v] = w;
        g[v][u] = w;

    }
    
    floyd_warshall(numNodes, g);
    for(int i=1;i<=numNodes;i++){
        for(int j=1;j<=numNodes;j++){
            cout<<g[i][j]<<" ";
        }
        puts("");
    }
    
    return 0;
}
