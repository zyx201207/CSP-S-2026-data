#include <bits/stdc++.h>
using namespace std;
#define ll long long

void chkmin(ll &x, ll y) {
    if (y < x)x = y;
    return;
}

ll w[500005];

vector <pair <int, int> > id[500005];
ll e[505][505];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        int k;scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int x, t;scanf("%d%d", &x, &t);
            id[x].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)e[i][j] = 0;
            else e[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= m; i++) {
        int len = (int)id[i].size();
        for (int j = 0; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                chkmin(e[id[i][j].first][id[i][k].first], id[i][j].second + id[i][k].second);
                chkmin(e[id[i][k].first][id[i][j].first], id[i][j].second + id[i][k].second);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << e[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
//                chkmin(e[i][j], e[i][k] + e[k][j]);
                chkmin(e[j][k], e[j][i] + e[i][k]);
                //if (e[i][j] < 0)cout << e[i][k] << "#" << e[k][j] << endl;
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;scanf("%d%d", &x, &y);
        ll ans = 1e18;
        for (auto j : id[x]) {
            for (auto k : id[y]) {
                ans = min(ans, w[x] + w[y] + j.second + k.second + e[j.first][k.first]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}