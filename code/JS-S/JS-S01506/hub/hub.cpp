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

void solve() {
    int n, k; fin >> n >> k;

    vector<vector<int> > g(n + 1);

    for (int i = 1; i < n; i ++ ) {
        int u, v; fin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> cur;
    vector<vector<int> > opt;

    function<void(int, int)> choose = [&](int u, int num) -> void {
        if (num > k) return ;
        if (u == n + 1 or num == k) {
            if (num != k) return;
            vector<int> fa(n + 1);
            for (int i = 1; i <= n; i ++ )
                fa[i] = i;

            function<int(int)> find = [&](int x) {
                if (fa[x] == x) return x;
                return fa[x] = find(fa[x]);
            };

            vector<bool> st(n + 1);
            for (int i : cur)
                st[i] = true;

            for (auto i : cur) {
                for (auto v : g[i])
                    if (st[v])
                        fa[find(v)] = find(i);
            }

            int cnt = 0;
            for (int i = 1; i <= n; i ++ )
                if (st[i] and find(i) == i)
                    cnt ++ ;

            if (cnt <= 2) opt.push_back(cur);

            return ;
        }

        choose(u + 1, num);
        cur.push_back(u);
        choose(u + 1, num + 1);
        cur.pop_back();
    };
    choose(1, 0);

    vector<vector<int> > dist(n + 1, vector<int>(n + 1, INF));

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

            for (auto ttt : g[u]) {
                int v = ttt, ww = 1;
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

    int res = INF;

    for (auto cur : opt) {
        vector<bool> st(n + 1);

        for (int i : cur)
            st[i] = true;

        vector<int> d(n + 1, INF);

        for (int i = 1; i <= n; i ++ ) {
            if (st[i]) {
                d[i] = 0;
                continue;
            }
            for (int j = 1; j <= n; j ++ )
                if (st[j]) {
                    d[i] = min(dist[i][j], d[i]);
                    // cout << i << " " << j << " " << dist[i][j] << " " << d[i] << endl;
                }
        }
        int tt = 0;

        for (int i = 1; i <= n; i ++ )
            tt = max(tt, d[i]);

        // for (int i = 1; i <= n; i ++ )
        //     cout << d[i] << " ";
        // cout << endl;

        res = min(res, tt);
    }

    cout << res << endl;
}

signed main() {
    IO("hub");

    int c, T; fin >> c >> T;

    while(T -- ) {
        solve();
    }
}