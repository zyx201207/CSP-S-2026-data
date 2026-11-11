#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '/n'
int n, m;
int a[1000000 + 1];
int q, cnt = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) {
			cnt = cnt + 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		while (m > 0) {
			q = 1;
			m = m - (q * (a[i + 1] - a[i]));
			q = q + 1;
		}
	}
	q = (1 + q) * q / 2;
	cout << q + cnt;
	return 0;
}