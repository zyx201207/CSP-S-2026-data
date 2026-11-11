#include <cstdio>
#include <iostream>

using namespace std;

const int N = 510, M = 5e5 + 10, K = 30;
const long long INF = 0x3f3f3f3f3f3f3f;

int w[M], k[N], a[N][N], t[N][N];
long long mp[N][N];
long long sum[M], num[M][K], tim[M][K];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(), cout.tie();
	int n, m, q;
	cin >> n >> n >> m >> q >> q;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (i != j)
				mp[i][j] = INF;
	for (int i = 1; i <= m; i ++)
		for (int j = 1; j <= n; j ++)
			tim[i][j] = INF;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			cin >> a[i][j] >> t[i][j];
			num[a[i][j]][++ sum[a[i][j]]] = i;
			tim[a[i][j]][sum[a[i][j]]] = t[i][j];
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int p = 1; p <= sum[i]; p ++) {
			for (int q = p + 1; q <= sum[i]; q ++) {
				mp[num[i][p]][num[i][q]] = min(mp[num[i][p]][num[i][q]], tim[i][p] + tim[i][q]);
				mp[num[i][q]][num[i][p]] = mp[num[i][p]][num[i][q]];
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			for (int q = 1; q < i; q ++) {
				mp[i][j] = min(mp[i][j], mp[i][q] + mp[q][j]);
				mp[j][i] = mp[i][j];
			}
		}
	}
	for (int i = 1; i <= q; i ++) {
		int star, sto;
		cin >> star >> sto;
		long long ans = INF;
		for (int p = 1; p <= sum[star]; p ++) {
			for (int q = 1; q <= sum[sto]; q ++) {
				ans = min(ans, mp[num[star][p]][num[sto][q]] + tim[star][p] + tim[sto][q]);
			}
		}
		cout << ans + w[star] + w[sto] << '\n';
	}
	return 0;
}
