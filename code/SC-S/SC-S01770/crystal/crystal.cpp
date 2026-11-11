#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

inline ll read() {
	ll w = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
	return f * w;
}

inline void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x < 10) {
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int N = 5e5 + 5;

ll n, m;
ll a[N], sum[N];
ll ans = 1;

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1;i <= n; ++i) a[i] = read();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	for (ll l = 1, r = 2; r <= n; ++r) {
		while ((r - l + 1) * a[r] - sum[r] + sum[l - 1] > m) ++l;
		ans = max(ans, r - l + 1);
	}
	write(ans);
	return 0;
}