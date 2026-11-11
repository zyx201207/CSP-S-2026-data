#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;
long long n, m, ans = LONG_LONG_MIN, a[N], vis[N];

void dfs(long long x, long long sum) {
	if (x == m + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			dfs(x + 1, (sum & a[i]));
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
		dfs(2, a[i]);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}
