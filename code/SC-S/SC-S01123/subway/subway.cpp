#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int maxn = 5e5 + 1000, maxq = 1e5 + 10;
vector <PII> e[maxn];
PII que[maxq];
long long dis[maxn], d[510][510], w[maxn];
bool vis[maxn];
int n, m, k, Q;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, D;
	scanf("%d%d%d%d%d", &c, &n, &m, &D, &Q);
	for (int i = 1; i <= m; i++) scanf("%lld", w + i);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int a, t;
			scanf("%d%d", &a, &t);
			e[m + i].push_back({a, t});
			e[a].push_back({m + i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (i != j) d[i][j] = 1e18;
	for (int i = 1; i <= m; i++)
		for (auto j : e[i])
			for (auto k : e[i])
				d[j.first - m][k.first - m] = min(d[j.first - m][k.first - m], 1ll * j.second + k.second);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	for (int i = 1; i <= Q; i++) {
		long long ans = 1e18;
		int s, t;
		scanf("%d%d", &s, &t);
		for (auto j : e[s])
			for (auto k : e[t])
				ans = min(ans, d[j.first - m][k.first - m] + j.second + k.second + w[s] + w[t]);
		printf("%lld\n", ans);
	}
	return 0;
}