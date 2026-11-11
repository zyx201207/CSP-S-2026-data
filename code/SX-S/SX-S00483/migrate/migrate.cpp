#include <bits/stdc++.h>
using namespace std;
int c, t, n, x[2000010], s, a, ans, b;
long long d;
bool f[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (--t) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		if (x[n] - x[1] <= d || n < 4) {
			printf("0\n");
			continue;
		}
		if (c == 11 || c == 12) {
			s = x[2] - x[1];
			a = d / s;
			b = a * 2 - 1;
			ans = n - b;
			printf("%d", ans);
		}
	}
	return 0;
}