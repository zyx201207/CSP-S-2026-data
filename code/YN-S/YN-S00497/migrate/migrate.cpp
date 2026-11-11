#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll c, t, n, d, a[N];
vector<ll> b;
ll k;

dfs(ll u, ll v, ll l) {
	//cout << u << " " << v << "" << l << "\n";
	if (u == v) {
		b.push_back(l);
	}
	k = u + 1;
	while (a[k] <= d && k <= v) {
		dfs(k, v, l + 1);
		k++;
	}
}

int main() {
	// please, don't hack me(even though this program hasn't be completed yet)
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to change the file name!!!!!
	// be sure to delete any "//"
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ll cnt = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				//cout << i << " " << j << "\n";
				dfs(1, 4, 0);
				sort(b.begin(), b.end());
				if (b.size() >= 2 && b[0] == b[1]) {
					cnt++;
				}

			}
		}
		cout << cnt << "\n";
	}
	return 0;
}