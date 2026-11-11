#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define int long long
int T, n, k, flag[N], vis[N], dis[N], cnt, ans;
vector<int> e[N];
queue<int> que;
void dfs(int u) {
    vis[u] = 1;
    for(int v : e[u])
        if(!vis[v] && flag[v]) dfs(v);
}
void bfs() {
    for(int i = 1;i <= n;i++)
        if(flag[i]) que.push(i), dis[i] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int v : e[u])
            if(dis[v] == 1e18) que.push(v), dis[v] = dis[u] + 1;
    }
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T >> T;
    while(T--) {
        cin >> n >> k; ans = 1e18;
        for(int i = 1;i <= n;i++) e[i].clear();
        for(int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i = 1;i < (1 << n);i++) {
            if(__builtin_popcount(i) != k) continue;
            cnt = 0;
            for(int j = 1;j <= n;j++) {
                if(i & (1 << (j - 1))) flag[j] = 1;
                else flag[j] = 0;
                vis[j] = 0; dis[j] = 1e18;
            }
            for(int j = 1;j <= n;j++)
                if(flag[j] && !vis[j]) dfs(j), cnt++;
            if(cnt > 2) continue;
            bfs();
            int maxx = 0;
            for(int j = 1;j <= n;j++) maxx = max(maxx, dis[j]);
            ans = min(ans, maxx);
        }
        cout << ans << endl;
    }
    return 0;
}
