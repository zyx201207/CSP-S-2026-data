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
const int N=10;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
    cout<<N<<" "<<rd()%(N-1)+2<<endl;
    for(int i=2;i<=N;i++) cout<<i<<" "<<rd()%(i-1)+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    cout<<"0 1"<<endl;
    while(t--) solve();
    return 0;
}