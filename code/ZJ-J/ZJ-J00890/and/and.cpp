#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int maxn2 = 2 * 1e5 + 5;
int n, m, a[maxn2], suf[maxn2], pre[maxn2];
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	int is_A = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int flag = 0;
		for (int j = 0; j <= 30; j++)
			if (a[i] == (1 << j) - 1)
				flag = 1;
		is_A &= flag;
	}
	if (n <= 20) {
		int ans = 0;
		for (int i = 0; i < 1 << n; i++)
			if (__builtin_popcount(i) == m) {
				int res = INT_MAX;
				for (int j = 0; j < n; j++)
					if (i >> j & 1)
						res &= a[j + 1];
				ans = max(res, ans);
			}
		cout << ans;
	} else if (n <= 2000) {
		if (m == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				ans = max(ans, a[i]);
			cout << ans;
		} else if (m == 2) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					ans = max(ans, a[i] & a[j]);
			cout << ans;
		} else if (m == n) {
			int ans = INT_MAX;
			for (int i = 1; i <= n; i++)
				ans &= a[i];
			cout << ans;
		}
	} else if (m == n - 1) {
		int ans = 0;
		pre[0] = suf[n + 1] = INT_MAX;
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] & a[i];
		for (int i = n; i >= 1; i--)
			suf[i] = suf[i + 1] & a[i];
		for (int i = 1; i <= n; i++)
			ans = max(ans, pre[i - 1] & suf[i + 1]);
		cout << ans;
	} else if (is_A) {
		sort(a + 1, a + n + 1, greater <int> ());
		int ans = INT_MAX;
		for (int i = 1; i <= m; i++)
			ans &= a[i];
		cout << ans;
	}
}