#include <bits/stdc++.h>
using namespace std;
long long rf, n, m, d, q, k, a, w, xl[505][505050], tt[505], mn = 1e7;

struct nd {
	int x[22], s[22], kz, t = 1, v;

} z[505050];

int main() {
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	for (int i = 1; i <= 505; i++)
		tt[i] = 1;
	cin >> rf >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> z[i].kz;
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int xx;
			cin >> xx;
			z[xx].x[z[xx].t] = i;
			cin >> z[xx].s[z[xx].t++];
			xl[i][tt[i]++] = xx;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> a >> w;
		cout << z[a].ks + z[w].ks;
	}

	return 0;
}