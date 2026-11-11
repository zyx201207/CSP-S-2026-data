#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 505, M = 5e5+5;

int __c, n, m, d, q;
int w[M];
vector<pair<int, int>> to[M];
vector<pair<int, int>> from[N];
ll dist[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &__c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%d", w+i);
	for (int i = 1; i <= n; i++) {
		int K;
		scanf("%d", &K);
		for (int j = 1; j <= K; j++) {
			int a, t;
			scanf("%d%d", &a, &t);
			to[a].push_back({i, t});
			from[i].push_back({a, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			dist[i][j] = dist[j][i] = 5000000000000000;
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (auto x : from[i])
			for (auto y : to[x.first])
				dist[i][y.first] = dist[y.first][i] = min(dist[i][y.first], (ll)x.second+y.second);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
	int x, y;
	ll ans;
	while (q--) {
		scanf("%d%d", &x, &y);
		ans = LLONG_MAX;
		for (auto i : to[x])
			for (auto j : to[y])
				ans = min(ans, dist[i.first][j.first]+i.second+j.second);
		printf("%lld\n", ans+w[x]+w[y]);
	}
}