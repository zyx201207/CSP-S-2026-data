#include <bits/stdc++.h>

#define int long long

using namespace std;

const int kMaxN = 2e6 + 5;

int c, t, n, d, x[kMaxN], L[kMaxN], f[kMaxN], sum[kMaxN];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		L[i] = lower_bound(x + 1, x + i + 1, x[i] - d) - x;
	}
	L[n + 1] = n + 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = sum[i] = 0;
		int l = L[i], r = L[i + 1] - 1;
		ans += (l < i - 1) * (L[l + 1] == L[l] ? f[l + 1] : min(L[l + 2] - L[l + 1], f[l + 1])) + sum[l];
		f[i] = f[l] + r - l + 1;
		sum[i] = sum[l] + (l < r) * f[l + 1];
		if (l > r) f[i] = 0, sum[i] = 0;
	}
	cout << ans << '\n';
}

signed main() {
  freopen("migrate.in", "r", stdin);
  freopen("migrate.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
	for (cin >> c >> t; t; t--)
		solve();
  return 0;
}
// zha le