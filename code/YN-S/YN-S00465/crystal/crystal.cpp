#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int N = 5 * 1e5 + 5;
int a[N];
int sum[N];
int step[N];
int ans = 0;

bool check(int x) {
	for (int i = 1; i <= x; i ++) {
		if (step[i] > m) {
			return false;
		}
	}
	return true;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		step[i] = (i - 1) * a[i] - sum[i - 1];
	}
	if (step[n] <= m) {
		cout << n;
		return 0;
	}

	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;

	return 0;
}