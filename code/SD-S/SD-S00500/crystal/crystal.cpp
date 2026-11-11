#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500010], qzh[500010], j = 1, rem, ans = 1;

bool cmp(int &x1, int &x2) {
	return x1 > x2;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	rem = m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 2; i <= n; i++) {
		a[i] = a[1] - a[i];
	}
	a[1] = 0;
	rem = m;
	for (int i = 1; i <= n, j <= n; i++) {
		rem += (j - i) * (a[i] - a[i - 1]);
		for (; rem - (a[j] - a[i]) >= 0 && j <= n; j++) {
			rem -= a[j] - a[i];
		}
		ans = max(ans, j - i);
	}
	printf("%lld", ans);
}
