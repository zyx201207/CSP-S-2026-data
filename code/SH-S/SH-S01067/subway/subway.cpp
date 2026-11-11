#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c, n, m, d, q, w[500009], A[509][509];
vector<pair<ll,ll>> x[500009];

/**
 * 容我用爱修饰故作矜持的原罪 沉溺在诗篇中辗转迂回
 */

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> n >> m >> d >> q;
    for(ll i = 1; i <= m; i++) cin >> w[i];
    for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) A[i][j] = INF;
    for(ll i = 1; i <= n; i++) A[i][i] = 0;
    for(ll i = 1, k, a, t; i <= n; i++) {
        cin >> k;
        while(k--) {
            cin >> a >> t;
            x[a].emplace_back(i, t);
        }
    }
    pair<ll,ll> p1, p2;
    for(ll i = 1; i <= m; i++) {
        for(ll j = 0; j < x[i].size(); j++) for(ll k = 0; k < j; k++) {
            p1 = x[i][j], p2 = x[i][k];
            A[p1.first][p2.first] = A[p2.first][p1.first] = min(A[p1.first][p2.first], p1.second+p2.second);
        }
    }
    for(ll k = 1; k <= n; k++) for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
    ll u, v;
    while(q--) {
        cin >> u >> v;
        ll ans = INF;
        for(pair<ll,ll> p1:x[u]) for(pair<ll,ll> p2:x[v]) ans = min(ans, w[u]+w[v]+p1.second+p2.second+A[p1.first][p2.first]);
        cout << ans << '\n';
    }
    return 0;
}