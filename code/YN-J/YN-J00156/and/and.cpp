#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], ans, d1[200005], d2[200005];

void dfs(int x, int dep, int cnt) {
	if (x == m) {
		ans = max(ans, cnt);
		return;
	}
	if (dep == n + 1) {
		return;
	}
	dfs(x, dep + 1, cnt);
	if (x + 1 <= m) {
		dfs(x + 1, dep + 1, (cnt & a[dep]));
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 20) {

		int cf = 1;
		for (int i = 1; i <= 31; i++) {
			cf *= 2;
		}
		cf--;
		dfs(0, 1, cf);
		cout << ans;
		return 0;
	} else if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	} else if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	} else if (m == n - 1) {
		d1[1] = a[1];
		for (int i = 2; i <= n; i++) {
			d1[i] = (d1[i - 1] & a[i]);
		}
		d2[n] = a[n];
		for (int i = n - 1; i >= 1; i--) {
			d2[i] = (d2[i + 1] & a[i]);
		}
		for (int i = 1; i <= n; i++) {
			int v1 = i - 1;
			int v2 = i + 1;
			ans = max(ans, (d1[v1] & d2[v2]));
		}
		cout << ans;
		return 0;
	} else {

		sort(a + 1, a + n + 1);
		ans = a[n];
		for (int i = n - 1; i >= n - m + 1; i--) {
			ans = (ans & a[i]);
		}
		cout << ans;
	}
	return 0;
}