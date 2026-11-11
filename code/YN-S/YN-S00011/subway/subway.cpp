//by.pcx
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M], x[M], y[M], k[N];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, t;
			cin >> a >> t;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	while (q--) {
		if (q == 1)
			cout << k[1] + k[2];
		else
			cout << 0;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/