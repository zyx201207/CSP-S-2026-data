#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n, a[N], m, sum[N], ans;

bool check(int x) {
	for (int i = x; i <= n; i++) {
		int num = sum[i] - sum[i - x], maxx = a[i];
		if (maxx * x - num <= m)
			return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int l = 1, r = n; l <= r; ) {
		int mid = l + ((r - l) >> 1);
		if (check(mid))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}