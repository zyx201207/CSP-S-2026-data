#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int t[510][500010];
int w[5000010];
vector<int> b[5000010];
ll mp[510][510];
int c, n, m, d, q;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int u;
			scanf("%d", &u);
			scanf("%d", &t[i][u]);
			b[u].push_back(i);
		}
	}
	memset(mp, inf, sizeof(mp));
	for (int i = 1; i <= m; i++) {
		if ((int)b[i].size() == 1)
			continue;
		for (int j = 0; j + 1 < (int)b[i].size(); j++) {
			for (int l = j + 1; l < (int)b[i].size(); l++) {
				int X = b[i][j];
				int Y = b[i][l];
				mp[X][Y] = min(mp[X][Y], 1LL * (t[X][i] + t[Y][i]));
				mp[Y][X] = min(mp[Y][X], 1LL * (t[X][i] + t[Y][i]));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		mp[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= n; l++) {
				mp[i][j] = min(mp[i][j], mp[i][l] + mp[l][j]);
			}
		}
	}
	for (int step = 1; step <= q; step++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = w[x] + w[y];
		ll res = inf;
		for (int i = 0; i < (int)b[x].size(); i++) {
			for (int j = 0; j < (int)b[y].size(); j++) {
				int X = b[x][i], Y = b[y][j];
				ll cnt = 1LL * t[X][x] + 1LL * t[Y][y];
				cnt += mp[X][Y];
				res = min(res, cnt);
			}
		}
		ans += res;
		printf("%lld\n", ans);
	}
	return 0;
}