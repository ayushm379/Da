#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
void getData(vector<pair<int, pair<int, int> > >&graph, int e){
    int a[] = {0, 0, 0, 0, 1, 1, 2};
    int b[] = {1, 3, 2, 4, 2, 3, 4};
    int w[] = {5, 4, 4, 3, 1, 2, 1};
    for(int i=0; i<e; i++)
        graph[i] = make_pair(w[i], make_pair(a[i], b[i]) );
}
bool compare(pair<int, pair<int, int> >a, pair<int, pair<int, int> >b){
    return (a.ff < b.ff);
}
void selfParent(vector<int> &parent, int n){
    for(int i=0; i<n; i++) 
        parent[i] = i;
}
int findParent(vector<int> parent, int val){
    if(val == parent[val]) return val;
    return findParent(parent, parent[val]);
}
bool unionFun( vector<int> &parent, int val1, int val2 ){
    int p1 = findParent(parent, val1), p2 = findParent(parent, val2);
    if( p1 == p2 ) return false;
    if( p1 < p2 ) parent[p2] = p1;
    else parent[p1] = p2;
    return true;
}
void dispList(vector<int> parent, int n){
    cout << "\nParent Array \t";
    for(int i=0; i<n; i++) 
        cout << parent[i] << " ";
    cout << endl;
}
void kruskals(vector<pair< int, pair<int, int> > >graph, int e, int n){
    sort(graph.begin(), graph.end(), compare);
    vector<int> parent(n); 
    selfParent(parent, n);
    int sum = 0;
    for(int i=0; i<e; i++){
        if( unionFun( parent, graph[i].ss.ff, graph[i].ss.ss ) ){
            cout << graph[i].ss.ff << " - " << graph[i].ss.ss <<" is added" << endl;
            sum += graph[i].ff;
        }
    }
    cout << "\tTotal sum of edges of MST = " << sum << endl;
    dispList(parent, n);
}
int main(){
    int n = 5, e = 7;
    vector<pair<int, pair<int, int> > >graph(e);
    getData(graph, e);
    kruskals(graph, e, n);
    return 0;
}
/*

1 - 2 is added
2 - 4 is added
1 - 3 is added
0 - 4 is added
Total sum of edges of MST = 7

Parent Array 	0 0 1 1 1 

*/
