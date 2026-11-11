#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char a = getchar();
	while (a < '0' || a > '9') {
		if (a == '-') f = -1;
		a = getchar();
	}
	while (a >= '0' && a <= '9') {
		x = x * 10 + a - '0';
		a = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 5e5 + 10;
int n, m;
int a[N], p[N];
bool check(int x) {
	for (int i = x; i <= n; ++i) {
		if (a[i] * x - (p[i] - p[i - x]) <= m) return true;
	}
	return false;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	int ans = 1;
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i];
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	write(ans);
	putchar('\n');
	return 0;
}
