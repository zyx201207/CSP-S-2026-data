#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <map>
#define SIZE 500010
#define NODE 2010
#define INF 0x3f3f3f3f3f3f3f3fll
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
using ll = long long;
int c, n, m, d, q;
int k;
int u, v;
ll w[SIZE];
ll dp[NODE][NODE];
ll line[NODE][NODE];
ll t[NODE][NODE];
ll len[NODE];
ll N, M;
//void print() {
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf("%-10lld ", dp[i][j]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}
void Flody() {
	memset(dp, 0xf, sizeof(dp));

	for (int i = 1; i <= m; i++) dp[i][i] = 0;

	for (int p = 1; p <= n; p++) { //p -> 几号线
		for (int i = 1; i <= len[p]; i++) {
			for (int j = 1; j <= len[p]; j++) {
				dp[line[p][i]][line[p][j]] =
				    min(dp[line[p][i]][line[p][j]],
				        t[p][i] + t[p][j]);
			}
		}
	}
	for (int p = 1; p <= m; p++) { //p -> node
		for (int i = 1; i <= p; i++) {
			for (int j = i; j <= p; j++) {
				dp[i][p] = min(dp[i][p], dp[i][j] + dp[j][p]);
			}
			dp[p][i] = dp[i][p];
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%lld %lld", &line[i][j], &t[i][j]);
		}
		len[i] = k;
	}
	Flody();
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &u, &v);
		printf("%lld\n", w[u] + dp[u][v] + w[v]);
	}
}
/*
16:43
*/