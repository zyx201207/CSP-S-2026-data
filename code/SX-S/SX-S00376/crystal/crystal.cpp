#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int n, m, a[N], sum[N];

bool check(int x, int y) {
	if (a[y]*x <= sum[y] - sum[y - x] + m && a[y]*x >= sum[y] - sum[y - x])
		return 1;
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ma = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, i)) {
				ans = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}
		ma = max(ma, ans);
	}
	cout << ma;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/