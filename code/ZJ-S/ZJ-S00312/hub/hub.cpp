#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
int n, k;
vector <int> G[N];
int fa[N];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return ;
    fa[v] = u;
}
int count(int x){
    int cnt = 0;
    while(x) x &= x - 1, ++cnt;
    return cnt;
}
bool vis[N];
int minn, maxx;
void dfs(int u, int f, int dis){
    if(vis[u]) minn = std::min(minn, dis);
    for(int i = 0; i < G[u].size(); ++i){
        int v = G[u][i];
        if(v == f) continue;
        dfs(v, u, dis + 1);
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    int ans = 1e18;
    for(int msk = 0; msk < (1 << n); ++msk){
        if(count(msk) != k) continue;
        for(int i = 1; i <= n; ++i) vis[i] = 0, fa[i] = i;
        for(int i = 1; i <= n; ++i){
            if(msk >> i - 1 & 1){
                vis[i] = 1;
                for(int j = 0; j < G[i].size(); ++j){
                    int v = G[i][j];
                    if(msk >> v - 1 & 1) merge(i, v);
                }
            }
        }
        int rt1 = -1, rt2 = -1;
        bool flg = 1;
        for(int i = 1; i <= n && flg; ++i){
            if(vis[i]){
                if(rt1 == -1) rt1 = find(i);
                else if(find(i) != rt1){
                    if(rt2 == -1) rt2 = find(i);
                    else if(find(i) != rt2) flg = 0;
                }
            }
        }
        if(!flg) continue;
        maxx = 0;
        for(int i = 1; i <= n; ++i) if(!vis[i]) minn = 1e18, dfs(i, 0, 0), maxx = std::max(maxx, minn);
		ans = std::min(ans, maxx);
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i) G[i].clear();
}
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--) solve();
    return 0;
}
