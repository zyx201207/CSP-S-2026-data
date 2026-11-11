#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll inf = 123456789123456;

ll w[500005];
vector <int> a[505];
vector <int> b[500005];
ll dis[505][505];
ll t[505][500005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int kkk; cin >> kkk;
        for (int j = 1; j <= kkk; j++) {
            int xx, yy; cin >> xx >> yy;
            a[i].push_back(xx);
            b[xx].push_back(i);
            t[i][xx] = yy;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            if (i == j) {dis[i][j] = 0; continue;}
            dis[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j : a[i]) {
            for (int k : b[j]) {
                if (i == k) continue;
                dis[i][k] = min(dis[i][k], t[i][j] + t[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n ; j++) {
            for (int k = 1; k <= n; k++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--) {
        int x, y; cin >> x >> y;
        ll ans = inf;
        for (int i : b[x]) {
            for (int j : b[y]) {
                ans = min(ans, dis[min(i, j)][max(i, j)] + w[x] + w[y] + t[i][x] + t[j][y]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
