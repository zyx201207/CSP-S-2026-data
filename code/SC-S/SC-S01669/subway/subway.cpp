#include <bits/stdc++.h>
using namespace std;
using t = pair<long long, long long>;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	long long c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<long long> w(m);
	for (long long i = 0; i < m; i++) cin >> w[i];
	vector<vector<vector<t>>> g(n);
	for (long long i = 0; i < n; i++) {
		long long k;
		cin >> k;
		g[i].resize(k);
		for (long long j = 0; j < k; j++) {
			long long t_n, t_t;
			cin >> t_n >> t_t;
			g[i][j].push_back({t_t, t_n});
		}
	}
	while (q--) {
		long long x, y;
		cin >> x >> y;
		long long ans = 0;
		for (auto i : w) ans += i;
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
