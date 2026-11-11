#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M];
int dis[N][N];
vector <pair <int, int> > sub[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dis, 0x3f, sizeof(dis));
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1, k; i <= n; i++) {
        dis[i][i] = 0;
        cin >> k;
        for (int j = 1, a, t; j <= k; j++)
            cin >> a >> t, sub[a].push_back({i, t});
    }
    for (int i = 1; i <= m; i++) {
        int siz = sub[i].size();
        for (int j = 0; j < siz; j++)
            for (int k = j + 1; k < siz; k++) {
                int u = sub[i][j].first;
                int v = sub[i][k].first;
                int di = sub[i][j].second + sub[i][k].second;
                dis[u][v] = dis[v][u] = min(dis[u][v], di);
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--) {
        int from, to;
        cin >> from >> to;
        int res = 1e18;
        for (int i = 0; i < sub[from].size(); i++)
            for (int j = 0; j < sub[to].size(); j++)
                res = min(res, dis[sub[from][i].first][sub[to][j].first] + sub[from][i].second + sub[to][j].second);
        cout << res + w[from] + w[to] << endl;
    }
    return 0;
}