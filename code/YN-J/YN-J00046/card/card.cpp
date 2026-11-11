#include <bits/stdc++.h>
using namespace std;
int c[500005], d[300005], f[300005], n, m, k, ans[300005], l;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int t = 1; t <= n; t++) {
		l = 0;
		for (int i = t; i <= n; i++) {
			k = c[i];
			if (f[k] && f[k] < l) {
				l = f[k];
			} else {
				l++;
				if (f[d[l]] >= l) {
					f[d[l]] = 0;
				}
				d[l] = k;
				f[k] = l;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (f[i] <= l && f[i]) {
				ans[i]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}