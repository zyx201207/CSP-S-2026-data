#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2001000;
int c, n, lst[N];
ll d, x[N];

inline void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", &x[i]);
	if (c <= 6) {
		for (int i = 1; i <= n; i++) {
			int l = i - 1, r = n + 1;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				if (x[m] - x[i] <= d) 
					l = m;
				else 
					r = m;
			}
			lst[i] = l;
		}
		ll ans = 0;
		for (int l = 1; l <= n; l++) {
			for (int r = l + 1; r <= n; r++) {
				bool ok = 0;
				int skip = 0;
				for (int i = l; i < r; ) {
					if (i == lst[i]) {
						ok = 0;
						break;
					}
					if (skip && lst[i - 1] >= min(r, lst[i]) && lst[i - 2] < min(r, lst[i])) {
						if (ok) {
							ok = 0;
							break;
						}
						ok = 1;
					}
					skip = lst[i] - i - 1;
					i = lst[i];
				}
				ans += ok;
			}
		}
		printf("%lld\n", ans);
	} else {
		int l = 0, r = n + 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (x[m] - x[1] <= d) 
				l = m;
			else 
				r = m;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (l > 2 && n - i >= 2 * (l - 1) - 1) 
				ans++;
		}
		printf("%d\n", ans);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	scanf("%d%d", &c, &t);
	while (t--) {
		solve();
	}
}

