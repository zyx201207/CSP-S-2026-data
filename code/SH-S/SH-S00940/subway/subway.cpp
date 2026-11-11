#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 5e2 + 10, M = 5e5 + 10;
int e[M][N];
int w[M];
LL f[N][N];
vector <int> sub[M];
int n, m, c, d, q;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int times;
		cin >> times;
		for (int j = 1; j <= times; j++) {
			int a, t;
			cin >> a >> t;
			e[a][i] = t;
			sub[a].push_back(i);
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= m; i++) {
		if (sub[i].size() > 1) {
			for (int u = 0; u < sub[i].size(); u++) {
				for (int v = 0; v < sub[i].size(); v++) {
					if (u == v) f[sub[i][u]][sub[i][v]] = 0;
					else f[sub[i][u]][sub[i][v]] = min(f[sub[i][u]][sub[i][v]], 0LL + e[i][sub[i][u]] + e[i][sub[i][v]]);
				}
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		int s, t;
		LL ans = LLONG_MAX;
		cin >> s >> t;
		for (int si = 0; si < sub[s].size(); si++) {
			for (int ti = 0; ti < sub[t].size(); ti++) {
				ans = min(ans, f[sub[s][si]][sub[t][ti]] + e[s][sub[s][si]] + e[t][sub[t][ti]]);
			}
		}
		cout << ans + w[s] + w[t] << '\n';
	}
	return 0;
}
