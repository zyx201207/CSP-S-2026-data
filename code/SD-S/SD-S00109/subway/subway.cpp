/*
Cute Chtholly.
*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rep(i, l, r) for(ll i = (l); i <= (r); i++)
#define per(i, r, l) for(ll i = (r); i >= (l); i--)
#define fo(i, n) rep(i, 1, n)
using ll = long long;
using pll = pair<ll, ll>;

const ll N = 505, M = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
ll tid, n, m, d, T, w[M], k, x, y, dis[N][N];
vector<pll> e[M];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tid >> n >> m >> d >> T;
    fo(i, m) {
        cin >> w[i];
    }
    fo(i, n) {
        fo(j, n) {
            if(i != j) dis[i][j] = INF;
        }
    }
    fo(i, n) {
        cin >> k;
        fo(j, k) {
            cin >> x >> y;
            e[x].pb({i, y});
        }
    }
    fo(i, m) {
        ll t = e[i].size();
        rep(xx, 0, t - 1) {
            rep(yy, xx + 1, t - 1) {
                ll u = e[i][xx].fi, v = e[i][yy].fi;
                if(e[i][xx].se + e[i][yy].se < dis[u][v]) {
                    dis[u][v] = dis[v][u] = e[i][xx].se + e[i][yy].se;
                }
            }
        }
    }
    fo(c, n) {
        fo(u, n) {
            fo(v, n) {
                if(dis[u][c] + dis[c][v] < dis[u][v]) {
                    dis[u][v] = dis[u][c] + dis[c][v];
                }
            }
        }
    }
    fo(_, T) {
        cin >> x >> y;
        ll ans = INF;
        for(pll u : e[x]) {
            for(pll v : e[y]) {
                ans = min(ans, dis[u.fi][v.fi] + u.se + v.se);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}

