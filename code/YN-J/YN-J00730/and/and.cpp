#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], ans = 0;

void dfs(int c, int dep, int sum) {
	if (c == m) {
		ans = max(ans, sum);
		return ;
	}
	if (dep > n)
		return;
	dfs(c, dep + 1, sum);
	if (c == 0)
		dfs(c + 1, dep + 1, a[dep]);
	else
		dfs(c + 1, dep + 1, sum & a[dep]);
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++)
			ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if (n <= 2000 && m == 2) {
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				ans = max(ans, a[i] & a[j]);
		cout << ans;
		return 0;
	}
	if (n <= 20) {
		dfs(0, 1, 0);
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}