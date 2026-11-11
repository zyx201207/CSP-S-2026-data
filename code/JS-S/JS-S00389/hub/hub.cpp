#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1005;
int c;
int n, k, dis[N][N], f[25][N], d[N];
bool vis[N], checked[N];
vector<int> e[N];

void ck(int u, int fa) {
    checked[u] = true;
    for(auto v: e[u]) {
        if(v == fa) continue;
        if(vis[v] && !checked[v]) 
            ck(v, u);
    }
}

bool check() {
    int cnt = 0;
    for(int i=1;i<=n;i++) checked[i] = false;
    for(int i=1;i<=n;i++) {
        if(vis[i] && !checked[i]) {
            ck(i, 0);
            cnt++;
        }
    }
    return cnt<=2;
} 

void dfs(int u, int fa) {
    for(auto v: e[u]) {
        if(v == fa) continue;
        f[0][v] = u;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void init() {
    d[1] = 1;
    dfs(1, 0);
    for(int i=1;i<=22;i++) 
        for(int j=1;j<=n;j++) 
            f[i][j] = f[i-1][f[i-1][j]];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int u = i, v = j;
            if(d[u] < d[v]) swap(u, v);
            int del = d[u]-d[v];
            for(int k=22;k>=0;k--)
                if(del & (1<<k))
                    u = f[k][u];
            if(u == v) {
                dis[i][j] = max(d[i],d[j])-d[u];
                // cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
                continue;
            }
            for(int k=22;k>=0;k--) 
                if(f[k][u] != f[k][v]) 
                    u = f[k][u], v = f[k][v];
            int lca = f[0][u];
            dis[i][j] = d[u]-d[lca] + d[v]-d[lca];
            // cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
        }
    }
}

void work() {
    cin >> n >> k;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init();
    int ans = 1e9;
    for(int i=1;i<(1<<n);i++) {
        int cc = __builtin_popcount(i);
        if(cc != k) continue;
        for(int j=0;j<n;j++) {
            if(i & (1<<j))
                vis[j+1] = true;
            else
                vis[j+1] = false;
        }
        if(!check()) continue;
        int as = 0;
        for(int j=1;j<=n;j++) {
            int mn = 1e9;
            for(int k=1;k<=n;k++) {
                if(!vis[k]) continue;
                mn = min(mn, dis[j][k]);
            }
            as = max(as, mn);
        }
        ans = min(ans, as);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int t;
    cin >> c >> t;
    while(t--) { work(); }
    return 0;
}