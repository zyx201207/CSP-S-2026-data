#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 505, M = 5e5 + 5, INF = 1e18;

ll f[N][N];

ll n, m, c, d, q;

ll w[M];

struct S {
    ll x, w;
};

vector<S> nbr[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; i++) {
        cin >> w[i];    
    }
    for (ll i = 1; i <= n; i++) {
        ll len;
        cin >> len;
        for (ll j = 1, x, w; j <= len; j++) {
            cin >> x >> w;
            nbr[x].push_back({i, w});
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            f[i][j] = INF;
        }
    }
    for (ll i = 1; i <= n; i++) {
        f[i][i] = 0;
    }
    for (ll i = 1; i <= m; i++) {
        for (ll x, w, j = 0; j < nbr[i].size(); j++) {
            x = nbr[i][j].x, w = nbr[i][j].w;
            for (ll y, o, e = 0; e < j; e++) {
                y = nbr[i][e].x, o = nbr[i][e].w;
                f[x][y] = f[y][x] = min(f[x][y], w + o);
            }
        }
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (ll x, y; q--;) {
        cin >> x >> y;
        ll ans = w[x] + w[y], ooo = INF;
        ll sum = INF;
        for (ll u, dss, i = 0; i < nbr[x].size(); i++) {
            u = nbr[x][i].x, dss = nbr[x][i].w;
            for (ll j = 0, v, dw; j < nbr[y].size(); j++) {
                v = nbr[y][j].x, dw = nbr[y][j].w;
                sum = dss + dw + f[u][v];
                ooo = min(ooo, sum);
            }
        }
        ans += ooo;
        cout << ans << "\n";
    }
    return 0;
}