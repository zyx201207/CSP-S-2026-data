#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 510, M = 5e5 + 10;

struct edge{
	int p, cd;
};

vector<edge> x[M];
int c, n, m, d, q, op, st, en, cst, len, w[M], f[N][N];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &len);
		for (int j = 1; j <= len; j++){
			scanf("%lld %lld", &op, &cst);
			x[op].push_back(edge{i, cst});
		}
	}
	for (register int i = 1; i < N; ++i)
		for (register int j = 1; j < N; ++j)
			if (i != j) f[i][j] = 3e18;
	for (int i = 1; i <= m; i++)
		for (edge u : x[i])
			for (edge v : x[i])
				if (f[u.p][v.p] > u.cd + v.cd) f[v.p][u.p] = f[u.p][v.p] = u.cd + v.cd;
	for (register int k = 1; k <= n; ++k)
		for (register int i = 1; i <= n; ++i)
			for (register int j = 1; j <= n; ++j)
				if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
	for (int i = 1; i <= q; i++){
		scanf("%lld %lld", &st, &en);
		int ans = 3e18;
		for (edge u : x[st])
			for (edge v : x[en])
				ans = min(ans, f[u.p][v.p] + u.cd + v.cd);
		printf("%lld\n", ans + w[st] + w[en]);
	}
	return 0;
}