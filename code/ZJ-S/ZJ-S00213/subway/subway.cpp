#include <bits/stdc++.h> 
using namespace std;
const int M = 5e5 + 5, N = 505;
int w[M], k[N], a[N][M], t[N][M], x[M], y[M];
int c, n, m, d, q;
int main() {
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", w+i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", k+i);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", x+i, y+i);
	}
	
	return 0;
}
