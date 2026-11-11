#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d, q, c, uu[500005], ww[500005], nn, ans, l, r, dij[500005], f[500005], mm = INT_MAX, si, p[500005],
                                                                                  w[500005];

struct T {
	int u, w;
} v[5005][5005];

struct V {
	int a, t;
} ss[2500005];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> nn;
		for (int j = 1; j <= nn; j++) {
			cin >> ss[j].a >> ss[j].t;
		}
		for (int j = 1; j <= nn - 1; j++) {
			for (int k = i + 1; k <= nn; k++) {
				v[ss[j].a][++p[ss[j].a]].u = ss[k].a;
				v[ss[k].a][++p[ss[j].a]].u = ss[j].a;
				v[ss[k].a][++p[ss[j].a]].w = ss[j].t + ss[k].t;
				v[ss[j].a][++p[ss[j].a]].w = ss[j].t + ss[k].t;
			}
		}
	}
	while (q--) {
		cin >> l >> r;
		memset(dij, 0x3f, sizeof 0x3f);
		dij[l] = 0;
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= m; i++) {
				if (f[i] == 0 && dij[i] < mm) {
					dij[i] = mm;
					si = i;
				}
			}
			f[si] = 1;
			if (si == r) {
				cout << w[l] + w[r] + dij[si] << endl;
				break;
			}
			for (int i = 1; i <= p[i]; i++) {
				int _u = v[si][i].u, _w = v[si][i].w;
				if (dij[_u] < dij[si] + _w) {
					dij[_u] = dij[si] + _w;
				}
			}
		}

	}
	return 0;
}
