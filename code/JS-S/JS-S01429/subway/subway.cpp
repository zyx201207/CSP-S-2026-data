#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;
using pii = pair<int, LL>;

const int N = 600;
const int M = 5e6 + 2000;

vector<pair<int, LL>> st[M];
LL w[M];
LL dis[N][N];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int id;
            LL d;
            cin >> id >> d;
            st[id].push_back(make_pair(i, d));
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dis[i][j] = LLONG_MAX;
        }
    }
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        for (auto j : st[i]) {
            for (auto k : st[i]) {
                int u = j.first;
                int v = k.first;
                LL du = j.second;
                LL dv = k.second;
                dis[u][v] = min(dis[u][v], du + dv);
                dis[v][u] = min(dis[v][u], du + dv);
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX &&  dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        LL ans = LLONG_MAX;
        for (auto i : st[s]) {
            for (auto j : st[e]) {
                int u = i.first, v = j.first;
                LL du = i.second, dv = j.second;
                ans = min(ans, w[s] + w[e] + dis[u][v] + du + dv);
            }
        }
        cout << ans << endl;
    }
    return 0;
}