#include <iostream>
using namespace std;

const int M = 5e5 + 10, D = 25, Q = 1e5 + 10;
int c, n, m, d, q, k;
int t[M];
struct yyq {
	int a;
	int b;
} y[D], p[Q];

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &t[i]);
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &k);
//		for (int j = 1; j <= k; ++k)
//			scanf("%d %d", &y[j].a, &y[j].b);
//	}
//	for (int i = 1; i <= q; ++i)
//		scanf("%d %d", &p[i].a, &p[i].b);

	for (int i = 1; i <= q; ++i)
		printf("%d ", t[c + i]*t[n + i]);

	return 0;
}