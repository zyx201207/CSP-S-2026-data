#include <bits/stdc++.h>
using namespace std;
const int MAX = 3005;
int c, t;
int n, d;
long long a[MAX];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		long long m = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			m = max(a[i], m);
		}
		long long cnt = 0, ans = 0;
		for (int  i = 4; i <= n; i++) {
			if (a[i] - a[i - 2] > d && a[i] - a[i - 1] <= d)
				ans += cnt;
			else
				cnt = 0;
			if (a[i - 2] - a[i - 3] <= d && a[i - 1] - a[i - 3] <= d && a[i] - a[i - 1] <= d && a[i] - a[i - 2] <= d
			        && a[i] - a[i - 3] > d) {
				cnt++;
				ans++;
			}
		}
		if (a[n] - a[1] <= 2 * d)
			cout << n - 3 << '\n';
		else
			cout << ans << '\n';
	}
	return 0;
}