#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], s[500005];
int n, m;

bool check(int x) {
	for (int l = 1; l <= n - x; l++) {
		int r = l + x - 1;
		int len = r - l + 1;
		int w = len * a[r];
		int k = s[r] - s[l - 1];
		w -= k;
		if (w <= m)
			return 1;
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int l = 1, r = n;
	int ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
