#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 2e5 + 10;
const int inf = 1e7;
int c, t, n, k, dis[N];
vector<int> e[N];
bool vis[N];
int solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = inf;
    for (int mask = 1; mask < 1 << n; mask++) if (__builtin_popcount(mask) == k) {
        queue<int> q;
        int cnt = 0, cc = 0;
        for (int i = 0; i < n; i++) vis[i] = false;
        for (int i = 0; i < n; i++) if ((mask >> i & 1) && !vis[i]) {
            ++cc;
            q.push(i);
            vis[i] = true;
            while (q.size()) {
                int u = q.front(); q.pop();
                for (int v : e[u]) if ((mask >> v & 1) && !vis[v]) vis[v] = true, q.push(v);
            }
        }
        if (cc > 2) continue;
        queue<int> que;
        for (int i = 0; i < n; i++) dis[i] = inf;
        for (int i = 0; i < n; i++) if (mask >> i & 1) que.push(i), dis[i] = 0;
        int mx = 0;
        while (que.size()) {
            int u = que.front(); que.pop();
            mx = dis[u];
            for (int v : e[u]) if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
        ans = min(ans, mx);
    }
    return ans;
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}
