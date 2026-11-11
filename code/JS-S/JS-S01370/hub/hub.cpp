#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+5,M=5e5+5;
vector<int>g[N];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<k-1<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1,c;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}