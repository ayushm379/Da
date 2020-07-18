#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
void disp(vector<pair<float, pair<float, float> > > items, int n){
    cout<< "index profit weight   p/w" << endl;
    for(int i=0; i<n; i++)
        cout << i << "\t" << items[i].ss.ff << "\t" << items[i].ss.ss << "\t" << items[i].ff << endl;
          
    cout << "------------------" << endl;    
}
bool compare(pair<float, pair<float, float> > a, pair<float, pair<float, float> >b){
    return ( a.ff > b.ff );
}
float knabSack(vector<pair<float, pair<float, float> > > items, int n, float sack){
    sort(items.begin(), items.end(), compare);
    disp(items, n);
  
    cout << "Total Sack Size\t" << sack << endl;
    float maxProfit = 0;
    
    for(int i=0; i<n; i++){
        if(sack <= items[i].ss.ss){
            maxProfit += float( sack / items[i].ss.ss ) * items[i].ss.ff ; 
            cout << i << " Selected only\t\t" << sack << endl;
            return maxProfit;
        }
        if( items[i].ss.ss  < sack ){
            sack -= items[i].ss.ss;
            maxProfit += items[i].ss.ff * items[i].ss.ss;
            cout << i << " Selected Completely\t" << sack << "\tTotalProfit "<<maxProfit  <<  endl;
        }
    }
    
    return maxProfit;
}
int main(){
    int n = 7, sack = 15;
    int profit[] = {10, 5, 15, 7, 6, 18, 3};
    int weight[] = {2, 3, 5, 7, 1, 4, 1};
    vector<pair<float, pair<float, float> > >items(n);
    
    for(int i=0; i<n; i++){
        items[i].ss.ff = profit[i];
        items[i].ss.ss = weight[i];
        items[i].ff = float(profit[i]/weight[i]);
    }
  
    cout << knabSack(items, n, sack) << endl;
    return 0;
}

/*
Result - 

index profit weight   p/w
0	6	1	6
1	10	2	5
2	18	4	4
3	15	5	3
4	3	1	3
5	5	3	1
6	7	7	1
------------------
Total Sack Size	15
0 Selected Completely	14	TotalProfit 6
1 Selected Completely	12	TotalProfit 26
2 Selected Completely	8	TotalProfit 98
3 Selected Completely	3	TotalProfit 173
4 Selected Completely	2	TotalProfit 176
5 Selected only		2
179.333

*/
