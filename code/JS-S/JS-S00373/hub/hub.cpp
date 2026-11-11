#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
int C,T;
int n,k;
const int N = 1e6+5;
vector<int> g[N];
int nd, dis;
void dfs(int u, int d=0, int p=-1) {
    if(dis<d) dis=d, nd=u;
    for(int i : g[u]) {
        if(i==p) continue;
        dfs(i, d+1, u);
    }
}
void solve() {
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    dfs(nd);
    int x=nd;
    dfs(x);
    int y=nd;
    cout<<(dis-k)/2;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>C>>T;
    while(T--) solve();
    return 0;
}