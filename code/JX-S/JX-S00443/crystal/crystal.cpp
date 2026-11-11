#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int a[500005], s[500005];
int n, m;
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		int l = i, r = i + x - 1;
		if (r > n) break;
		int t = a[r] * (x - 1) - (s[r - 1] - s[l - 1]);
		if (t <= m) return 1;
	}
	return 0;
}
signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	int l = 1, r = n, ans = 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
