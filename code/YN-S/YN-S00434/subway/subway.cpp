#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[900009];
int k[900009];
int a[2009][2009];
int t[2009][2009];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j];
		}
		for (int j = 1; j <= k[i]; j++) {
			cin >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int s, e;
		cin >> s >> e;
		int ans = w[s] + w[e];
		cout << ans << '\n';
	}
	return 0;
}