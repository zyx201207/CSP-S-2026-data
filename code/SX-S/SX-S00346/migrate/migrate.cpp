#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int c, t, n, d, x[N], ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("megrate.ans", "w", stdout);
	scanf("%d %d", &c, &t);
	while (t--) {
		ans = 0;
		scanf("%d %d", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x[i]);
		}
		int a = x[2] - x[1], s = 0, i = 1;
		if (d <= a) {
			printf("0\n");
			continue;
		}
		for (; s < d; i++) {
			s += a;
		}
		for (int j = 1; j + i <= n; j++) {
			ans += 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}