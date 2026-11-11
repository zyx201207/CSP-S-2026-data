#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, ans, a[2000005], way[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		if (c == 13 || c == 14) {
			int x = n;
		}
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= d; j++) {
				way[i + j]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (way[i] == 2)
				ans++;
			way[i] = 0;
		}
		cout << ans << endl;
	}
	return 0;
}