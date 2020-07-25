#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int tree[4*MAX+4] = {0};
void dispTree(int n){
    cout << endl;
    for(int i=1; i<=2*n; i++)
        cout << tree[i] << " ";
    cout << endl;
    cout<<"==========================================="<<endl;
}
void build(int *a, int node, int start, int end){
    
    // to avoid out of bound error 
    if(start > end) return;
    
    // only 1 node left 
    if( start == end ){
        tree[node] = a[start];
        return;
    }
    
    // finding center point of start and end 
    int mid = (start+end)/2;
    
    // send recursive call to left and right of the tree 
    // left child being 2*node and right child being 2*node +1
    // for tree to begin with 1 
    build(a, 2*node, start, mid);
    build(a, 2*node+1, mid+1, end);
    
    // sum the values of children nodes to parent ndoe 
    tree[node] = tree[2*node] + tree[2*node+1];
}
int sum(int node, int start, int end, int l, int r){
    
    // to avoid out of bound error
    if( l>end or r<start ) return 0;
    
    // range of query is between the range of selected tree
    if( l<=start and r>=end ) return tree[node];
    
    // finding center point of start and end 
    int mid = (start+end)/2;
    
    // calling left and right tree to get their sum
    int p1 = sum(2*node, start, mid, l, r);
    int p2 = sum(2*node+1, mid+1, end, l, r);
    
    // return the sum of the children trees or nodes
    return p1 + p2;
}
void update(int node, int start, int end, int l, int r, int value){
    // to prevent out of bound 
    if( l > end or r < start ) return;
    
    // if we reached the node to change
    if(start == end){
        tree[node] = value;
        return;
    }
    
    // finding mid of start and end
    int mid = (start+end)/2;
    
    // update the tree at right and left 
    update(2*node, start, mid, l, r, value);
    update(2*node+1, mid+1, end, l, r, value);
    
    // update the current node if value of child node changes
    tree[node] = tree[2*node] + tree[2*node+1];
}
void updateNode(int node, int start, int end, int index, int value){
    // preventing out of bound error
    if(index > end or index < start) return;
    
    // if we are at the node to update
    if(start == end){
        tree[node] = value;
        return;
    }
    
    // finding the central node
    int mid = (start+end)/2;
    
    // calling the left and right tree and updating them
    updateNode(2*node, start, mid, index, value);
    updateNode(2*node+1, mid+1, end, index, value);
    
    // update the current node if value of child node changes
    tree[node] = tree[2*node] + tree[2*node+1];
}
int main(){
    int a[] = {-1, 1, 3, 4, 7, 9, 11, 13, 15};
    // 0th index not included so marked as -1
    
    int n = sizeof(a)/sizeof(int);
    int node = 1, start = 1, end = n-1;
    
    // builds a tree in the global array tree 
    build(a, 1, start, end);
    dispTree(n);
    
    int l=2, r=5;
    cout << "The sum is = " << sum(node, start, end, l, r) << endl; 
    
    update(node, start, end, 3, 4, 3);
    cout << "The sum is = " << sum(node, start, end, l, r) << endl; 
    
    updateNode(node, start, end, 4, 7);
    cout << "The sum is = " << sum(node, start, end, l, r) << endl;
    
    return 0;
}
/*

63 15 48 4 11 20 28 1 3 4 7 9 11 13 15 0 0 0 
===========================================
The sum is = 23
The sum is = 18
The sum is = 22

*/
