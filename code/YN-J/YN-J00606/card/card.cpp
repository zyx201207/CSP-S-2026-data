#include <bits/stdc++.h>
using namespace std;


int n, m, a[500005], p[500005] = {0}, r[300005] = {0}, b = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] != 0) {
				for (int l = 0; l <= n; l++) {
					if (a[j] == p[l]) {
						b++;
					}
				}
				if (b == 0) {
					p[j] = a[j];
				} else {
					for (int o = 0; o <= n; o++) {
						p[o] = 0;
					}
					p[j] = a[j];
				}
			}
			b = 0;
		}
		for (int h = 1; h <= m; h++) {
			for (int k = 0; k < n; k++) {
				if (p[k] == h) {
					r[h] += 1;
				}
			}
		}
		a[i] = 0;
		for (int q = 0; q <= n; q++) {
			p[q] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", r[i]);
	}

	return 0;
}