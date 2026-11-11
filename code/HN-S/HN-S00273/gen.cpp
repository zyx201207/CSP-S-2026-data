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
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e7,V=1e9;
void solve(){
    cout<<N<<endl;
    for(int i=1;i<=N;i++) cout<<rd()%V+1<<" ";
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}