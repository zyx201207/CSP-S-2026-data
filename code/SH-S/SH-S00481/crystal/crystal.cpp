#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500001], c[500001], m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = c[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i + 1;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (a[i] * mid - (c[i] - c[i - mid]) <= m)
				l = mid;
			else
				r = mid;
		}
		ans = max(ans, l);
	}
	printf("%d\n", ans);
}
