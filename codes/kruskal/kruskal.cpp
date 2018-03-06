#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<28
#define mx 100000

int parent[mx];
void makeset(int u){
    parent[u] = u;
}
void init_disjoint_set(int numNodes){
    for(int i=1;i<=numNodes;i++) {
        makeset(i);
    }
}

int find_representative(int u){
    if(parent[u]==u) return u;
    return find_representative(parent[u]);
}

int set_union(int u,int v){
    int rep_u = find_representative(u);
    int rep_v = find_representative(v);
    if (rep_u != rep_v) {
        parent[rep_u] = rep_v;
        return true;
    }
    return false; //u, v are already in same component
}

struct edge{
    int u, v, w;
    edge(int _u,int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};
bool comp(edge a, edge b){
    return a.w < b.w;
}
int main(){
    //freopen("in", "r", stdin);
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    init_disjoint_set(numNodes);
    
    vector<edge>edges;
    for(int i=0;i<numEdges;i++){
          int u, v, w;
          cin>>u>>v>>w;
          edges.push_back(edge(u, v,w));
    }
    
    sort(edges.begin(), edges.end(), comp);
    
    int sum = 0;
    for(int i=0;i<(int)edges.size();i++){
        edge currentEdge = edges[i];
        int ret = set_union(currentEdge.u, currentEdge.v);
        if(ret == true){
            sum = sum + currentEdge.w;
        }
    }
    
    cout<<sum<<endl;
   
    return 0;
}

