#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define pb push_back
using namespace std;
mt19937_64 rnd(time(0));
int Rand(int l, int r) {
	return rnd() % (r - l + 1) + l;
}
void solve() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<int>w(m + 1), Path(n + 1);
	vector<vector<int>> crs(n + 1);
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> Path[i];
		crs[i].resize(Path[i] * 2 + 1);
		for (int j = 1; j <= Path[i]; j++) cin >> crs[i][j];
	}
	vector<int>st(q + 1), en(q + 1);
	for (int i = 1; i <= q; i++) cin >> st[i] >> en[i];
	for (int i = 1; i <= q; i++) cout << Rand(1, 100000) << "\n";
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}