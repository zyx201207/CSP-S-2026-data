#include <bits/stdc++.h>
using namespace std;
long long m, a[500010], d[500010], n, c[500010], t, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		d[i] = d[i - 1] + a[i];
	c[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = c[i] + 1; j <= n; j++) {
			t = j - i;
			if (a[j]*t - (d[j - 1] - d[i - 1]) <= m) {
				ans =  max(ans, t + 1);
			}

			else {
				c[i + 1] = j;
				break;
			}
		}
		if (c[i + 1] == n)
			break;
	}

	printf("%lld", ans);
	return 0;
}
