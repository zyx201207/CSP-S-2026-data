#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000010], ans = 0, ways = 0, minn = LLONG_MAX;

void check(long long fr, long long to, long long dist) {
	if (fr == to) {
		if (dist < minn)
			ways = 1, minn = dist;
		else if (dist == minn)
			ways++;
		return;
	}
	for (int i = fr + 1; i <= to; i++) {
		if (x[i] - x[fr] > d)
			break;
		check(i, to, dist + 1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		ans = 0;
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (x[i + 1] - x[i] > d)
				continue;
			for (int j = i + 3; j <= n; j++) {
				ways = 0, minn = LLONG_MAX;
				check(i, j, 0);
				if (ways == 2) {
					ans++;
				}

			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
