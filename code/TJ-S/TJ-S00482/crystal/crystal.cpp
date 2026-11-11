#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, t, x;
vector <int> v;
inline int read() {
	char c;
	int x = 0, f = 1;
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
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for (int i = 0; i < n; i++)
		t = read(),
		v.push_back(t);
	sort(v.begin(), v.end());
	for (int i = 0; i < (n - 1); i++)
		if (((((v[0] + v[i]) * (i + 1)) >> 1) + m) < (v[i + 1] * (i + 1))) {
			write(i + 1);
			return 0;
		}
	return 0;
}
