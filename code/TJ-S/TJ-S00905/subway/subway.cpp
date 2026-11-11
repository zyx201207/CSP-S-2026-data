#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, k[20001], w[500001], a[501][20001], t[501][20001], p[100001][3];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
			scanf("%d", &a[k[i]][j]);
		for (int j = 1; j <= k[i]; j++)
			scanf("%d", &t[k[i]][j]);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &p[i][1], &p[i][2]);
	}
	return 0;
} 
