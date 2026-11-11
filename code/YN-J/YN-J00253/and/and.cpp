//2026.10.31  zyb  and
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, Inf = (1 << 30) - 1;
int n, m, a[N], ans, s[N];

void dfs(int pos, int cnt, int sum) {
	if (pos == n + 1) {
		if (cnt < m)
			return ;
		ans = max(ans, sum);
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		int res = Inf;
		if (i)
			res = a[i];
		dfs(pos + 1, cnt + i, sum + res);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	bool flagA = true, flagB = (n == (n & -n));
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
		if (a[i] & (a[i] + 1))
			flagA = false;
		if (a[i] != i - 1)
			flagB = false;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans << '\n';
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = (ans & a[i]);
		cout << ans << '\n';
		return 0;
	}
	if (flagB) {
		cout << n - m << '\n';
		return 0;
	}
	if (m == n - 1) {
		s[n + 1] = Inf;
		for (int i = n; i >= 1; i--)
			s[i] = (s[i + 1] & a[i]);
		int sum = Inf;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, sum & s[i + 1]);
			sum = (sum & a[i]);
		}
		cout << ans << '\n';
		return 0;
	}
	if (flagA) {
		sort(a + 1, a + n + 1, greater<int>());
		cout << a[m] << '\n';
		return 0;
	}
	if (m == 2 && n * n <= 1e9) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans << '\n';
		return 0;
	}
	if (maxx * n <= 5e8) {
		int ans = 0;
		for (int x = maxx; x >= 1; x--) {
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				cnt += ((x & a[i]) == x);
			if (cnt >= m) {
				ans = x;
				break;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	if (n <= 20) {
		dfs(1, 0, (1 << 30) - 1);
		cout << ans << '\n';
		return 0;
	}
	cout << maxx << '\n';
	return 0;
}