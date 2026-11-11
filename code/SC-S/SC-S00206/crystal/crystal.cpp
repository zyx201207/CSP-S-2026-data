#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 5000000;
ll a[N], d[N];
int n;
ll m;
bool check(int x) {
	ll minn = LONG_LONG_MAX;
	for (int i = 1; i <= n - x + 1; i++) {
		ll sum = 0;
		for (int j = i; j <= (i + x - 1); j++) {
			sum += abs(d[j] - d[(i + i + x - 1) / 2]);
		}
		//cout << sum << endl;
		if (sum <= m) {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, [](int x, int y) {
		return x > y;
	});
	
	for (int i = 1; i < n; i++) {
		d[i + 1] = d[i] + a[i] - a[i + 1];
	}
	int l = 1, r = n, mid, maxn = 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (check(mid)) {
			l = mid + 1;
			maxn = max(maxn, mid);
		} else {
			r = mid - 1;
		}
	}
	cout << maxn << endl;
	return 0;
}