#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int n, m, a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	int cnt = 1, sum = 0, ans = 1;
	for (int i = 2; i <= n; ++i) {
		sum += cnt * (a[i] - a[i - 1]);
		++cnt;
		while (sum > m) {
			cnt--;
			sum -= (a[i] - a[i - cnt]);
		}
		ans = max(ans, cnt);
	}
	printf("%lld\n", ans);
	return 0;
}