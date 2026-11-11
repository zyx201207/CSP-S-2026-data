#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using db = double;
using ull = unsigned long long;
using cll = const long long;
cll N = 5e5 + 5;
ll c, n, m, d, q;
ll w[N], k[505];
ll a[505][N], t[505][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i ++)  {
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i ++) {
		cin >> k[i];
		for (ll j = 1; j <= k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (ll i = 1; i <= q; i ++) {
		ll x, y;
		cin >> x >> y;
		ll cnt = w[x] + w[y];
		ll mi = 1e18;
		for (ll j = 1; j <= n; j ++) {
			ll xf, yf, xh, yh;
			for (ll o = 1; o <= k[j]; o ++) {
				if (a[j][o] == x) xf = j, xh = o;
				if (a[j][o] == y) yf = j, yh = o;
			}
			mi = min(mi, t[xf][xh] + t[yf][yh]);
		}
		cnt += mi;
		cout << cnt << '\n';
	}
	return 0;
}