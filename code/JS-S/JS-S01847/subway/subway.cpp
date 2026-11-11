// 神秘，17:40 才开窍想出来解法（怒
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M];
vector<pair<int, long long>> edges[M + N];
long long dis[N][N];

int main()
{
    ifstream fin("subway.in");
    ofstream fout("subway.out");
    fin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dis[i][j] = LLONG_MAX >> 1;
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) fin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        fin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            fin >> a >> t;
            edges[n + a].push_back({i, t});
            edges[i].push_back({n + a, t});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto e : edges[i]) {
            for (auto f : edges[e.first]) {
                dis[f.first][i] = dis[i][f.first] = min(dis[i][f.first], e.second + f.second);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        fin >> x >> y;
        long long ans = LLONG_MAX;
        for (auto e : edges[x + n]) {
            int u = e.first;
            for (auto f : edges[y + n]) {
                int v = f.first;
                ans = min(ans, w[x] + w[y] + e.second + f.second + dis[u][v]);
            }
        }

        fout << ans << '\n';
    }

    return 0;
}

