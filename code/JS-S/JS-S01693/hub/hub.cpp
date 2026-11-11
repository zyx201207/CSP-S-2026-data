#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k, ans;
vector<int>g[1000005];
int f[1000005];
struct node {
    int deg, id, sz, dep;
} a[1000005];
void dfs(int u, int fa) {
    f[u] = fa;
    a[u].sz = 1;
    dep[u] = dep[fa] + 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        a[u].sz += a[v].sz;
    }
}
bool cmp(node a, node b) {
    if (a.deg != b.deg) return a.deg > b.deg;
    return a.sz > b.sz;
}
void dist(int a, int b) {
    int x = 0;
    if (a[a].dep < a[b].dep) swap(a, b);
    while (a[a].dep > a[b].dep) a = f[a], x++;
    while (a != b) a = f[a], b = f[b], x++;
    return x;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            a[u].deg++;
            a[v].deg++;
            a[u].id = u;
            a[v].id = v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (c > 10) {
            cout << "2\n";
            continue;
        }
        dfs(1, 0);
        sort(a + 1, a + n + 1, cmp);
        ans = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 1e9;
            for (int j = 1; j <= k; j++) {
                sum = min(sum, dist(i, j));
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}