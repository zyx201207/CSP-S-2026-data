#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int c, t, n;
long long d, a[MAXN];

int main() {
	freopen("migrat.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		long long ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n - 1; i++) {
			int p1 = upper_bound(a + 1, a + n + 1, a[i] + d) - a, p2 = upper_bound(a + 1, a + n + 1, a[i + 1] + d) - a;
			if (p2 - p1 == 1)
				ans++;
		}
		cout << ans << "\n";
	}
}