#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], sum[N], sumf[N];

bool ck(int x) {
	for (int i = x; i <= n; i++) {
		long long res = (x * a[i]) - (sum[i] - sum[i - x ]) - (sumf[i] - sumf[i - x]);
		if (res <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			sum[i] = sum[i - 1] + a[i];
			sumf[i] = sumf[i - 1];
		} else {
			sumf[i] = sumf[i - 1] + a[i];
			sum[i] = sum[i - 1];
		}
	}
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ck(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
