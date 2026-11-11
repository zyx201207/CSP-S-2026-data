#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1, 0), d(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int sum = 0, ans = 0;
	sort(a.begin(), a.end());
	d[1] = 0;
	bool f = true;
	for (int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		if (d[i] != 1)
			f = false;
	}
	if (f && n <= m) {
		cout << n;
		return 0;
	} else if (f && m < n) {
		cout << m;
		return 0;
	}
	int i = 1;
	while (1) {
		sum += d[i];
		if (sum > m)
			break;
		ans++;
		i++;
		if (i == n)
			break;
	}
	cout << ans;
	return 0;
}