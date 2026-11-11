#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long c, t, n, d, a, b, x, l[N], mid;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	if (c == 11 || c == 12) {
		for (int i = 1; i <= t; i++) {
			scanf("%lld%lld", &n, &d);
			if (n <= 2) {
				scanf("%lld", &x);
				printf("0\n");
				continue;
			}
			scanf("%lld%lld", &a, &b);
			for (int j = 3; j <= n; j++)
				scanf("%lld", &x);
			b -= a;
			d /= b;
			if (d <= 1) {
				printf("0\n");
				continue;
			}
			d = d * 2 - 1;
			printf("%lld\n", max(0 * 1ll, n - d));
		}
	} else if (c == 13 || c == 14) {
		for (int i = 1; i <= t; i++) {
			scanf("%lld%lld", &n, &d);
			if (n <= 2) {
				scanf("%lld", &x);
				printf("0\n");
				continue;
			}
			for (int j = 1; j <= n; j++) {
				scanf("%lld", l + i);
				if (l[i] - l[1] <= d)
					mid = i;
			}
			if (mid == n) {
				printf("0\n");
				continue;
			}
			a = 0;
			b = 0;
			for (int j = n; j > mid && l[j] - l[mid - 1] <= d && l[j] - l[mid - 2] > d; j--)
				a++;
			for (int j = 1; j < mid && l[mid + 1] - l[j] <= d && l[mid + 2] - l[j] > d; j--)
				b++;
			printf("%lld\n", a*(mid - 1) + b*(n - mid) - a *b);
		}
	}
	return 0;
}
//16:25:29
//先做3AB阴他一手
//阴间数据点击文档卡一年，是病毒吧！