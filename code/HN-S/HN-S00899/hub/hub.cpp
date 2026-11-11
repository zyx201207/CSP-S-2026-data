#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e6 + 10;

int tp, T, n, k, last[N], maxd, vex;
int res, len, stk[N], top;
bool f[N];
vector<pii> g[N];
pii e[N];

void dfs(int u, int fa, int id, int dep) {
    if (dep > maxd) maxd = dep, vex = u;
    last[u] = fa;
    for (pii _ : g[u]) {
        int v = _.first, vid = _.second;
        if (v != fa && vid != id) dfs(v, u, id, dep + 1);
    }
}

void DFS(int u, int fa, int id) {
    stk[++top] = u;
    for (pii _ : g[u]) {
        int v = _.first, vid = _.second;
        if (v != fa && vid != id) DFS(v, u, id), f[u] |= f[v];
    }
    if (top > len) f[stk[top - len]] = 1;
    res += f[u], top--;
}

int Solve(int rt, int id) {
    maxd = vex = 0, dfs(rt, 0, id, 1);
    maxd = 0, rt = vex, dfs(vex, 0, id, 1);
    for (int j = 1; j < maxd / 2; j++, vex = last[vex]);
    res = 0, DFS(vex, 0, id);
    for (int i = 1; i <= n; i++) f[i] = 0;
    return res;
}

bool Check(int x) {
    int ret = n; len = x;
    for (int i = 1; i < n; i++) {
        ret = min(ret, Solve(e[i].first, i) + Solve(e[i].second, i));
    }
    return ret <= k;
}

void Solve() {
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v, e[i] = {u, v};
        g[u].push_back({v, i}), g[v].push_back({u, i});
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        Check(mid) ? r = mid : l = mid + 1;
    }
    cout << l << '\n';
    for (int i = 1; i <= n; i++) g[i].clear();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> tp >> T;
    while (T--) Solve();
    return 0;
}
