#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], res;
void dfs(int x, int p, int ans) {
	if (x > m) {
		res = max(res, ans);
		return;
	}
	for (int i = p; i <= n; i++) dfs(x + 1, i + 1, (ans & a[i]));
	return;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int maxn = 0, tt = 35, minn = 0x3f3f3f3f, ff = 1, fff = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(a[i], maxn);
		int t = a[i], s = 0;
		while (t) s += t % 2, t /= 2;
		if (t < tt || (t == tt && a[i] < minn)) tt = t, minn = a[i];
		if (1 << s != a[i] + 1) ff = 0;
		if (a[i] != i - 1) fff = 0;
	}
	if (m == 1) {
		cout << maxn;
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if (n <= 20) {
		dfs(1, 1, 2147483647);
		cout << res;
		return 0;
	}
	if (m == n - 1) {
		int ans = 2147483647, f = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == minn && f == 0) {
				f = 1;
				continue;
			}
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (ff || fff) {
		sort (a + 1, a + n + 1);
		int ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--) ans &= a[i];
		cout << ans;
		return 0;
	}
	return 0;
}
