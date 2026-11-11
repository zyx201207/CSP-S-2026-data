#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, w;

    bool operator<(const Edge &rhs) const {
        return this->w > rhs.w;
    }
};

const int maxn = 500 + 5, maxm = 5e5 + 5, inf = 0x3f3f3f3f;
int c, n, m, d, q;
int w[maxm];

void db (const vector<int> &v) {
    for (auto e: v) cout << e << ' ';
    cout << '\n';
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i ++) cin >> w[i];

    // if (c <= 8 || (12 <= c && c <= 15)) {
    if (c < 9 || c > 11) {
        vector<Edge> G[n+m+1];
        for (int i = 1, k; i <= n; i ++) {
            cin >> k;
            for (int j = 0, a, t; j < k; j ++) {
                cin >> a >> t;
                G[a].push_back({m+i, t});
                G[m+i].push_back({a, t});
            }
        }

        for (int r = 0, x, y; r < q; r ++) {
            cin >> x >> y;
            priority_queue<Edge> pq;
            bitset<maxm> vis;
            vector<int> dis(m+n+1, inf);
            pq.push({x, 0}); dis[x] = 0;
            while(!pq.empty()) {
                    // db(dis);
                    Edge t = pq.top(); pq.pop();
                    int u = t.v;
                    // cerr << t.v << ' ' << t.w << '\n';
                    if (vis[u]) continue;
                    vis[u] = 1;
                    for (Edge e: G[u]) {
                        if (dis[e.v] > dis[u] + e.w) {
                            dis[e.v] = dis[u] + e.w;
                            pq.push({e.v, dis[e.v]});
                        }
                    }
            }
            cout << w[x] + w[y] + dis[y] << '\n';
        }

    } else {
    // if (9 <= c && c <= 11) {
        int G[m+n+1][m+n+1];
        memset(G, 0x3f, sizeof G);
        for (int i = 1, k; i <= n; i ++) {
            cin >> k;
            for (int j = 0, a, t; j < k; j ++) {
                cin >> a >> t;
                G[a][m+i] = t;
                G[m+i][a] = t;
            }
        }
        for (int k = 0; k < n+m+1; k ++)
            for (int i = 0; i < n+m+1; i ++)
                for (int j = 0; j < n+m+1; j ++)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        for (int r = 0, x, y; r < q; r ++) {
            cin >> x >> y;
            cout << w[x] + w[y] + G[x][y] << '\n';
        }
    }
    

    return 0;
}