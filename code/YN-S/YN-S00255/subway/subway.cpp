#include <bits/stdc++.h>
using namespace std;
const int maxn = 550;
int c, n, m, d, q;
int w[maxn], subway[maxn][maxn];

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	int k;
	scanf("%d", &k);
	int T ;
	for (int i = 1; i <= k; i++) {
		int a, t;
		scanf("%d %d", &a, &t);
		subway[i][a] = t;
		T = t;
	}
	for (int i = 1; i <= r; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", T);
	}

	return 0;
}