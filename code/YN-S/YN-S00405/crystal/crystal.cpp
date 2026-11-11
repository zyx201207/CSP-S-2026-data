#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500050], sum[500050], n, m, ans;

int check(int x) {
	for (int i = x; i <= n; i++) {
		int p = a[i] * (x - 1) - (sum[i - 1] - sum[i - x]);
		if (p <= m)
			return 1;
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/