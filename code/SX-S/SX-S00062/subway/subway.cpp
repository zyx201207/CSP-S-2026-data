#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[50002];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int a, b;
	for (int i = 1; i <= m; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d);
		for (int j = 1; j <= d; j++) {
			scanf("%d", &a, &b);
		}
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d", &m, &n);
		printf("%d/n", w[m] + w[n] + 2 * b);
	}
	return 0;
}//T2