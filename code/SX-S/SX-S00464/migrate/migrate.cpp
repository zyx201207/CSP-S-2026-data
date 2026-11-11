#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000005], f[2000005][2], s[2000005], l[2000005], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (long long i = 1; i <= n; i++) {
			cin >> x[i];
			f[i][0] = f[i][1] = s[i] = 0;
		}
		l[0] = 1;
		f[0][0] = f[0][1] = s[0] = ans = 0;
		for (long long i = 1; i <= n; i++) {
			l[i] = l[i - 1];
			while (x[i] - x[l[i]] > d) {
				f[i - 1][0]++;
				if (l[i] < i - 1)
					s[i - 1]++;
				l[i]++;
			}
			if (i < n && x[i + 1] - x[l[i]] <= d) {
				f[i][0] = 0;
				f[i][1] = 0;
				ans += f[l[i]][1];
			} else {
				f[i][0] = f[l[i]][0];
				f[i][1] = f[l[i]][1];
			}
			if (i - l[i] > 1) {
				if (i < n && x[i + 1] - x[l[i] + 1] <= d)
					ans += s[l[i] + 1];
				else
					f[i][1] += s[l[i] + 1];
			}
			if (i - l[i] > 1 && l[i] != l[l[i]] && x[l[i] + 1] - x[l[l[i]]] <= d && (i - l[i] == 2
			        || x[l[i] + 2] - x[l[l[i]]] > d)) {
				if (i < n && x[i + 1] - x[l[i] + 1] <= d)
					ans += f[l[l[i]]][0];
				else
					f[i][1] += f[l[l[i]]][0];
			}
			ans += f[i][1];
		}
		cout << ans << '\n';

	}
	return 0;
}