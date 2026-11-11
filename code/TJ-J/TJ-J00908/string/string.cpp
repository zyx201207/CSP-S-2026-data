#include <bits/stdc++.h>
#define int long long
using namespace std;
char c;
string s;
int n, a, g;
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
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	while (n--) {
		a = read();
		c = getchar();
		while (a--)
			s += c;
	}
	for (int l = 0, r = (int)(s.size()) - 1; l <= r; l++, r--)
		if (s[l] != s[r])		
			g++;
	write(g);
	return 0;
}
