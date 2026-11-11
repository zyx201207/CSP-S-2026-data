#include <bits/stdc++.h>
using namespace std;
int a[200005];
int n, m, ans = 0;
void dfs (int x, int cnt, int ret) {
	if (cnt == m) {
		ans = max(ret, ans);
		return;
	}
	for (int i = x; i <= n; i++) {
		dfs(i + 1, cnt + 1, ret & a[i]);
	}
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int s = (1<<25) - 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s &= a[i];
	}
	if (n <= 2000) {
		dfs(1, 0, (1<<25) - 1);
		cout << ans;
	} else {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
	}
	return 0;
}