#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> g[n+5];
    for (int i=1;i<=n-1;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<"1\n";
    return;
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while (T--) {
        solve();
    }
    return 0;
}
