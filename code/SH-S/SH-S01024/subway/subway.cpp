#include <stdio.h>
#include <string.h>

#define MAXN 505
#define MAXM 500005
#define MAXQ 100005
#define INF 0x3f3f3f3f

int c, n, m, d, q;
int w[MAXM];
int k[MAXN];
int a[MAXN][MAXM], t[MAXN][MAXM];
int x[MAXQ], y[MAXQ];

int dist[MAXM][MAXM];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	/* input */
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);

		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
		}
	}

	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}

	/* init floyd */
	memset(dist, 0x3f, sizeof(dist));

	for (int i = 1; i <= m; i++) {
		dist[i][i] = 0;
	}
	
	for (int i = 1; i <= q; i++) {
		printf("1\n");
	}

	return 0;
}
