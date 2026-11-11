#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f;
int c, t, n, k;
vector<int> g[N];
bool book[N], vis[N];
int fa[N], size[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int u, int v) {
    u = find(u), v = find(v); if (u == v) return;
    if (size[u] < size[v]) swap(u, v);
    fa[v] = u, size[u] += size[v];
}
int solve(const vector<int>& v) {
    for (int i: v) fa[i] = i, size[i] = 1;
    for (int i: v) for (int j: g[i]) if (book[j]) merge(i, j);
    int cnt = 0;
    for (int i: v) cnt += fa[i] == i;
    if (cnt > 2) return inf;
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    for (int i: v) q.push({i, 0}), vis[i] = 1;
    int left = n - k, ans = 0;
    while (!q.empty() && left) {
        int u = q.front().first, d = q.front().second; q.pop();
        for (int v: g[u]) if (!vis[v])
            vis[v] = 1, left--, q.push({v, d + 1}), ans = max(ans, d + 1);
    }
    return ans;
}
int dfs(int m, int k) {
    if (m == n + 1) {
        vector<int> v;
        for (int i = 1; i <= n; i++) if (book[i]) v.push_back(i);
        return solve(v);
    }
    int ans = inf;
    if (n - m >= k) ans = min(ans, dfs(m + 1, k));
    if (k && n - m >= k - 1)
        book[m] = 1, ans = min(ans, dfs(m + 1, k - 1)), book[m] = 0;
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
        if (c <= 3) memset(book, 0, sizeof(book)), cout << dfs(1, k) << endl;
        else if (k == 1) {
            int ans = inf;
            for (int i = 1; i <= n; i++) ans = min(ans, solve({i}));
            cout << ans << endl;
        } else if (k == 2) {
            int ans = inf;
            for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++)
                ans = min(ans, solve({i, j}));
            cout << ans << endl;
        }
    }
    return 0;
}