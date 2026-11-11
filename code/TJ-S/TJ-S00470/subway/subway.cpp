#include <bits/stdc++.h>
// I Can Fly !!!!!!!!
using namespace std;

typedef long long ll;
typedef long double ld;

ll cas;
ll n, m, d, q;
ll w[500010];
ll k[510];
vector<ll> a[510], t[510];
vector<pair<ll,ll>> e[500010];

ll dist[510][510];
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> cas >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        scanf("%Ld", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%Ld", &k[i]);
        a[i].resize(k[i] + 2);
        t[i].resize(k[i] + 2);
        for (int j = 1; j <= k[i]; j++) {
            scanf("%Ld%Ld", &a[i][j], &t[i][j]);
            e[a[i][j]].push_back({i, t[i][j]});
        }
    }
    // build
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dist[i][j] = dist[j][i] = 1e18;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (auto [j, wj] : e[i]) {
            for (auto [k, wk] : e[i]) {
                if (j != k) {
                    dist[j][k] = min(dist[j][k], wj+wk);
                    dist[k][j] = dist[j][k];
                }
            }
        }
    }
    floyd();
    // query
    while (q--) {
        ll x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (auto[i, wi] : e[x]) {
            for (auto[j, wj] : e[y]) {
                ans = min(ans, wi + wj + dist[i][j] + w[x] + w[y]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
