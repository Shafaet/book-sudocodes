#include <bits/stdc++.h>

using namespace std;


int main(){
    freopen("in", "r", stdin);
    vector<int>g[10000]; //this code can handle maximum 10000 nodes
    int numEdges;
    int numNodes = 0;
    map<string, int>mark;
    cin>>numEdges;
    int indegree[10000] = {0};
    string numberToString[10000];

    for(int i=0;i<numEdges;i++){
        string a, b;
        cin>>a>>b;
        int u, v;
        
        if(mark.find(a) == mark.end()) { //We found a new node
			numNodes = numNodes + 1;	 //Increment number of nodes
			mark[a] = numNodes;          //Represent the String using an integer 
			numberToString[numNodes] = a; //do a reverse mapping too so that we can find the original node name
		}
		
		if(mark.find(b) == mark.end()) {
			numNodes = numNodes + 1;
			mark[b] = numNodes;
			numberToString[numNodes] = b;
		}
		
		u = mark[a];	//Get integer representation of the node name
		v = mark[b];
		
		g[u].push_back(v);
		indegree[v]++; //Keep track of indegree
    }
    
    queue<int>q; //this will contain all the nodes with indegree 0
    for(int u = 1; u<=numNodes; u++) {
		if (indegree[u] == 0) {
			q.push(u);
		}
	}
	
	vector<string>order;
	while(!q.empty()) {
		int u = q.front();
		order.push_back(numberToString[u]); //Add to answer
		q.pop();
		for(int i = 0;i<(int)g[u].size(); i++){
			int v = g[u][i];
			indegree[v] --;
			if(indegree[v] == 0) {
				q.push(v); //We found a new node which have indegree 0
			}
		}
	}
	
	for(int i=0;i<(int)order.size();i++){
		cout<<i+1 <<" > " <<order[i]<<endl;
	}
    return 0;
}
