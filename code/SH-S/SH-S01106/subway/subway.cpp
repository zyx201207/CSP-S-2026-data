#include<bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef long long ll;
const ll N = 509, M = 500009, D = 29, INF = 1e18;
vector<pair<ll, ll> > trk[M];
ll d[N][N], a[M], c, n, m, q;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> c >> q;
	for (ll i = 1; i <= m; i++) cin >> a[i];
	for (ll i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll u, t;
			cin >> u >> t;
			trk[u].push_back(mp(i, t));
		}
	}
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++) d[i][j] = (i == j ? 0LL : INF);
	for (ll i = 1; i <= m; i++)
		for (ll j = 0; j < trk[i].size(); j++)
			for (ll k = j + 1; k < trk[i].size(); k++) {
				ll u = trk[i][j].f, v = trk[i][k].f, w = trk[i][j].s + trk[i][k].s;
				d[u][v] = d[v][u] = min(d[u][v], w);
//				cout << u << ' ' << v << ' ' << w << endl;
			}
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			for (ll k = 1; k <= n; k++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (ll i = 1; i <= q; i++) {
		ll x, y;
		cin >> x >> y;
		ll ans = INF;
		for (pair<ll, ll> pu : trk[x])
			for (pair<ll, ll> pv : trk[y])
				ans = min(ans, d[pu.f][pv.f] + a[x] + a[y] + pu.s + pv.s);
		cout << ans << endl;
	}
	return 0;
}
/*
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
*/
