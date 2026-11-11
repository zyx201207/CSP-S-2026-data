#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 0x3f3f3f3f3f3f3f3f;
int cas, n, m, d, q, w[500005], dis[505][505];
vector<pair<int, int>> G[500005];
inline void Min(int &x, int y) {
    if (y < x) x = y;
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> cas >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) cin >> w[i];
    for (int i=1;i<=n;i++) {
        int k;
        cin >> k;
        for (int j=0;j<k;j++) {
            int v, w;
            cin >> v >> w;
            G[v].push_back({i, w});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i=1;i<=n;i++) dis[i][i] = 0;
    for (int i=1;i<=m;i++) {
        for (auto &p1 : G[i])
            for (auto &p2 : G[i]) Min(dis[p1.first][p2.first], p1.second+p2.second);
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            if (dis[i][k] != oo)
                for (int j=1;j<=n;j++) Min(dis[i][j], dis[i][k]+dis[k][j]);
    // for (int i=1;i<=n;i++)
    //     for (int j=1;j<=n;j++) cerr << i << " " << j << " : " << dis[i][j] << "\n";
    while (q--) {
        int x, y;
        cin >> x >> y;
        // cerr << "===\n";
        int mi = oo;
        for (auto &p1 : G[x])
            for (auto &p2 : G[y]) mi = min(mi, p1.second+p2.second+dis[p1.first][p2.first])/* , cerr << p1.second << " " << p1.first << " " << p2.first << " " << p2.second << "\n" */;
        mi += w[x]+w[y];
        cout << mi << "\n";
    }
    return 0;
}
//freopen choke