#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define WHITE 0
#define GREY 1
#define BLACK 2

vector< int > G[MAXN];
int dfsTime = 0;
int color[MAXN];
int d[MAXN];
int f[MAXN];

void DFS(int u) {
	dfsTime = dfsTime + 1;
	d[u] = dfsTime;
	color[u] = GREY;
	for(int i = 0; i<(int)G[u].size(); i++) {
		int v = G[u][i];
		//if color[v] is grey, it is a back edge
		//if color[v] is white, it is a tree edge
		if(color[v] == WHITE) {
			DFS(v);
		} 
	}
	color[u] = BLACK;
	dfsTime = dfsTime + 1;
	f[u] = dfsTime;
}
int main(){

	int n, e;
	cin>>n>>e;
	for(int i = 0; i < e; i++) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	
	for(int i=1;i<=n;i++){
		if(color[i] == WHITE) {
			DFS(i);
		}
	}
	
	for(int i = 1; i <=n; i++){
		cout<<i<<" -> "<<d[i]<<" "<<f[i]<<endl;
	}
    return 0;
}
