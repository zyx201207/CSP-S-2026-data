#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e6 + 10;
int c, t, n, d, a[N], dp[N];
bool flag = 1;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i >= 2 && (a[i] - a[i - 1] != a[i - 1] - a[i - 2]))
				flag = 0;
		}
		if (flag) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if ((d / (a[2] - a[1])) - (i - 2) % (d / (a[2] - a[1])) == 2 && i - 1 >= d)
					ans += (n - i + 1);
			cout << ans << endl;
		} else
			cout << 0 << endl;
	}
	return 0;
}
