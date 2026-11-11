#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], sum[N];

inline bool check(int x) {
	for (int i = 1; (i + x - 1) <= n; i ++) {
		int l = i, r = i + x - 1;
		if (a[r] * x - (sum[r] - sum[l - 1]) <= m) {
//			cout << " paqieraputoip" << endl;
			return 1;
		}
	}
	return 0;
}

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0, r = n, mid, ans = 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int T;
	T = 1;
	while (T --) {
		solve();
	}
	return 0;
}
