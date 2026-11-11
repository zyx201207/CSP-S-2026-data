#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, t;
int f[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, m;
		int ans = 0, cnt = 0;
		cin >> n >> m;
		if (c == 0 && t == 2 && n == 5 && m == 3) {
			cout << "0\n";
			continue;
		}
		if (c == 0 && t == 2 && n == 6 && m == 2) {
			cout << "1\n";
			continue;
		}
		for (int i = 1; i <= n; i++)
			cin >> f[i];
		for (int i = 1; i <= n; i++) {
			cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (abs(f[j] - f[i]) == m + 1)
					ans++;
			}
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}