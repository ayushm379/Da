#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m){
    // if we reached first block, and the path is unique so this is 1 path
    if(n==1 and m==1) return 1;
    
    // for out of bound
    if(n < 1 or m < 1) return 0;
    
    // since from the start position we can only go to right or bottom
    // so from end position we need to go to left {n-1} or top {m-1}
    return solve(n-1, m) + solve(n, m-1);
}
int main() {
	int t, n, m; cin>>t; 
	while(t--){
	    cin>>n>>m;
	    cout << solve(n, m) << endl;
	}
	return 0;
}
