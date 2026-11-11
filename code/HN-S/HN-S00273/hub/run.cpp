#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
#define pii pair<int,int>
#define pdd pair<double,double>
#define pb push_back
#define umap unordered_map
#define pq priority_queue
#define mset multiset
#define ull unsigned long long
#define i128 __int128
#define fixs fixed<<setprecision
#define FileIn(x) freopen(x".in","r",stdin)
#define FileOut(x) freopen(x".out","w",stdout)
#define FileIO(x) FileIn(x),FileOut(x)
void solve(){
    int tc=0;
    while(1){
        system("./gen > in.txt");
        system("./tmp < in.txt > ans.txt");
        system("./hub < in.txt > out.txt");
        if(system("diff out.txt ans.txt -b -w")){
            cout<<"Wrong Answer on test #"<<++tc<<endl;
            break;
        }
        cout<<"Accepted on test #"<<++tc<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}