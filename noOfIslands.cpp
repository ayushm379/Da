#include <bits/stdc++.h>
using namespace std;
void dfs(int a[4][4], bool visited[4][4], int n, int i, int j){
    // if visited or not land, i.e. 0 return 
    if(visited[i][j] or a[i][j] == 0) return;
    // if out of bound return
    if(i >= n or i < 0 or j >= n or j < 0) return;
    
    // check the visited, saying this land is already visited
    visited[i][j] = true;
    
    // recursively call the 4 land chunks nearby 
    dfs(a, visited, n, i+1, j);
    dfs(a, visited, n, i-1, j);
    dfs(a, visited, n, i, j+1);
    dfs(a, visited, n, i, j-1);
}
int main(){
    int n = 4, noOfIslands = 0;
    int a[4][4] = {
        {1, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };
    bool visited[4][4] = {false};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // only if there is land {a[i][j] == 1} and not visited move in dfs function
            if( a[i][j] == 1 and !visited[i][j] ){
                dfs(a, visited, n, i, j);
                noOfIslands++;
            }
        }
    }
    
    cout << "No of islands = " << noOfIslands << endl;
    return 0;
}
