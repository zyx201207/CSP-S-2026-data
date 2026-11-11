#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, s;
int w[500010];
int k[510];
int a[510][510];
int t[510][510];
int x[100010];
int y[100010];
int dist[510][510];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i1 = 1; i1 <= q; i1++) {
		cin >> x[i1] >> y[i1];
		s = 0;
		s = w[x[i1]] + w[y[i1]] + t[1][1] + t[1][1];
		cout << s << endl;
	}
	return 0;
}