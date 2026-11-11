#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, a[N], m, c[N], ans, h[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
	}
	c[1] = 0;
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1] + c[i] * (i - 1);
	}
	for (int i = n; i >= 1; i--) {
		auto it = lower_bound(h + 1, h + n + 1, h[i] - m) - h;
		ans = max(ans, i - it + 1);
	}
	cout << ans;
	return 0;
}
