#include <bits/stdc++.h>
using namespace std;
int n, m, c[500010], a[500010], b[500010], ma = -1;

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[j] = 0;
			b[j] = 0;
		}
		for (int j = 1; j <= n; j++) {
			a[j] = c[j] - c[i];
			b[j] = a[j] + b[j - 1] + c[j - 1];
		}
		int r = n, l = 1, mid = (l + r) / 2;
		while (l < r) {
			mid = (l + r) / 2;
			if (b[mid] > m) {
				r = mid;
			}
			if (b[mid] <= m) {
				l = mid + 1;
			}

		}
		int sl = r - i + 1;
		ma = max(ma, sl);
	}
	printf("%d", ma);
	return 0;
}