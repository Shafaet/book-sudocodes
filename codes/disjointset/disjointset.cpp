#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<28
#define mx 100000

int parent[mx];
void makeset(int u){
    parent[u] = u;
}
void init_disjoint_set(int numNodes){
    for(int i=1;i<=numNodes;i++){
        makeset(i);
    }
}

int find_representative(int u){
    if(parent[u]==u) return u;
    return find_representative(parent[u]);
}

void set_union(int u,int v){
    int rep_u = find_representative(u);
    int rep_v = find_representative(v);
    if(rep_u != rep_v){
        parent[rep_u] = rep_v;
    }
}

int main(){

    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    init_disjoint_set(numNodes);
    for(int i=0;i<numEdges;i++){
          int u, v;
          cin>>u>>v;
          set_union(u, v);
    }
    
    //print the number of different representatives
    set<int>representatives;
    for(int i=1;i<=numNodes;i++){
        representatives.insert(find_representative(i));
    }
    cout<<representatives.size()<<endl;
   
    return 0;
}

