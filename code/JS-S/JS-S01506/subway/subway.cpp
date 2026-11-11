#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <queue>
#include <map>
#include <unordered_map>

namespace std {
    class Read {
        public:
        template<typename T>
        inline Read operator >> (T & x) {
            T sum = 0; signed opt = 1;
            char ch = getchar();
            while(!isdigit(ch)) opt = (ch == '-') ? -1 : 1, ch = getchar();
            while( isdigit(ch)) sum = (sum << 1) + (sum << 3) + (ch ^ 48), ch = getchar();
            x = sum * opt; return (*this);
        }
    };
}
#define int long long
#define all(a) a.begin(), a.end()
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
#define endl "\n"

using namespace std; Read fin;

using PII = pair<int, int>;

const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    IO("subway");
    
    int c, n, m, d, q; fin >> c >> n >> m >> d >> q;

    vector<int> w(m + 1);

    for (int i = 1; i <= m; i ++ )
        fin >> w[i];
    
    vector<vector<PII> > G(n + 1);
    vector<vector<int> > dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<PII> > x(m + 1);

    for (int i = 1; i <= n; i ++ ) {
        int k; fin >> k;
        for (int j = 1; j <= k; j ++ ) {
            int a, t; fin >> a >> t;
            x[a].push_back({i, t});
        }
    }
    vector<vector<int> > g(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= m; i ++ ) {
        for (auto j : x[i]) {
            for (auto k : x[i]) {
                if (j == k) continue;
                g[j.first][k.first] = min(g[j.first][k.first], j.second + k.second);
            }
        }
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (g[i][j] < INF / 2) {
                G[i].push_back({j, g[i][j]});
            }

    function<void(int)> Dijkstra = [&](int s) -> void {
        vector<bool> st(n + 1);

        priority_queue<PII, vector<PII>, greater<PII> > q;

        q.push({0, s}); dist[s][s] = 0;

        while(q.size()) {
            auto tt = q.top(); q.pop();
            int u = tt.second, dis = tt.first;

            if (st[u]) continue;
            st[u] = true;

            // cout << u << ":\n";

            for (auto ttt : G[u]) {
                int v = ttt.first, ww = ttt.second;
                // cout << s << " " << u << " " << v << endl;
                if (dist[s][v] > dist[s][u] + ww) {
                    dist[s][v] = dist[s][u] + ww;
                    q.push({dist[s][v], v});
                }
            }
        }
    };

    for (int i = 1; i <= n; i ++ ) {
        Dijkstra(i);
    }

    while(q -- ) {
        int s, t; fin >> s >> t;

        int res = INF;

        for (auto i : x[s])
            for (auto j : x[t]) {
                res = min(res, dist[i.first][j.first] + i.second + j.second);
            }
        cout << res + w[s] + w[t] << endl;
    }
}