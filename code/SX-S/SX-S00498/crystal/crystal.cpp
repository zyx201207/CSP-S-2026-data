#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n, m, st = 0, dt = 0, ans = 1, j = 1, ding, k = 1, p, q;
ull a[500010], b[500010], c[500010], d[500010], g[500010];

int cmp(ull x, ull y) {
	return x < y;
}

void crystal() {
	for (ull i = 1; i <= j; ++i) {
		b[i] -= p;
		if (b[i] == d[k]) {
			q = i;
			ans = c[i];
			break;
		}
	}
	while (st <= m) {
		q--;
		dt = -1 * b[q];
		if (st + dt  <= m && st + dt * c[q] <= m) {
			st += dt * c[q];
			ans += c[q];
		} else if (dt <= m && dt * c[q] > m) {
			ans += (m - st) / dt;
			break;
		} else
			break;
	}

}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	cin >> n >> m;
	for (ull i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	b[1] = a[1];
	c[1] = 1;
	for (ull i = 2; i <= n; ++i) {
		if (a[i] == b[j])
			c[j]++;
		else {
			j++;
			b[j] = a[i];
			c[j] = 1;
		}
	}
	if (c[1] == n) {
		cout << n << '\n';
		return 0;
	}
	ding = c[1];
	d[1] = b[1];
	for (ull i = 2; i <= j ; ++i) {
		if (c[i] == ding) {
			k++;
			d[k] = b[i];
		} else if (c[i] > ding) {
			ding = c[i];
			memset(d, 0, sizeof d);
			k = 1;
			d[k] = b[i];
		}
	}
	if (k == 1) {
		p = d[k];
		crystal();
	}
	cout << ans << '\n';
	return 0;
}
