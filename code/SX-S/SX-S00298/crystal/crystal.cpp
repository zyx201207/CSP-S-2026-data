#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], sum[500005];

bool check(int len) {
	for (int i = len; i <= n; i++) {
		if (a[i]*len - (sum[i] - sum[i - len]) <= m)
			return true;
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << l - 1;
	return (0 - 0);
}
/*
5 8
-3 -1 2 2 7
*/
