#include <bits/stdc++.h>
#define int unsigned long long 
using namespace std;
int n, m, r, a[200005];
inline int read() {
	char c;
	int x = 0, f = 1;
	c = getchar();
	for (; c < '0' || '9' < c; c = getchar())
		if (c == '-')
			f = -1;
	for (; '0' <= c && c <= '9'; c = getchar())
		x = ((x << 1) + (x << 3) + (c ^ '0'));
	return x * f;
}
inline void write(int x) {
	if (x < 0)
		putchar('-'),
		x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ '0'); 
}
inline bool cmp(int a, int b) {
	return (a & b) > (b & a);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1, cmp);
	r = a[n];
	for (int i = n - 1; i > (n - m); i--)
		r &= a[i];
	write(r);
	return 0;
}
