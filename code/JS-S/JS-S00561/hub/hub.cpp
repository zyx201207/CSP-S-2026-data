#include<bits/stdc++.h>
#define int long long
#define REP(i,a,b,c) for(int i=a;i<=b;i+=c)
#define PER(i,a,b,c) for(int i=a;i>=b;i-=c)
#define sz(s) s.size()
using namespace std;
const int N=1e5+5;
int c,n,k,u,v;
void solve(){
    cin>>n>>k;
    REP(i,1,n-1,1) cin>>u>>v;
    int m=(n-1)/2;
    cout<<m-1<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>c>>t;
    while(t--) solve();
}
