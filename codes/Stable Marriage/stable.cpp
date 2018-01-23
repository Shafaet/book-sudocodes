#include <bits/stdc++.h>

using namespace std;


int main(){
    
    int engagedTo[1000];
	queue<int>menPrefQ[1000];
	queue<int>freeMenQ;
	map<string, int>mark;
	string numberToString[1000];
	int womenPrefRank[1000][1000];
	memset(womenPrefRank, -1, sizeof womenPrefRank);
	memset(engagedTo, -1, sizeof engagedTo);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		string u;
		cin>>u;
		int numNodes = i;
		mark[u] = numNodes;
		numberToString[numNodes] = u;
		freeMenQ.push(mark[u]);
	}
	
	for(int i =1 ;i <= n;i++) {
		string u;
		cin>>u;
		int numNodes = n + i;
		mark[u] = numNodes;
		numberToString[numNodes] = u;
	}
	
	for(int u = 1 ; u <= n; u++) {
		for(int j = 1 ; j <=n ; j++) {
			string v;
			cin>>v;
			menPrefQ[u].push(mark[v]);
		}
	}
	
	for(int v = n + 1 ; v <= n + n; v++) {
		for(int j = 1; j <= n; j++){
			string u;
			cin>>u;
			womenPrefRank[v][mark[u]] = n - j + 1;
		}
	}
	
	while(!freeMenQ.empty()){
		int u = freeMenQ.front();
		freeMenQ.pop();
		int v = menPrefQ[u].front();
		menPrefQ[u].pop();
		if(engagedTo[v] == -1) {
			engagedTo[v] = u;
		} else {
			int w = engagedTo[v];
			if(womenPrefRank[v][u] > womenPrefRank[v][w]) {
				freeMenQ.push(w);
				engagedTo[v] = u;
			} else {
				freeMenQ.push(u);
			}
		}
	}
	
	
	for(int i = n + 1; i <= n + n;i++) {
		cout<<numberToString[i]<<" "<<numberToString[engagedTo[i]]<<endl;
	}
    return 0;
}
