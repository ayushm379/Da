#include <bits/stdc++.h>
using namespace std;

void dispActivities(vector<pair<int, int> > list, int size){
    // displays list
    cout << "Disp List" << endl;
    for(int i=0; i<size; i++)
        cout << i+1 << list[i].first << " - " << list[i].second << endl;
}

bool compare(pair<int, int> a, pair<int, int> b){
    // activities are sorted on the basis of their finish time
    return ( a.second < b.second );
}

void selectActivities(vector<pair<int, int> > list, int size){
    sort(list.begin(), list.end(), compare);
    dispActivities(list, size);
    
    int j = 0;
    cout << "{ " << list[0].first << " - " << list[0].second << " }" << endl;
    
    for(int i=1; i<size; i++){
        if( list[i].first >= list[j].second ){
            cout << "{ " << list[i].first << " - " << list[i].second << " }" << endl; 
            j = i;
        }
    }
    
}

int main(){
    int size, x, y; cin>>size;
    vector<pair<int, int> > list(size);
    
    for(int i=0; i<size; i++){
        cin>>x>>y;
        list[i] = make_pair(x, y);
    }
    
    dispActivities(list, size);
    selectActivities(list, size);
    
    return 0;
}
/*
input - 

6 
5 9
1 2
3 4
0 6 
5 7
8 9

*/
