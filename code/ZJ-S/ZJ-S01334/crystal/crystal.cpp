#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 10;

int n, m, a[N], b[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		b[i] = b[i - 1] + a[i];
	int pos = 1, ans = 1;
	for (int i = 2; i <= n; ++i) {
		while(a[i] * (i - pos + 1) - b[i] + b[pos - 1] > m) ++pos;
		ans = max(ans, i - pos + 1);
	}
	printf("%lld", ans);
	return 0;
}
