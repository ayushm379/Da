#include <iostream>
using namespace std;
void leaveLine(){
    cout << endl;
    cout << "========================================";
    cout << endl;
}
void solve(string s, int n, int i = 0, string output = ""){
    if(i >= n){
        cout << "{ " << output << " }" << endl;
        return;
    }
    solve(s, n, i+1, output);
    solve(s, n, i+1, output+s[i]);
}
void print1toN(int n){
    if(n<=0)
        return;
    print1toN(n-1);
    cout << n <<" ";
}
void printNto1(int n){
    if(n<=0)
        return;
    cout << n << " ";
    printNto1(n-1);
}
void sortArray(int *a, int n, int i=0, int j=0){
    if(i >= n or j >= n-1){
        return;
    }
    
    if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
        
    sortArray(a, n, i, j+1);
    sortArray(a, n, i+1, 0);
}
void printArray(int *a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
string removeDuplicates(string s, int n, bool* visited, int i=0){
    if(n<=i) return "";
    int index = s[i] - 'a';
    if( !visited[index] ){
        visited[index] = true;
        return s[i] + removeDuplicates(s, n, visited, i+1);
    }else{
        return removeDuplicates(s, n, visited, i+1);
    }
}

int main(){
    
    string s = "abc";
    int n = s.length();
    solve(s, n);
    leaveLine();
    
    print1toN(n);
    leaveLine();
    
    printNto1(n);
    leaveLine();
    
    int a[] = {6, 2, 4, 1, 3, 5};
    n = sizeof(a)/sizeof(int);
    printArray(a, n);
    sortArray(a, n);
    printArray(a, n);
    leaveLine();
    
    s = "aabcddeeaaa";
    n = s.length();
    
    string output = "";
    bool visited[26] = {false};
    cout << removeDuplicates(s, n, visited);
    leaveLine();
    
    

    return 0;
}
