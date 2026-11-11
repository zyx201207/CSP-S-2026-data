#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[900009];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, dc, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dc = a[i] - a[i - 1];
	}
	int t = dc;
	while (m > 0) {
		m -= t;
		t += dc;
		cnt++;
	}
	cout << cnt;
	return 0;
}