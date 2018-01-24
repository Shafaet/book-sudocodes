#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
vector< int > G[MAXN];
int parent[MAXN];
int low[MAXN]
int d[MAXN]
int visited[MAXN];
bool isArticulationPoint[MAXN];
int Time = 0;
 
void dfs(int u, int root) {
	Time = Time + 1;
    visited[u] = 1;
    d[u] = low[u] = Time;
    int noOfChildren = 0;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        if(v == parent[u]) continue;
        parent[v] = u;
        if(visited[v]) low[u] = min(low[u], d[v]);
        else {	
            noOfChildren = noOfChildren + 1;
            dfs(v, root);
            low[u] = min(low[u], low[v]);
            if(low[v] >= d[u] and u != root) isArticulationPoint[u] = 1;
        }
    }
    if(u == root and noOfChildren > 1) isArticulationPoint[u] = true;
}

int main(){
    //freopen("in", "r", stdin);
	int n, e;
	cin>>n>>e;
	for(int i = 0;i < e; i++) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	
	dfs(1, 1);
	for(int i = 1; i<=n;i++){
		if (isArticulationPoint[i]) {
			cout<<i<<endl;
		}
	}
    return 0;
}
