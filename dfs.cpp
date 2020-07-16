#include <bits/stdc++.h>
using namespace std;
bool alreadyExsists(vector<vector<int> > graph, int s, int d){
    for(auto j: graph[s])
        if( j == d ) return true;
    return false;
}
void inputEdge(vector<vector<int> > &graph, int s, int d, bool bidir = true){
    if(s >= graph.size() || d >= graph.size()){
        cout << "ERROR: Out Of Range" << endl;
        return;
    }
    if(alreadyExsists(graph, s, d)){
        cout << "ERROR: Edge " << s << " - " << d <<" Already Exisits" << endl;
    }
    graph[s].push_back(d); 
    if(bidir) graph[d].push_back(s); 
}
void inputData(vector<vector<int> > &graph){
    inputEdge(graph, 0, 2); inputEdge(graph, 0, 3); 
    inputEdge(graph, 1, 2); inputEdge(graph, 1, 3);
    inputEdge(graph, 4, 1); inputEdge(graph, 3, 2);
    cout << "DATA INPUT - DONE" << endl;
}
void selfParent(vector<int> &parent){
    int n = parent.size();
    for(int i=0; i<n; i++) 
        parent[i] = i;
    cout << "SELF PARENT - DONE" << endl;
}
void dispList(vector<int>parent){
    int n = parent.size();
    cout<<endl;
    for(int i=0; i<n; i++) cout << parent[i] << " ";
    cout<<endl;
}
void dfs(vector<vector<int> >graph, vector<int> &parent, int startIndex, vector<bool> &visited){
    cout << startIndex << " ";
    visited[startIndex] = true;
    for(auto i: graph[startIndex]){
        if( !visited[i] ){
            parent[i] = startIndex;
            dfs(graph, parent, i, visited);
        }
    }
}
int main(){
    int n = 5, startIndex = 1;
    vector<vector<int> > graph(n);
    inputData(graph);
    
    vector<int> parent(graph.size());
    vector<bool> visited(graph.size(), false);
    
    selfParent(parent);
    dfs(graph, parent, startIndex, visited);
    dispList(parent);
    
    
    return 0;
}
