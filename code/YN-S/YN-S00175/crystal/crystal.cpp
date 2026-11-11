//hy
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N], b[N];
int ans;

bool ck(int x) {
	for (int i = x; i <= n; i++) {
		int t = b[i] - b[i - x];
		if (abs(x * a[i] - t) <= m)
			return 1;
	}
	return 0;
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
		b[i] = a[i] + b[i - 1];
	}
	int l = 1, r = n;
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
