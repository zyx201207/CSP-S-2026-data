#include <bits/stdc++.h>
#define ONLINE(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

class Linked_Forward_Star {
    struct Edge {
        int nxt, to;
    };

public:
    vector<Edge> edge;
    vector<int> head;

    Linked_Forward_Star(int n) {
        edge.emplace_back();
        head.resize(n + 1);
    }

    inline void add(int u, int v) {
        edge.push_back({head[u], v});
        head[u] = edge.size() - 1;
    }
};

class DSU {
public:
    vector<int> fa, siz;

    explicit DSU(int n) {
        fa.resize(n + 1), siz.resize(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int u) {
        return u == fa[u] ? u : fa[u] = find(fa[u]);
    }

    inline void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        siz[v] += siz[u];
        fa[u] = v;
    }
};

inline void solve() {
    int n, m;
    cin >> n >> m;
    Linked_Forward_Star g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g.add(u, v), g.add(v, u);
    }

    vector<vector<int> > dist(n + 1, vector<int>(n + 1, -1));
    for (int st = 1; st <= n; st++) {
        queue<int> q;
        q.push(st);
        dist[st][st] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = g.head[u]; i; i = g.edge[i].nxt) {
                int v = g.edge[i].to;
                if (dist[st][v] == -1) {
                    dist[st][v] = dist[st][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    auto judge = [&](int mask) -> bool {
        DSU dsu(n);
        for (int u = 1; u <= n; u++) {
            if (mask & (1 << (u - 1))) {
                for (int i = g.head[u]; i; i = g.edge[i].nxt) {
                    int v = g.edge[i].to;
                    if (mask & (1 << (v - 1)))
                        dsu.merge(u, v);
                }
            }
        }
        int S = 0;
        for (int u = 1; u <= n; u++) {
            if (mask & (1 << (u - 1))) {
                if (dsu.find(u) == u) S++;
            }
        }
        return S <= 2;
    };

    int ans = INF;

    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != m) continue;
        if (!judge(mask)) continue;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int mn = INF;
            for (int j = 1; j <= n; j++)
                if (mask & (1 << (j - 1)))
                    mn = min(mn, dist[i][j]);
            mx = max(mx, mn);
        }
        ans = min(ans, mx);
    }

    cout << ans << "\n";
}

namespace sub13_14 {
    inline void solve() {
        int n, m;
        cin >> n >> m;

        int mid = (n - 1) / 2;
        int pos = mid + 1;
        int linked = -1;

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;

            if (u == pos) linked = v;
            if (v == pos) linked = u;
        }

        if (m == mid) {
            if (linked <= mid) cout << 1 << "\n";
            else cout << 2 << "\n";
        } else if (m >= mid + 1 && m < n) {
            cout << 1 << "\n";
        } else if (m == n) {
            cout << 0 << "\n";
        } else if (m < mid) {
            if (m % 2 == 1 && mid % 2 == 0) m--;
            int ans = (mid - m) / 2 + 1;
            if (linked == 1 + mid + 1 || linked == mid + mid + 1) {
                cout << ans + 1 << "\n";
            } else cout << ans << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ONLINE(hub);
    int c, t;
    cin >> c >> t;
    while (t--) {
        if (c == 13 || c == 14) sub13_14::solve();
        else solve();
    }
    return 0;
}
