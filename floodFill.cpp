#include <bits/stdc++.h>
using namespace std;

void dispList(int a[8][8], int n){
    // display array 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "---------------" << endl;
}

void fun(int a[8][8], int n, int x, int y, int color, int currentColor){
    // to remove segmentation fault
    if( x>=n or y>=n or x<0 or y<0 ) return;
    
    // if any pixel's color is already changed
    if( a[x][y] != currentColor ) return;
    
    // change the value of pixel that hasnt been changed yet
    a[x][y] = color;
    
    // call the 4 pixels near that pixel
    fun(a, n, x+1, y, color, currentColor);
    fun(a, n, x-1, y, color, currentColor);
    fun(a, n, x, y+1, color, currentColor);
    fun(a, n, x, y-1, color, currentColor);
}

int main(){
    int a[8][8] = {
            {1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 0, 0},
            {1, 0, 0, 1, 1, 0, 1, 1},
            {1, 2, 2, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 0, 1, 0},
            {1, 1, 1, 2, 2, 2, 2, 0},
            {1, 1, 1, 1, 1, 2, 1, 1},
            {1, 1, 1, 1, 1, 2, 2, 1}
        };
    int n = 8, x = 4, y = 4, color = 3;
    
    dispList(a, n);
    int currentColor = a[x][y];
    
    fun(a, n, x, y, color, currentColor);
    dispList(a, n);
    
    return 0;
}
/*

1 1 1 1 1 1 1 1 
1 1 1 1 1 1 0 0 
1 0 0 1 1 0 1 1 
1 2 2 2 2 0 1 0 
1 1 1 2 2 0 1 0 
1 1 1 2 2 2 2 0 
1 1 1 1 1 2 1 1 
1 1 1 1 1 2 2 1 
---------------
1 1 1 1 1 1 1 1 
1 1 1 1 1 1 0 0 
1 0 0 1 1 0 1 1 
1 3 3 3 3 0 1 0 
1 1 1 3 3 0 1 0 
1 1 1 3 3 3 3 0 
1 1 1 1 1 3 1 1 
1 1 1 1 1 3 3 1 
---------------

*/
