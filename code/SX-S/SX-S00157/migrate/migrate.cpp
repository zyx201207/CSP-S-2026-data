#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, b, x[6000000], a;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	scanf("%d%d", &c, &t);
	while (t > 0) {
		t--;
		scanf("%d%lld", &n, &d);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &b);
			x[i] = b;
		}
		b = x[1] - x[0];
		if ((2 * b ) > d) {
			printf("%d\n", 0);
		} else {
			if ((2 * b ) <= d && (3 * b ) > d) {
				if ((n - 3) < 0)
					printf("%d\n", 0);
				else
					printf("%d\n", n - 3);
			} else {
				a = d / b;
				if (( n - 2 * a + 1) < 0)
					printf("%d\n", 0);
				else
					printf("%lld\n", n - 2 * a + 1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
