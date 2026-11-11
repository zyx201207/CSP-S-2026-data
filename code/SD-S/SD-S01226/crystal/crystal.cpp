#include <bits/stdc++.h>
using namespace std;

#define il inline
#define ri register int
#define ll long long
#define inf 0x3f3f3f3f
il ll read();
const int N = 500005;

int n;
ll m, z[N], sum, ans;
ll q[N], f, e;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for (ri i=1; i<=n; i++) {
		z[i] = read();
	}
	sort(z + 1, z + n + 1);
	f = 1;
	q[++e] = z[1];
	ans = 1;
	for (ri i=2; i<=n; i++) {
		sum += (z[i] - q[e]) * (e - f + 1);
		while (sum > m && f <= e) {
			sum -= (z[i] - q[f]);
			f++;
		}
		q[++e] = z[i];
		ans = max(ans, e - f + 1);
	}
	cout << ans;
	return 0;
}
il ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
