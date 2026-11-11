#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll c, n, m, d, q;
ll w[500009], to[509][509];
ll a[500009][22], t[500009][22], cnt[500009];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	memset(to, 0x1f, sizeof(to));
	for (int i = 1; i <= n; i++) {
		to[i][i] = 0;
		ll ki; cin >> ki;
		while (ki--) {
			ll aa;
			cin >> aa;
			a[aa][++cnt[aa]] = i;
			cin >> t[aa][cnt[aa]];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cnt[i]; j++) {
			for (int k = 1; k <= cnt[i]; k++) {
				if (j != k)
					to[a[i][j]][a[i][k]] = min(to[a[i][j]][a[i][k]], t[i][j] + t[i][k]);
			}
		}
	} // O(md^2), max 2 * 10^8
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				to[i][j] = min(to[i][j], to[i][k] + to[k][j]);
		}
	} // O(n^3), max 1.25 * 10^8 [floyd]
	while (q--) {
		ll x, y;
		cin >> x >> y; // x != y
		ll ans = 0x1f1f1f1f1f1f1f1f;
		for (int j = 1; j <= cnt[x]; j++)
			for (int k = 1; k <= cnt[y]; k++) {
				ll cnt = to[a[x][j]][a[y][k]] + t[x][j] + w[x] + t[y][k] + w[y];
				ans = min(ans, cnt);
			}
		cout << ans << endl;
	} // O(qd^2), max 0.4 * 10^8
	return 0;
}