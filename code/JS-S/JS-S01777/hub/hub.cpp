#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N=4005;
constexpr ll inf=(1ll<<60);
ll c,T;
vector<ll>g[N];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin >> c >> T;
    while(T--) {
        ll n,k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) g[i].clear();
        for(int i=1; i<n; i++) {
            ll u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==1) cout << 0;
        if(k==2) cout << 1;
        cout << '\n';
    }
    return 0;
}
