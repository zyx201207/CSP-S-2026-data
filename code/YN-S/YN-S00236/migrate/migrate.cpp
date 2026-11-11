#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, T, n, d, x[N], f[N], val[N], sum[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		if (c == 13 || c == 14) {
			int id = 0, ans = 0;
			sum[0] = 0;
			for (int i = 1; i <= n; i++) {
				sum[i] = 0;
				if (x[i] - x[1] <= d && x[n] - x[i] <= d) {
					id = i;
				}
			}
			int l = 1;
			for (int i = id + 1; i <= n; i++) {
				while (x[i] - x[l] > d)
					l++;
				if (id - l < 2)
					sum[id - l]++;
			}
			l = n;
			for (int i = id; i >= 1; i--) {
				while (x[l] - x[i] > d)
					l--;
				if (l - id < 2)
					ans += sum[1 - (l - id)];
			}
			cout << ans << "\n";
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++)
					f[j] = val[j] = 0;
				f[i] = 1;
				int l = i;
				for (int j = i + 1; j <= n; j++) {
					while (x[j] - x[l] > d && l < j) {
						l++;
					}
					if (l == j)
						break;
					val[j] = val[l] + 1;
					for (int k = l; k <= min(l + 3, j - 1); k++) {
						if (val[k] == val[l]) {
							f[j] += f[k];
							if (f[j] > 2)
								break;
						} else
							break;
					}
					if (f[j] == 2)
						ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
