#include <cstdio>
#include <algorithm>
using namespace std;
int c, n, m, d, q, x, y;
int w[5005];
int k[5005];
int a[505][5005];
long long t[505][5005];
long long f[5005][5005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) f[i][j] = 1e18;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) scanf("%lld%lld", &a[i][j], &t[i][j]);
		for (int j = 2; j <= k[i]; j++) {
			for (int v = 1; v < j; v++) {
				f[a[i][j]][a[i][v]] = f[a[i][v]][a[i][j]] = min(f[a[i][j]][a[i][v]], t[i][j] + t[i][v]);
			}
		}
	}
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while (q--) {
		scanf("%d%d", &x, &y);
		printf("%lld\n", f[x][y] + w[x] + w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}