#include <bits/stdc++.h>
using namespace std;
using uns = long long;
using ll = long long;
using ull = long long;
ll a[2000000]; uns c;
ull sp[1001][1001], dp[1001][1001];
uns n; ll d;

void get_sp(uns l, uns r) {
	uns lst = l;
	for (uns i = l + 1; i <= r; ++i) {
		if (a[i] - a[lst] > d) ++sp[l][r], lst = i - 1;
	} ++sp[l][r];
	return;
}

void alg() {
	memset(sp, 0, sizeof sp);
	memset(dp, 0, sizeof dp);
	cin >> n >> d;
	for (uns i = 0; i < n; ++i) cin >> a[i];
	if (c >= 11 && c <= 12) {
		uns gc = a[1] - a[0];
		uns len = d / gc;
		if (len == 0) { puts("0"); return; }
		cout << n - len - 1 << '\n';
		return;
	}
	
	for (uns i = 0; i < n; ++i) {
		for (uns j = i + 1; j < n; ++j) {
			get_sp(i, j);
		}
	}
	uns ans = 0;
	for (uns len = 1; len <= n; ++len) {
		for (uns l = 0; l < n; ++l) {
			uns r = l + len - 1;
			dp[l][r] = a[r] - a[l] <= d;
			for (uns k = l + 1; k < r; ++k) {
				if (sp[l][k] + sp[k][r] != sp[l][r]) continue;
				dp[l][r] += dp[l][k] * dp[k][r];
			}
			if (dp[l][r] == 2) ++ans;
		}
	}
	cout << ans << '\n';
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	uns t;
	cin >> c >> t;
	while (t--) alg();
	return 0;
}
