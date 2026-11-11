// 图论建模 最短路 绿～青
#include <bits/stdc++.h>
using namespace std;

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

#define int long long
const int N = 505, M = 5e5+5, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, d, q, w[M], k[N];
vector<int> a[N], t[N];
struct Edge {
    int v, w;
};
vector<Edge> h[M];   // 每个点可以坐哪些地铁
int e[N][N];    // 地铁图

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> n >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            h[x].push_back({i, y});
        }
    }

    memset(e, 0x3f, sizeof e);
    for (int i = 1; i <= n; i++) {
        e[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < k[i]; x++) {
            for (auto &j : h[a[i][x]]) {
                e[i][j.v] = min(e[i][j.v], t[i][x] + j.w);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (e[i][j] > e[i][k] + e[k][j]) {
                    e[i][j] = e[i][k] + e[k][j];
                }
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        int mn = inf;
        for (auto &i : h[u]) {
            for (auto &j : h[v]) {
                mn = min(mn, i.w + e[i.v][j.v] + j.w);
            }
        }
        cout << mn + w[u] + w[v] << '\n';
    }

    return 0;
}