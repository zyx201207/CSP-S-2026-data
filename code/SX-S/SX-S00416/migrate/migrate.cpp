#include <bits/stdc++.h>
using namespace std;
long long a[200010], s[200010], z[200010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long t, n, m, ans;
	cin >> t >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		ans = 0;
		for (int i = 1; i < n; i++) {

			memset(s, 0x7f, sizeof(s));
			memset(z, 0, sizeof(z));
			z[i] = 1;
			s[i] = 0;
			for (int j = i + 1; j <= n; j++) {
				for (int k = i; k < j; k++) {
					if (a[j] - a[k] <= m) {
						if (s[k] + 1 == s[j]) {
							z[j] = z[k] + z[j];
						}
						if (s[k] + 1 < s[j]) {
							s[j] = s[k] + 1;
							z[j] = z[k];
						}
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				if (z[j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
