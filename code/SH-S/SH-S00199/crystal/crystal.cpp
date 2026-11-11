#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5 + 10;
const __int128 INF = 2e18;
__int128 n, ans, m, a[maxN], pre[maxN];

inline __int128 read() {
	__int128 res = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	} 
	while (isdigit(c)) {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}
inline void write(__int128 res) {
	if (res < 0) {
		res = -res;
		putchar('-'); 
	} 
	if (res > 9) write(res / 10);
	putchar(res % 10 + '0');
}
bool check(__int128 siz) {
	__int128 minVal = INF;
	for (int i = siz; i <= n; i++) {
		__int128 cost = a[i] * siz - (pre[i] - pre[i - siz]);
		minVal = min(minVal, cost);
	}
	return minVal <= m;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	__int128 L = 1, R = n;
	while (L <= R) {
		__int128 mid = (L + R) / 2;
		if (check(mid)) {
			L = mid + 1;
			ans = mid;
		} else R = mid - 1;
	}
	write(ans);
	return 0;
} 
