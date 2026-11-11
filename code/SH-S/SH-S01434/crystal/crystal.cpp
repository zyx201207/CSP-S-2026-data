#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, l, r;
ll m, a[500005], f[500005], p[500005];
bool check(int x) {
	ll nd, minn = LLONG_MAX;
	for (int i = x; i <= n; i++) {
		nd = a[i] * x - (p[i] - p[i - x]);
		minn = min(minn, nd);
	}
	return m >= minn;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + a[i];
	}
	l = 0, r = n;
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << '\n';
	return 0;
}
