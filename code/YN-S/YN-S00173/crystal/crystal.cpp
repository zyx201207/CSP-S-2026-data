#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 5e5 + 5;
int n, m, a[Maxn], sum[Maxn];

bool check(int k) {
	for (int i = 1; i + k - 1 <= n; i++) {
		int x = a[i + k - 1] * (k - 1);
		int y = sum[i + k - 2] - sum[i - 1];
		if (x - y <= m)
			return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}