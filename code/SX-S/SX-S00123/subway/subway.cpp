#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+5, C = 2e1+5 + 5, K = 5e5+5, M = K, D = 2e1+5, Q = 1e5+5;
int c, n, m, d, q, ans, a[N][K], w[M], t[N][K];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", w + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", t[i]);
		for (int j = 1; j <= *t[i]; j++) {
			scanf("%d%d", a[i] + j, t[i] + j);
		}
	}
	for (int i = 1; i <= q; i++) {
		int start, end;
		scanf("%d%d", &start, &end);
		printf("%d\n", t[i][i]);
	}
	return 0;
}