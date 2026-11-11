#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[20005], k[505], s, e;

struct aandt {
	int a;
	long long t;
} at[505][20005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%lld", &at[i][j].a, &at[i][j].t);
		}
	}
	while (q--) {
		long long ans = 0;
		scanf("%d%d", &s, &e);
		ans += (w[s] + w[e]);
		int x, y;
		for (int i = 1; i <= n; i++) {
			bool flag1 = 0, flag2 = 0;
			for (int j = 1; j <= k[i]; j++) {
				if (s == at[i][j].a) {
					flag1 = 1;
				}
				if (flag1) {
					ans += at[i][j].a;
				}
				if (e == at[i][j].a) {
					flag2 = 1;
				}
				if (flag2) {
					printf("%d\n", ans);
					break;
				}
			}
			if (flag2)
				break;
		}
	}
	return 0;
}
