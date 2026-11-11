#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pil = pair<int, ll>;

const int N = 2e6 + 5;

int tstcntc, t, n;
ll a[N], m;
//ll cz[N];
pil f[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	for (cin >> tstcntc >> t; t--;) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
//			cz[i] = a[i] - a[i - 1];
		}
//		if (n <= 2) {
//			cout << "0\n";
//			continue;
//		}
//		bool flag = 1;
//		for (int i = 3; i <= n; i++) {
//			flag &= cz[i] == cz[i - 1];
//		}
//		if (flag) {
//			cout << max(0ll, n - (m / cz[2]) * 2ll + 1) << '\n';
//			continue;
//		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			// (i, ?)
			f[i] = {0, 1};
			for (int j = i + 1; j <= n; j++) {
				for (int k = i; k <= j; k++) {
					if (a[j] - a[k] > m) continue;
					if (f[j].second > 2) break;
					if (!f[j].first || f[k].first + 1 < f[j].first) {
						f[j].first = f[k].first + 1;
						f[j].second = f[k].second;
					} else if (f[k].first + 1 == f[j].first) {
						f[j].second += f[k].second;
					}
				}
				if (f[j].second == 2) ans++;
			}
			for (int j = 1; j <= n; j++) {
				f[j] = {0, 0};
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

