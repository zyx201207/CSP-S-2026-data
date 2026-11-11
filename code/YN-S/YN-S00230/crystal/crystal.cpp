#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N];
int sum[N], sum1[N];

bool ck(int x) {
	int l = x - 1;
	int mi = 1e18;
	for (int i = 1; i <= n; i++) {
		if (i - l >= 1) {
			mi = min(mi, a[i] * x - (sum[i] - sum[max(0ll, i - l - 1)]));
		}
	}
	return mi <= m;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = n; i >= 1; i--) {
		sum1[i] = sum1[i + 1] + a[i];
	}
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (ck(mid)) {
			l = mid + 1;
			ans = mid;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}