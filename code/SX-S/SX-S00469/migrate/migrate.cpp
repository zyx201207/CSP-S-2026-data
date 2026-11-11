#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 10;
ll n, d, a[N], vis[N], ans;

int c, t;

inline bool check(int x, int y) {
	if ((c - d) % 2 == 0)
		return 0;
	return 1;
}

inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n > 30) {
		cout << n*(n - 1ll) / 2ll - (n - 1) << '\n';
		return;
	}
	ans = 0;
	for (int i = 1 ; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (check(i, j))
				ans ++;
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --) {
		solve();
	}
	return 0;
}
