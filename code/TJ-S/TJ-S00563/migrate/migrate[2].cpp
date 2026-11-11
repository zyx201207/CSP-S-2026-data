#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll c, t, n, d, ans, x[2000010];
void solve() {
	ans = 0;
	map < pair < ll, ll >, ll > mp, vis;
	cin >> n >> d;
	for (ll i = 1; i <= n; i++) cin >> x[i];
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			if (i == j) mp[{i, j}] = -1;
			else if (x[j] - x[i] <= d) mp[{i, j}] = mp[{j, i}] = 1;
		}
	}
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			if (i == k) continue;
			for (ll j = i + 1; j <= n; j++) {
				if (j == k) continue;
				if ((mp[{i, k}] + mp[{k, j}] && !mp[{i, j}] && mp[{i, k}] && mp[{k, j}]) ||
				(mp[{i, k}] + mp[{k, j}] < mp[{i, j}] && mp[{i, j}] > 0 && mp[{i, k}] > 0 && mp[{k, j}] > 0)) {
					mp[{i, j}] = mp[{j, i}] = mp[{i, k}] + mp[{k, j}];
//					cout << i << ' ' << j << ' ' << k << '<' << '\n';
				}
			}
		}
	}
	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			if (i == k) continue;
			for (ll j = i + 1; j <= n; j++) {
				if (j == k) continue;
				if (mp[{i, k}] + mp[{k, j}] == mp[{i, j}] && mp[{i, j}] > 0 && mp[{i, k}] > 0 && mp[{k, j}] > 0) {
//					cout << i << ' ' << j << ' ' << k << '=' << '\n';
					vis[{i, j}]++;
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			if (vis[{i, j}] == 2) ans++;
		}
	}
//	for (ll i = 1; i <= n; i++) {
//		for (ll j = 1; j <= n; j++) cout << mp[{i, j}] << ' ';
//		cout << '\n';
//	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}

