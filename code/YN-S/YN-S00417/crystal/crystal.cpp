#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], res;

inline int read() {
	int f = 1, r = 0;
	char c;
	c = getchar();
	while (c < '0' || c > '9')
		f = -1, c = getchar();
	while (c >= '0' && c <= '9')
		r = r * 10 + c - '0', c = getchar();
	return f * r;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n);
	int l = 1, tot = 0, res = 1;
	for (int i = 2; i <= n; i++) {
		while (tot + (a[i] - a[i - 1]) * (i - l) > m) {
			tot -= a[i - 1] - a[l];
			l++;
		}
		tot += (a[i] - a[i - 1]) * (i - l);
		res = max(res, i - l + 1);
	}
	cout << res;
	return 0;
}