#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, k;
vector<int>e[2000005];
int a[2000005];
bool vis[2000005];
bool f[2000005];
int dis[2000005];
void bfs(int s) {
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (!f[v]) continue;
            if (vis[v])continue;
            vis[v] = true;
            q.push(v);
        }
    }
}
int ans;
void dfs(int pos) {
    if (n - a[pos - 1] + pos - 1 < k) return;
    if (pos == k + 1) {
        memset(vis, false, sizeof(vis));
        memset(f, false, sizeof(f));
        for (int i = 1; i <= k; i++) f[a[i]] = true;
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
            if (vis[a[i]]) {
                continue;
            }
            cnt++;
            bfs(a[i]);
        }
        if (cnt > 2)return;
        for (int i = 1; i <= n; i++) {
            dis[i] = INT_MAX - 5;
        }
        int mx = 0;
        queue<int>q;
        for (int i = 1; i <= k; i++) {
            q.push(a[i]);
            dis[a[i]] = 0;
        }
        while (q.size()) {
            int u = q.front();q.pop();
            for (int i = 0; i < e[u].size(); i++) {
                int v = e[u][i];
                if (dis[v] != INT_MAX - 5)continue;
                dis[v] = dis[u] + 1;
                mx = max(mx, dis[v]);
                q.push(v);
            }
        }
        ans = min(ans, mx);
        return;
    }
    for (int i = a[pos - 1] + 1; i <= n; i++) {
        a[pos] = i;
        dfs(pos + 1);
    }
}
void solve() {
    ans = INT_MAX - 5;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    printf("%d\n", ans);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        solve();
    }
    return 0;
}
