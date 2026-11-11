#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
const int N = 5e5 + 5;
int n, m, ans, cnt, st = 1;
int a[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; ++i) {
		cnt += (a[i] - a[i - 1]) * (i - st);
		while (cnt > m && st < i) {
			cnt -= a[i] - a[st];
			st ++;
		}
		ans = max(ans, i - st + 1);
	}
	printf("%lld\n", ans);
	return 0;
}