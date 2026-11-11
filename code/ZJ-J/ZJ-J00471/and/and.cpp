#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200010];

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int ma = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ma = max(ma, a[i]);
	}
	if (m == 1) {
		printf("%d\n", ma);
	} else if (m == 2) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[i] & a[j] > ans) {
					ans = a[i] & a[j];
				}
			}
		}
		printf("%d\n", ans);
	} else if (m == n) {
		int p = a[1];
		for (int i = 2; i <= n; i++) {
			p &= a[i];
		}
		printf("%d\n", p);
	} else {
		sort(a + 1, a + n + 1, cmp);
		printf("%d\n", a[m]);
	}
	return 0;
}
