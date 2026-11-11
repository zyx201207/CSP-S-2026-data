#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM = 2e5 + 5;
ll n, m, a[NM];

ll read() {
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + (ch - '0');
		ch = getchar();
	}
	return s * w;
}

namespace subtesk1 {
	void solve() {
		ll ans = -1;
		for (ll i = 1; i <= n; i++) {
			ans = max(a[i], ans);
		}
		cout << ans << '\n';
		return ;
	}
}

namespace subtesk2 {
	void solve() {
		ll ans = -1;
		for (ll i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					continue;
				}
				ll tmp = a[i];
				tmp &= a[j];
				ans = max(ans, tmp);
			}
		}
		cout  << ans << '\n';
		return ;
	}
}

namespace subtesk3 {
	ll ans = -1;
	ll tmp;
	void dfs(ll i, ll x, ll y) {
		if (x == m) {
			ans = max(ans, y);
			return;
		}
		for (ll j = i + 1; j <= n; j++) {
			tmp = y;
			tmp &= a[j];
			dfs(j, x + 1, tmp);
			dfs(j, x, y);
		}
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			dfs(i, 1, a[i]);
		}
		cout << ans << '\n';
		return ;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	if (m == 1) {
		subtesk1::solve();
		return 0;
	} else if (m == 2) {
		subtesk2::solve();
		return 0;
	} else {
		subtesk3::solve();
		return 0;
	}

	return 0;
}