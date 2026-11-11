#include <bits/stdc++.h>

using namespace std;

int c, n, k, ans;
set<int> sel;
vector<int> f;
vector<vector<int>> g;

int find(int x) {
    return f[x] == x ? x : (f[x] = find(f[x]));
}

void unite(int x, int y) {
    f[find(x)] = find(y);
}

void calc() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }

    for (int u : sel) {
        for (int v : g[u]) {
            if (sel.count(v) && find(u) != find(v)) {
                unite(u, v);
            }
        }
    }

    vector<int> flag;
    for (int i : sel) {
        if (f[i] == i) {
            flag.push_back(i);
        }
    }

    if (flag.size() > 2) {
        return;
    }

    queue<int> que;
    vector<int> dis(n + 1, INT_MAX);
    for (int i : flag) {
        que.push(i);
        dis[i] = 0;
    }

    while (que.size()) {
        int u = que.front();
        que.pop();

        for (int v : g[u]) {
            bool fl = sel.count(v) && sel.count(u);
            if (dis[u] + !fl < dis[v]) {
                que.push(v);
                dis[v] = dis[u] + !fl;
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dis[i]);
    }

    ans = min(ans, mx);
}

void dfs(int d) {
    if (d > k) {
        calc();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!sel.count(i)) {
            sel.insert(i);
            dfs(d + 1);
            sel.erase(i);
        }
    }
}

inline void solve() {
    cin >> n >> k;

    g.assign(n + 1, {});
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    if (n - k <= 1) {
        cout << (n - k) << "\n";
        return;
    }

    ans = INT_MAX;
    f.assign(n + 1, 0);
    dfs(1);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int t;
    cin >> c >> t;

    while (t--) {
        solve();
    }

    return 0;
}
