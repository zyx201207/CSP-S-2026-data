#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

void tomax(int& x, int y) {
    x = max(x, y);
}
void tomin(int& x, int y) {
    x = min(x, y);
}

constexpr int MAXN = 505;
constexpr int MAXM = 5e5 + 5;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[MAXM];
vpii plat[MAXM];
int G[MAXN][MAXN];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> n >> m >> d >> q;
    rep (i, 1, m) cin >> w[i];
    rep (i, 1, n) {
        int k;
        cin >> k;
        while (k--) {
            int a, t;
            cin >> a >> t;
            plat[a].pb(i, t);
        }
    }

    rep (i, 1, n) rep (j, 1, n) {
        if (i != j) G[i][j] = INF;
    }
    rep (i, 1, m) {
        int t = plat[i].size();
        rep (j, 0, t - 1) rep (k, 0, t - 1) {
            tomin(G[plat[i][j].fi][plat[i][k].fi], plat[i][j].se + plat[i][k].se);
        }
    }
    rep (k, 1, n) rep (i, 1, n) rep (j, 1, n) tomin(G[i][j], G[i][k] + G[k][j]);
    rep (i, 1, q) {
        int x, y;
        cin >> x >> y;
        int t1 = plat[x].size(), t2 = plat[y].size();
        int ans = INF;
        rep (j, 0, t1 - 1) rep (k, 0, t2 - 1) tomin(ans, G[plat[x][j].fi][plat[y][k].fi] + plat[x][j].se + plat[y][k].se);
        cout << ans + w[x] + w[y] << endl;
    }

    return 0;
}