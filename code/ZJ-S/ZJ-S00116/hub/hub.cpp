#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct F {
    vector<int> f;
    int n;
    F() {}
    F(int _n) {
        f.resize(_n + 10);
        for (int i = 1; i <= _n; i++)
            f[i] = i;
        n = _n;
    }
    int findset(int x) {
        if (x == f[x])
            return x;
        return f[x] = findset(f[x]);
    }
    void merges(int x, int y) {
        x = findset(x), y = findset(y);
        if (x == y)
            return;
        f[y] = x;
    }
};

int testid, ans, T, n, k, dist[1000010];
vector<int> edges[1000010];
bool b[1000010];

bool check() {
    F g(n);
    for (int i = 1; i <= n; i++)
        if (b[i])
            for (auto j : edges[i])
                if (b[j])
                    g.merges(i, j);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (b[i] && g.f[i] == i)
            cnt++;
    return cnt <= 2;
}

int calc() {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (b[i])
            dist[i] = 0, q.push(i);
    int ret = 0;
    for (; !q.empty(); ) {
        auto x = q.front();
        q.pop();
        for (auto p : edges[x])
            if (dist[p] == -1) {
                dist[p] = dist[x] + 1;
                ret = max(ret, dist[p]);
                q.push(p);
            }
    }
    return ret;
}

void dfs(int i, int cnt) {
    if (cnt == k) {
        if (check())
            ans = min(ans, calc());
        return;
    }
    if (i == n + 1)
        return;
    dfs(i + 1, cnt);
    b[i] = true;
    dfs(i + 1, cnt + 1);
    b[i] = false;
}

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    ans = 1 << 30;
    dfs(1, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        edges[i].clear();
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &testid, &T);
    for (; T--; )
        solve();
    return 0;
}
