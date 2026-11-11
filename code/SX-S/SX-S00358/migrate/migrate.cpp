#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000010], cha, ans;
bool isa = true;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &d);
		isa = true;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (i == 2)
				cha = a[i] - a[i - 1];
			if (a[i] - a[i - 1] != cha && i > 2)
				isa = false;
		}
		if (isa == true) {
			if (d < cha) {
				printf("0\n");
			} else {
				int dl = d / cha;
				for (int i = 1; i <= n; i++) {
					for (int j = i + 1; j <= n; j++) {
						if ((j - i) / dl == 2)
							ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}