#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 505, M = 5e5 + 5;

vector<pii> e[M];
int c, n, m, d, q, w[M];
int dis[N][N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a, t;
            cin >> a >> t;
            e[a].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (pii x : e[i])
            for (pii y : e[i])
                if (x != y)
                    dis[x.first][y.first] = dis[y.first][x.first] = min(dis[x.first][y.first], x.second + y.second);
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= q; i++) {
        int x, y, res = LONG_LONG_MAX;
        cin >> x >> y;
        for (pii xx : e[x])
            for (pii yy : e[y])
                res = min(res, xx.second + yy.second + dis[xx.first][yy.first]);
        cout << w[x] + w[y] + res << '\n';
    }
    return 0;
}