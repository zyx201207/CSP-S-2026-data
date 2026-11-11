#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n, m, a[N], ans;

inline void baoli() {
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int res = 0;
		int now = 0;
		for (int j = i; j >= max(i - m + 1, 1ll); j--) {
			now += (a[i] - a[j]);
			if (now > m) {
				break;
			}
			res++;
		}
		ans = max(ans, res);
	}
	cout << ans;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	// if (n <= 5000) {
	// 	baoli();
	// 	return 0;
	// }

	sort(a + 1, a + n + 1);
	int j = 1, now = 0; // first one
	for (int i = 2; i <= n; i++) {
		int df = a[i] - a[i - 1];
		now += ((i - 1) - j + 1) * df;
		while (j < i && now > m) {
			now -= (a[i] - a[j]);
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}