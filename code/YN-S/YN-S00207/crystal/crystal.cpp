#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int sum[500001];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;
		bool d = false;

		for (int i = 1; i + mid - 1 <= n; i++) {

			if (a[i + mid - 1]*mid - sum[i + mid - 1] + sum[i - 1] <= m) {
				d = true;
				break;
			}
		}

		if (d) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout << ans;
	return 0;
}