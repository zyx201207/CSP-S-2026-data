#include <bits/stdc++.h>
using namespace std;

int n, k;

const int N = 15;

vector<int> G[N];

int a[N], num;
bool vis[N];
int dis[N];
int ans;

void dfs1(int x) {
    vis[x] = true;
    for (auto v : G[x]) {
        if (vis[v]) continue;
        if (!a[v]) continue;
        dfs1(v);
    }
}
void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dis[i] = 1e9;
        if (a[i]) {
            q.push(i);
            dis[i] = 0;
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto v : G[x]) {
            if (dis[x] + 1 < dis[v]) {
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
}
void dfs(int pos) {
    if (num + (n - pos + 1) < k) return;
    if (num > k) return;
    if (pos > n) {
        for (int i = 1; i <= n; i++) vis[i] = false;
        int ltknum = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) continue;
            if (vis[i]) continue;
            dfs1(i);
            ltknum++;
        }
        if (ltknum > 2) return;
        bfs();
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, dis[i]);
        }
        ans = min(ans, res);
        return;
    }
    a[pos] = 0;
    dfs(pos + 1);
    a[pos] = 1;
    num++;
    dfs(pos + 1);
    num--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans = 1e9;
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}
// 5pts.
// sum : 100 + [32, 44] + 40 + 5 = [177, 189]
// Don't Guafen!!