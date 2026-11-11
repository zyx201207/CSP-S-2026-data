#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int _; cin >> _ >> _;
	while (_--) {
		int n, d; cin >> n >> d;
		vector<int> x(n+1, 0);
		vector<int> l(n+1, 0);
		vector<int> r(n+1, 0);
		vector<int> lf(n+1, 0);
		vector<int> rf(n+1, 0);
		for (int i = 1; i <= n; ++i) cin >> x[i];
		for (int i = 1, j = 1; i <= n; ++i) {
			while (x[i] - x[j] > d) ++j;
			l[i] = j;
			lf[i] = lf[j] + 1;
		}
		for (int i = n, j = n; i >= 1; --i) {
			while (x[j] - x[i] > d) --j;
			r[i] = j;
			rf[i] = rf[j] + 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 3; j <= n; ++j) {
				if (r[i] - l[j] == 1) {
					int res = 1;
					if (r[l[i]] == i && l[l[j]] == i) res *= lf[i];
					if (l[r[j]] == j && r[r[i]] == j) res *= rf[j];
					ans += res;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
