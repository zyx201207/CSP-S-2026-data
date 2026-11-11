#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 510;
const int M = 500010;
const LL INF = 1e18;

#define fi first
#define se second

int C, m, n, d, q;
LL w[M], f[N][N];
vector<pair<int, int> > h[M];
vector<LL> t[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &q);
	for(int i = 1; i <= m; ++ i) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; ++ i) {
		int k; scanf("%d", &k);
		t[i].push_back(0);
		for(int j = 1; j <= k; ++ j) {
			LL x, y; scanf("%lld%lld", &x, &y);
			t[i].push_back(y);
			h[x].push_back({i, j});
		}
	}
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			f[i][j] = (i == j ? 0 : INF);
	for(int i = 1; i <= m; ++ i) {
		int s = h[i].size();
		for(int j = 0; j < s; ++ j)
			for(int k = j + 1; k < s; ++ k) {
				f[h[i][j].fi][h[i][k].fi] = min(f[h[i][j].fi][h[i][k].fi], t[h[i][j].fi][h[i][j].se] + t[h[i][k].fi][h[i][k].se]);
				f[h[i][k].fi][h[i][j].fi] = f[h[i][j].fi][h[i][k].fi];
			}
	}
	for(int k = 1; k <= n; ++ k)
		for(int i = 1; i <= n; ++ i)
			for(int j = 1; j <= n; ++ j)
				if(f[i][k] != INF && f[k][j] != INF)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q --) {
		int x, y; scanf("%d%d", &x, &y);
		LL ans = INF;
		for(int i = 0; i < h[x].size(); ++ i)
			for(int j = 0; j < h[y].size(); ++ j)
				ans = min(ans, f[h[x][i].fi][h[y][j].fi] + t[h[x][i].fi][h[x][i].se] + t[h[y][j].fi][h[y][j].se]);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
