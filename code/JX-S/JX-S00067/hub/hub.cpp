#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n, m, ans = 1e18, f[N], dis[N], flag[N];
vector<int> g[N];
int find(int x) {
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
bool check() {
    int cnt = 0;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= n; i++) {
        if(!flag[i]) continue;
        for(auto it : g[i]) {
            if(flag[it]) f[find(i)] = find(it);
        }
    } 
    for(int i = 1; i <= n; i++) {
        if(!flag[i]) continue;
        if(f[i] == i) cnt++;
    }
    return cnt <= 2;
}
int xfs() {
    g[0].clear();
    for(int i = 1; i <= n; i++) dis[i] = 1e18;
    for(int i = 1; i <= n; i++) if(flag[i]) g[0].push_back(i);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : g[u]) {
            if(dis[v] != 1e18) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dis[i]);
    return res - 1;
}
void dfs(int pos, int sum) {
    if(sum == m) {
        if(check()) ans = min(ans, xfs());
        return ;
    }
    if(pos == n + 1) return ;
    flag[pos] = 1;
    dfs(pos + 1, sum + 1);
    flag[pos] = 0;
    dfs(pos + 1, sum);
    return ;
}
void work() {
    ans = 1e18;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << "\n";
    return ;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    int c, t; cin >> c >> t;
    while(t--) work();
    return 0;
}