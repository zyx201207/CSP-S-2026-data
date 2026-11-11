#include <bits/stdc++.h>
using namespace std;
const int N = 38;
int TEST, T, n, k, dis[N], vis[N], ina[N], a[N], ans = 1e9;
vector <int> g[N];
int calc() {
    queue <int> q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= k; i++) q.push(a[i]), dis[a[i]] = 0, vis[a[i]] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto v : g[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dis[i]);
    if (res == 1) for (int i = 1; i <= k; i++) cout << a[i] << " \n"[i == k];
    return res;
}
void dfs2(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (!vis[v] && ina[v]) {
            dfs2(v);
        }
    }
    return;
}
bool check() {
    int res = 0;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= k; i++) {
        if (vis[a[i]]) continue;
        dfs2(a[i]);
        res++;
        if (res > 2) return 0;
    }
    return (res <= 2);
}
void dfs(int lst, int cnt) {
    if (cnt > k) {
        if (check()) ans = min(ans, calc());
        return;
    }
    for (int i = lst + 1; i <= n; i++) {
        a[cnt] = i;
        ina[i] = 1;
        dfs(i, cnt + 1);
        a[cnt] =  0;
        ina[i] = 0;
    }
    return;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &TEST, &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs(0, 1);
        cout << ans << endl;
        ans = 1e9;
        for (int i = 1; i < n; i++) while (g[i].size()) g[i].pop_back();
    }
    return 0;
}
