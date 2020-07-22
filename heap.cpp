#include <bits/stdc++.h>
using namespace std;
void heapify(int *a, int n, int i=0){
    int c1 = 2*i+1, c2 = 2*i+2, max = i;
    
    // c1 and c2 are 2 child nodes of node i 
    
    // finding the maximum value amongst the 3 { a parent and 2 children }
    if( c1 < n and a[c1] > a[max] ) max = c1; 
    if( c2 < n and a[c2] > a[max] ) max = c2;
    
    // if current node is not max, swap the node from the max node (any of the child)
    // then call the heapify function for the replaced value 
    // As the value placed there could be smaller than the value of its new children 
    if( i != max ){
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}
void buildHeap(int *a, int n){
    cout << "BUILDING HEAD" << endl;
    for(int i=n/2; i>=0; i--){
        heapify(a, n, i); // calling heapify on non leaf nodes 
    }
}
void dispList(int *a, int n){
    cout << "Heap\t";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl << endl;
}
int extract(int *a, int &n){
    int temp = a[0]; // store the largest value in a variable and return it
    a[0] = a[n-1]; 
    n--; // decrease the size of heap
    heapify(a, n, 0); // call heapify on only the first node, since it is only misplaced node
    return temp;
}
void headSort(int *a, int n){
    for(int i=n-1; i>0; i--){
        swap(a[0], a[i]); // storing the largest value at the end of the heap 
        heapify(a, i, 0); // assuming it is not present, calling for heapify without the last value
    }
}
int main(){
    
    int n = 7;
    int a[] = {2, 5, 1, 3, 4, 7, 6}; 
    
    buildHeap(a, n);
    dispList(a, n);
    
    headSort(a, n);
    dispList(a, n);
    
    buildHeap(a, n);
    
    while(n){
        cout << extract(a, n) << " is extracted" << endl;
    }
    
    return 0;
}

/*
BUILDING HEAD
Heap	7 5 6 3 4 1 2 

Heap	1 2 3 4 5 6 7 

BUILDING HEAD
7 is extracted
6 is extracted
5 is extracted
4 is extracted
3 is extracted
2 is extracted
1 is extracted
*/
