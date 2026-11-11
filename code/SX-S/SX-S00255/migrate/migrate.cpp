#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		memset(a, 0, sizeof a);
		int n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++) {
			int id = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
			int r = upper_bound(a + 1, a + n + 1, a[i] + d ) - a;
			if (r > n || id - 2 < i || r == id)
				continue;
			int lac = a[id] - a[i];
			int lab	= a[id - 1] - a[i];
			int lbd = a[r] - a[id - 1];
			int lae = a[id - 2] - a[i];
			int led = a[r] - a[id - 2];

			if (0 < lac && lac <= d && 0 < lab && lab <= d && 0 < lbd && lbd <= d) {
				if (0 < lae && lae <= d && 0 < led && led <= d)
					continue;

				ans += (r - id);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
