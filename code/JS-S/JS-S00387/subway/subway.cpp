#include <bits/stdc++.h>
#define ONLINE(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

class Linked_Forward_Star {
    struct Edge {
        int nxt, to, w;
    };

public:
    vector<Edge> edge;
    vector<int> head;

    Linked_Forward_Star(int n) {
        edge.emplace_back();
        head.resize(n + 1);
    }

    inline void add(int u, int v, int w) {
        edge.push_back({head[u], v, w});
        head[u] = edge.size() - 1;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ONLINE(subway);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;

    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];

    Linked_Forward_Star g(m);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vector<int> p(x + 1), t(x + 1);
        for (int j = 1; j <= x; j++) cin >> p[j] >> t[j];

        for (int j = 1; j <= x; j++) {
            for (int k = j + 1; k <= x; k++) {
                g.add(p[j], p[k], t[j] + t[k]);
                g.add(p[k], p[j], t[j] + t[k]);
            }
        }
    }

    vector<vector<int> > dist(m + 1, vector<int>(m + 1, INF));

    auto dij = [&](int st) -> void {
        struct node {
            int u, dis;

            bool operator < (const node &x) const {
                return dis > x.dis;
            }
        };

        priority_queue<node> pq;
        dist[st][st] = 0;
        pq.push({st, 0});

        while (!pq.empty()) {
            int u = pq.top().u, dis = pq.top().dis;
            pq.pop();
            if (dis > dist[st][u]) continue;
            for (int i = g.head[u]; i; i = g.edge[i].nxt) {
                int v = g.edge[i].to, w = g.edge[i].w;
                if (dist[st][v] > dis + w) {
                    dist[st][v] = dis + w;
                    pq.push({v, dist[st][v]});
                }
            }
        }
    };

    while (q--) {
        int x, y;
        cin >> x >> y;

        if (dist[x][x] != 0) swap(x, y);
        if (dist[x][x] != 0) dij(x);

        cout << dist[x][y] + a[x] + a[y] << "\n";
    }

    return 0;
}
