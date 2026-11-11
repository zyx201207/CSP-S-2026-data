#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 505, MAXM = 5e5 + 5;
int c, n, m, d, q;
int w[MAXM], k[MAXN];
// int a[MAXN][MAXM], t[MAXN][MAXM];
struct Time {
    int id;
    ll t;
};
vector<Time> ti[MAXM];
ll dis[MAXN][MAXN];

void query() {
    int x, y;
    cin >> x >> y;
    ll ans = LLONG_MAX;
    for (int i = 0; i < ti[x].size(); i++) {
        for (int j = 0; j < ti[y].size(); j++) {
            int idx = ti[x][i].id, idy = ti[y][j].id;
            ll tx = ti[x][i].t, ty = ti[y][j].t;
//            cout << w[x] << ' ' << w[y] << ' ' << tx << ' ' << ty << ' ' << dis[idx][idy] << '\n';
            ans = min(ans, 1LL * w[x] + w[y] + tx + ty + dis[idx][idy]);
        }
    }
    cout << ans << '\n';
//    cout << '\n';
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            int a, t;
            cin >> a >> t;
            ti[a].push_back({i, t});
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < ti[i].size() - 1; j++) {
            for (int k = 0; k < ti[i].size(); k++) {
                int idx = ti[i][j].id, idy = ti[i][k].id;
                ll ndis = ti[i][j].t + ti[i][k].t;
                dis[idx][idy] = dis[idy][idx] = min(dis[idx][idy], ndis);
            }
        }
    }
    // floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << dis[i][j] << " ";
//        }
//        cout << '\n';
//    }
    while (q--) {
        query();
    }
    return 0;
}
