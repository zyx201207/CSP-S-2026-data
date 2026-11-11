#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
int n, k;
vector<int> G[N];
int a[N];
bool f[N], vis[N];
int d = inf;
int ans = inf;

void dfs2(int u, int fa) {
    vis[u] = true;

    for (const int& v : G[u])
        if (v != fa && f[v])
            dfs2(v, u);
}

void dfs3(int u, int fa, int dis) {
    if (f[u]) {
        d = min(d, dis);
        return;
    }

    for (const int& v : G[u])
        if (v != fa)
            dfs3(v, u, dis + 1);
}

void dfs(int x, int cnt) {
    if (cnt == k) {
        int m = 0;
        for (int i = 1; i <= cnt; i++)
            if (!vis[i]) {
                dfs2(i, -1);
                m++;
            }
        if (m > 2) return;

        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (!f[i]) {
                d = inf;
                dfs3(x, -1, 0);
                sum += d;
            }
        ans = min(ans, sum);

        memset(vis, false, sizeof vis);
    }

    if (x > n) return;
    
    dfs(x + 1, cnt);

    a[cnt + 1] = x;
    f[x] = true;
    dfs(x + 1, cnt + 1);
    a[cnt + 1] = 0;
    f[x] = false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    
    int c, t;
    cin >> c >> t;

    while (t--) {
        cin >> n >> k;

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        ans = inf;
        dfs(1, 0);
        cout << ans;
    }

    return 0;
}
