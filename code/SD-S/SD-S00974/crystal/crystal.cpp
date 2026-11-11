#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

const int N = 500005; 

int n, m, a[N], p[N];

void rd(int &a, int c = 0, int f = 0) {
	while (!isdigit(c = getchar())) f |= c == '-';
	for (a = 0; isdigit(c); c = getchar()) a = (a << 3) + (a << 1) + (c ^ 48);
	f && (a = -a);
}
void wrt(int x) {
	if (x > 9) wrt(x / 10);
	putchar(x % 10 ^ 48);
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	rd(n), rd(m);
	rep(i, 1, n) rd(a[i]);
	sort(a + 1, a + n + 1);
	rep(i, 1, n) p[i] = p[i - 1] + a[i];
	int ans = 1;
	rep(i, 1, n) {
		while (ans < i && a[i] * (ans + 1) - (p[i] - p[i - ans - 1]) <= m) ans++;
	}
	wrt(ans);
}
/*
5 5
1 2 4 8 9
*/
