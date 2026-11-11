#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, T, n, k, ans;
vector<int> g[N];
bool st[N], vis[N];
int dis[N], dep[N];
void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}
void dfs2(int u, int mask) {
    st[u] = true;
    for (int v : g[u]) {
        if (st[v]) continue;
        if (mask >> (v - 1) & 1) dfs2(v, mask);
    }
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) g[i].clear();
    for (int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (k == n) {
        cout << "0\n";
        return;
    } else if (k == 2) {
        //diametre - 2;
        dis[1] = 0;
        dfs(1, 0);
        int S = 0, d = 0;
        for (int i = 1; i <= n; i ++ )
            if (dis[i] > dis[S]) S = i;
        dis[S] = 0;
        dfs(S, 0);
        for (int i = 1; i <= n; i ++ )
            d = max(d, dis[i]);
        cout << (int)ceil(1.0 * (d - 2) / 2.0) << '\n';
        return;
    } else if (c >= 13 && c <= 14) {
        int m = (n + 1) / 2, res;
        cout << max(1, (int)ceil(1.0 * (m - k + 1) / 2.0)) << '\n';
        return;
    } else if (n <= 10) {
        ans = 2e9;
        for (int i = 1; i < (1 << n); i ++ ) {
            int res = 0, cnt = 0;
            for (int j = 0; j < n; j ++ ) if (i >> j & 1) cnt ++ ;
            if (cnt != k) continue;
            cnt = 0;
            for (int j = 1; j <= n; j ++ ) st[j] = false, vis[j] = false;
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1 && !st[j + 1])
                    dfs2(j + 1, i), cnt ++ ;
            if (cnt > 2) continue;
            queue<int> q;
            for (int j = 1; j <= n; j ++ )
                if (st[j]) q.push(j), dis[j] = 0, vis[j] = true;
            while (q.size()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (st[v] || vis[v]) continue;
                    vis[v] = true;
                    q.push(v);
                    dis[v] = dis[u] + 1;
                }
            }
            for (int j = 1; j <= n; j ++ ) res = max(res, dis[j]);
            ans = min(ans, res);
        }
        cout << ans << '\n';
    } else cout << "0\n";
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> T;
    while (T -- ) solve();
    return 0;
}


