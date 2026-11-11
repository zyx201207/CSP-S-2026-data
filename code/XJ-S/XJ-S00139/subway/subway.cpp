#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, q;
ll w[514514];
ll d[514][514];
vector <pair<int, ll>> s[514514];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	//input
	scanf("%d%d%d%d%d", &n, &n, &m, &q, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1, k, x, y; i <= n; i++) {
		scanf("%d", &k);
		for (; k--; )
			scanf("%d%d", &x, &y),
			s[x].push_back({i, y});
	}

	//search shortist
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= n; j++)
	        d[i][j] = 1e12;
	for (int i = 1; i <= n; i++)
		d[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (auto &x : s[i])
			for (auto &y : s[i])
				d[x.first][y.first] = d[y.first][x.first] = min(d[x.first][y.first], 0LL + x.second + y.second);
    
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
	            d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);

	for (int x, y; q--; ) {
		scanf("%d%d", &x, &y);

		ll ans = 1e18;
		for (auto &i : s[x])
			for (auto &j : s[y])
			    if (d[i.first][j.first] + i.second + j.second < 1e12)
				    ans = min(ans, d[i.first][j.first] + i.second + j.second);

		printf("%lld\n", ans + w[x] + w[y]);
	}
//    for (int i = 1; i <= n; i++) {
//    	for (int j = 1; j <= n; j++)
//    	    printf("%d ", d[i][j]);
//    	printf("\n");
//	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
