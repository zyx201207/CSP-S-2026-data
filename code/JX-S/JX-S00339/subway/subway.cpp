#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define i128 __int128
#define fi first
#define se second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define INF 0x3f3f3f3f
#define INFx 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 510, M = 5e5 + 10;

int c, n, m, d, q;
ll w[M];
vector<PLL> hall[M];
ll dis[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin); // modify!!!
    freopen("subway.out", "w", stdout); // modify!!!
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; i++) cin >> w[i];

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {  
            ll a, t;
            cin >> a >> t;
            hall[a].push_back({i, t});
        }
    }

    memset(dis, 0x3f, sizeof dis);

    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < hall[i].size(); j++) {
            ll u = hall[i][j].fi, tu = hall[i][j].se;
            for (int k = j + 1; k < hall[i].size(); k++) {
                ll v = hall[i][k].fi, tv = hall[i][k].se;
                dis[u][v] = dis[v][u] = min(dis[u][v], tu + tv);
            }
        }
    }

    floyd();

    while (q--) {
        int x, y;
        cin >> x >> y;

        ll ans = INFx;
        for (int i = 0; i < hall[x].size(); i++) {
            ll u = hall[x][i].fi, tu = hall[x][i].se;
            for (int j = 0; j < hall[y].size(); j++) {
                ll v = hall[y][j].fi, tv = hall[y][j].se;
                ans = min(ans, w[x] + w[y] + tu + tv + dis[u][v]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
