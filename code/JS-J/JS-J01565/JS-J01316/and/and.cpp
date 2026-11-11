#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, sum, ans;
int a[200005];
void dfs (int now, int depth) {
	if (depth >= m) {
		ans = max(ans, sum);
		sum = 0;
		return;
	}
	if (depth == 0) {
		for (int i = 1; i <= n; i++) {
			sum = a[i];
			dfs(i, depth + 1);
		}
	} else {
		for (int i = now + 1; i <= n; i++) {
			int s = sum;
			sum = (sum & a[i]);
			dfs(i, depth + 1);
			sum = s;
		}
	}
	return;
}
signed main ( void ) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
