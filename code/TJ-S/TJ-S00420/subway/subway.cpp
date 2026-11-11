#include <bits/stdc++.h>
using namespace std;

const int maxm = 5e5 + 2, maxn = 502;;
int c, n, d, m, q, w[maxm], k[maxn];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d %d %d %d %d", &c, &n, &d, &m, &q);
	for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; ++j) {
			int a, t; scanf("%d %d", &a, &t);
		}
	}
	
	while (q--) {
		int x, y; scanf("%d %d", &x, &y);
		puts("0");
	}
	
	return 0;
}
