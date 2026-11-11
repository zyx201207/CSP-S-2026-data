#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, a[500010], cnt = 1, ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (m - a[i] + a[j] >= 0) {
				m = m - a[i] + a[j];
				a[j] = a[i];
			} else
				break;
		}
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i < n; i++) {
		if (a[i + 1] == a[i])
			cnt++;
		else
			cnt = 1;
		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}
