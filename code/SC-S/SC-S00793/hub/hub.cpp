#include <bits/stdc++.h>
using namespace std;

ifstream inf("hub.in");
ofstream ouf("hub.out");

#define vec vector

const int inf32 = 0x3f3f3f3f;

void solve() {
    int n, k;
    inf >> n >> k;
    vec<vec<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        inf >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto getDir = [&]() -> vec<int> {
        vec<pair<int, int>> dis(n + 1);
        vec<int> fa(n + 1);
        auto DFS = [&](auto &self, int u, int fs) -> void {
            dis[u] = {0, u}, fa[u] = fs;
            for (int v : adj[u]) if (v != fs) {
                self(self, v, u);
                dis[u] = max(dis[u], make_pair(dis[v].first + 1, dis[v].second));
            }
        };
        DFS(DFS, 1, 0);
        int u = dis[1].second;
        DFS(DFS, u, 0);
        int v = dis[u].second;
        vec<int> path;
        while (v) path.emplace_back(v), v = fa[v];
        return move(path);
    };
    vec<int> path = getDir();
    int w = path.size();

    vec<int> mx(n + 1), cnt(n + 1);
    vec<int> sum(w);
    vec<int> pre(w), suf(w);
    vec<int> lef(w), rig(w);
    vec<vec<int>> bak(n + 1);

    auto DFS = [&](auto &self, int u, int fs, int rt) -> void {
        mx[u] = 0;
        for (int v : adj[u]) if (v != fs) {
            self(self, v, u, rt);
            mx[u] = max(mx[u], mx[v] + 1);
        }
        bak[rt].emplace_back(u);
    };
    for (int i = 0; i < w; ++i) {
        int u = path[i];
        for (int v : adj[u]) {
            if (i && v == path[i - 1]) continue;
            if (i + 1 < w && v == path[i + 1]) continue;
            DFS(DFS, v, u, u);
            mx[u] = max(mx[u], mx[v] + 1);
        }
    }

    auto check = [&](int d) -> bool {
        for (int i = 0; i < w; ++i) {
            int u = path[i];
            cnt[u] = 0;
            for (int x : bak[u])
                cnt[u] += mx[x] >= d;
        }
        int lw = w - 1;
        for (int i = 0, tmp = -inf32; i < w; ++i) {
            tmp = max(tmp, mx[path[i]] - i);
            if (tmp + i >= d) {
                lw = i;
                break;
            }
        }
        int up = 0;
        for (int i = w - 1, tmp = -inf32; ~i; --i) {
            tmp = max(tmp, mx[path[i]] + i);
            if (tmp - i >= d) {
                up = i;
                break;
            }
        }
        for (int i = 0; i < w; ++i) {
            sum[i] = cnt[path[i]];
            if (i) sum[i] += sum[i - 1];
        }
        for (int i = 0; i < w; ++i) {
            int l = min(lw, i);
            pre[i] = (sum[i] - (l ? sum[l - 1] : 0)) + (i - l + 1);
            int r = max(up, i);
            suf[i] = (sum[r] - (i ? sum[i - 1] : 0)) + (r - i + 1);
        }
        for (int i = 0, p = 0; i < w; ++i) {
            while (p < i && i - p + mx[path[i]] > d) ++p;
            lef[i] = pre[p];
        }
        for (int i = w - 1, p = w - 1; ~i; --i) {
            while (p > i && p - i + mx[path[i]] > d) --p;
            rig[i] = suf[p];
        }
        int mn = inf32;
        for (int i = 0; i + 1 < w; ++i)
            mn = min(mn, lef[i] + rig[i + 1]);
        return mn <= k;
    };

    int ng = 0, ok = n - 1;
    while (ng < ok) {
        int mid = (ng + ok) >> 1;
        if (check(mid)) ok = mid;
        else ng = mid + 1;
    }
    ouf << ok << "\n";
}

int main() {
    ios::sync_with_stdio(false), inf.tie(nullptr);

    int c, t;
    inf >> c >> t;
    for (int cas = 1; cas <= t; ++cas) {
        solve();
    }

    ouf.flush();
    return 0;
}