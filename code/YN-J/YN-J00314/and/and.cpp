#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, a[200005], f[40];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	f[0] = 1;

	for (int i = 1; i <= 30; i++) {

		f[i] = f[i - 1] * 2;
	}

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int j = 1;

	for (int i = 30; i >= 0; i--) {

		sort(a + j, a + n + 1);

		if (f[i] > a[n]) {
			continue;
		}

		int cnt = n - (lower_bound(a + j, a + n + 1, f[i] + ans) - a) + 1;

		if (cnt >= m) {
			ans += f[i];
			j = n - cnt + 1;
		} else {
			for (int k = n - cnt + 1; k <= n; k++) {

				a[k] -= f[i];
			}
		}
	}

	cout << ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/