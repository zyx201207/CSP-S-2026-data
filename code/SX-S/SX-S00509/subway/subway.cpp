#include <bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>
void read(T& x) {
	x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9')
		ch = getchar();
	while (ch>='0' && ch<='9') {
		x = (x<<3) + (x<<1) + (ch^48);
		ch = getchar();
	}
}
constexpr LL MAX = 1LL<<61;
pair<int, LL> sta[500007][25];
int totsta[500007];
LL cost[500007];
LL dis[507][507];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int testidx, n, m, d, q;
	read(testidx), read(n), read(m), read(d), read(q);
	for (int i = 1; i <= m; ++i)
		read(cost[i]);
	for (int i = 1; i <= n; ++i) {
		int k;
		read(k);
		while (k--) {
			int u;
			LL x;
			read(u), read(x);
			sta[u][++totsta[u]] = {i, x};
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				dis[i][j] = MAX;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= totsta[i]; ++j) {
			int u = sta[i][j].first;
			LL x = sta[i][j].second;
			for (int k = j+1; k <= totsta[i]; ++k) {
				int v = sta[i][k].first;
				LL y = sta[i][k].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], x+y);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		LL ans = MAX;
		for (int i = 1; i <= totsta[u]; ++i)
			for (int j = 1; j <= totsta[v]; ++j) {
				if (dis[sta[u][i].first][sta[v][j].first] == MAX)
					continue;
				ans = min(ans, sta[u][i].second + sta[v][j].second + dis[sta[u][i].first][sta[v][j].first] + cost[u] + cost[v]);
			}
		printf("%lld\n", ans);
	}
	return 0;
}
