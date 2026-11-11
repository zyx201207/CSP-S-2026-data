#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n;
long long d, a[N];
inline long long read() {
	long long x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int main() {
//	freopen("migrate4.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while (t--) {
		n = read(), d = read();
//		cout << n << " " << d << "\n";
		long long c = 0, ans = 0;
		for (long long i = 1; i <= n; i++) a[i] = read(), c = a[i] - a[i - 1];
		for (long long i = 3; i <= n; i += 2) ans += (n - i) * (d >= (i + 1) / 2 * c && d < ((i + 1) / 2 + 1) * c);
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

我真不行了，这个数据范围是根本不想让人输入完吗。。。
O(tn) 的输入你给我 TLE 也是个人才
*/