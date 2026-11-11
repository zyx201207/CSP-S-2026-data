#include<bits/stdc++.h>
using namespace std;

int n, k;
const int N = 1e6 + 10;
int vis[N], ok[N], dep[N], dis[N];
vector<int> g[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (ok[v] && !vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int u, int fa) {
    for (auto v : g[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 1e9;
        for (int s = 0; s < (1 << n); s++) {
            if (__builtin_popcount(s) != k) continue;
            for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = 1e9;
            for (int i = 1; i <= n; i++) {
                ok[i] = 0;
                if (!(s >> (i-1) & 1)) continue;
                ok[i] = 1;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!vis[i] && ok[i]) {
                    bfs(i);
                    ++cnt;
                }
            }
            if (cnt > 2) continue;
            for (int i = 1; i <= n; i++) {
                if (!ok[i]) continue;
                dep[i] = 0;
                dfs(i, 0);
                for (int j = 1; j <= n; j++) dis[j] = min(dis[j], dep[j]);
            }
            int mx = 0;
            for (int i = 1; i <= n; i++) mx = max(mx, dis[i]);
            ans = min(ans, mx);
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/