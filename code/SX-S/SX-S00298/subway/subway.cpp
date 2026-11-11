#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q, w[500005], k[505], v[505][505], f[505], mi[505];
vector<int> a[500005], t[500005], dd[500005];
map<int, int> tt[500005];

signed main() {
	freopen("subway4.in", "r", stdin);
	freopen("zhr.out", "w", stdout);
	memset(v, 0x3f, sizeof(v));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int kk, kkk;
			cin >> kk >> kkk;
			a[i].push_back(kk);
			t[i].push_back(kkk);
			dd[kk].push_back(i);
			tt[kk][i] = kkk;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k[i]; j++) {
			for (int k1 = 0; k1 < (int)dd[a[i][j]].size(); k1++) {
				int u = dd[a[i][j]][k1];
				if (u != i)
					v[i][u] = min(v[i][u], t[i][j] + tt[a[i][j]][u]);
			}
		}
	}
	while (q--) {
		memset(mi, 0x3f, sizeof(mi));
		memset(f, 0, sizeof(f));
		int from, to;
		cin >> from >> to;
		for (int i = 0; i < (int)dd[from].size(); i++) {
			mi[dd[from][i]] = tt[from][dd[from][i]];
		}
		for (int i = 1; i <= n; i++) {
			int mii, mx = LLONG_MAX;
			for (int j = 1; j <= n; j++) {
				if (!f[j]) {
					if (mi[j] < mx) {
						mx = mi[j];
						mii = j;
					}
				}
			}
			f[mii] = true;
			for (int j = 1; j <= n; j++) {
				if (v[mii][j] != v[0][0] && f[j] != true) {
					mi[j] = min(mi[j], mi[mii] + v[mii][j]);
				}
			}
		}
		int ans = LLONG_MAX;
		for (int i = 0; i < (int)dd[to].size(); i++) {
			ans = min(ans, mi[dd[to][i]] + tt[to][dd[to][i]]);
		}
		cout << ans + w[from] + w[to] << '\n';
	}
	return (0 - 0);
}
