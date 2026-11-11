#include <bits/stdc++.h>
using namespace std;
const long long N = 1;
long long ans = 1, b[500010];
long long n, m, a[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2 ; i <= n; i++) {
		if (a[i] - a[i - 1] <= m) {
			int op = i - 1, x = 1;
			b[op] = max(b[op], N);
			while (b[op] >= 1 && (x - 1) * (a[i] - a[i - 1]) <= m && op >= 1) {
				x++;
				op--;
			}
			if (x > ans) {
				ans = x;
				m -= x * (a[i] - a[op]);
				b[op] = 1;
				op++;
				x--;
				while (x >= 1) {
					b[op] = b[op - 1] + 1;
					a[op] = a[i];
					op++;
					x--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}