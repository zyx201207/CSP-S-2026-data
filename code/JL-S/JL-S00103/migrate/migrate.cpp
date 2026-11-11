#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
queue<int> q;
vector<vector<int> > g(N, vector<int>());
int n, d, a[N], x[N], ans = 0, dis[N], sum[N];

inline void bfs(int start) {
    memset(dis, 0x3f, sizeof dis); memset(sum, 0, sizeof sum); 
    q.push(start); dis[start] = 0, sum[start] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dis[v] > dis[u] + 1)
                q.push(v), dis[v] = dis[u] + 1, sum[v] = sum[u];
            else if (dis[v] == dis[u] + 1)
                sum[v]++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (sum[i] == 2)
            ans++;
}

inline void solve() {
    while (!q.empty()) q.pop(); g.assign(N, vector<int>()); ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (x[j] - x[i] <= d)
                g[i].push_back(j);
            else
                break;
    for (int i = 1; i <= n; i++)
        bfs(i);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T; cin >> c >> T; while (T--) solve();
    return 0;
}