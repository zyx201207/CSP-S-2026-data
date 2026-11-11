#include<bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18, MAXX = 1e6 + 5;

int n, k, vis[MAXX], flag[MAXX], u, v, op, t, ans;
vector<int> e[MAXX];

void DFS(int x, int fa){
    flag[x] = 1;
    for(int i = 0; i < e[x].size(); i++){
        int y = e[x][i]; if(y == fa) continue;
        if(vis[y]) DFS(y, x);
    }
}

int Get(int x, int fa){
    if(vis[x]) return 0;
    int ans = INF;
    for(int i = 0; i < e[x].size(); i++){
        int y = e[x][i]; if(y == fa) continue;
        ans = min(ans, Get(y, x) + 1);
    } return ans;
}

void dfs(int x){
    if(x > n){
        int sum = 0, tot = 0, res = 0;
        for(int i = 1; i <= n; i++) sum += vis[i], flag[i] = 0;
        if(sum != k) return;
        for(int i = 1; i <= n; i++){
            if(vis[i] && flag[i] == 0) DFS(i, 0), tot++;
        } if(tot > 2) return;
        for(int i = 1; i <= n; i++) res = max(res, Get(i, 0));
        // for(int i = 1; i <= n; i++) cout << vis[i] << " "; cout << '\n';
        // cout << res << '\n';
        ans = min(ans, res);
        return;
    } vis[x] = 0, dfs(x + 1);
    vis[x] = 1, dfs(x + 1);
}

void solve(){
    cin >> n >> k; ans = INF;
    for(int i = 1; i <= n; i++) e[i].clear();
    for(int i = 1; i < n; i++){
        cin >> u >> v; e[u].push_back(v), e[v].push_back(u);
    } dfs(1); cout << ans << '\n';
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> op >> t;
    while(t--) solve();
    return 0;
}