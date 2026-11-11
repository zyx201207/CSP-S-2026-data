#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10086;
int a[N], pre[N], erp[N], n, m;

int ans = 0;
void dfs(int id, int nw, int pre) {
	if (id > m) {
		ans = max(ans, nw);
		return;
	}
	if (n - id + 1 < m) return;
	for (int i = pre + 1; i <= n; i++) {
		dfs(id + 1, nw & a[i], i);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	} else if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	} else if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
		return 0;
	} else if (m == n - 1) {
		pre[1] = a[1];
		for (int i = 2; i <= n; i++) {
			pre[i] = pre[i - 1] & a[i];
		}
		int t = a[n];
		int ans = pre[n - 1];
		for (int i = n - 1; i >= 2; i--) {
			ans = max(ans, pre[i - 1] & t);
			t &= a[i];
		}
		ans = max(ans, t);
		cout << ans;
		return 0;
	} else {
		bool f = true;
		for (int i = 1; i <= n; i++) {
			int t = __builtin_popcount(a[i]);
			if (a[i] + 1 != (1 << t)) f = false;
		}
		if (f) {
			sort(a + 1, a + 1 + n, greater<int>());
			cout << a[m];
			return 0;
		} else {
			dfs(1, (1 << 20) - 1, 0);
			cout << ans;
		}
	}
	return 0;
}