#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200009];
int n, k;
int ans = -100;

void dfs(int dep, int sum, int cnt) {
	if (dep > n || cnt == k) {
		if (cnt == k) {
			ans = max(ans, sum);
		}
		return ;
	} else {
		if (cnt < k) {
			dfs(dep + 1, sum & a[dep], cnt + 1);
			dfs(dep + 1, sum, cnt);
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.in", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 1048575, 0);
	cout << ans;
	return 0;
}