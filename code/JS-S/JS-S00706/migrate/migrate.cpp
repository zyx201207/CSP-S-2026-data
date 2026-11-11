#include <bits/stdc++.h>
using namespace std;

#define ll long long

int L[2000005];
ll a[2000005], d[2000005], f[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	while (t--) {
		int n;
		ll m;
		scanf("%d %lld", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			for (int j = 1; j <= i; j++) {
				if (a[i] - a[j] <= m) {
					L[i] = j;
					break;
				}
			}
		}
		ll ans = 0;
		for (int i = n; i >= 1; i--) {
			d[i] = 0;
			f[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				int l = max(L[j], i);
				int r = l;
				while (r <= l + 2 && r < j && d[r] == d[l]) {
					r++;
				}
				r--;
				d[j] = d[l] + 1;
				f[j] = 0;
				for (int k = l; k <= r; k++) {
					f[j] += f[k];
				}
				f[j] = min(f[j], 3ll);
				if (f[j] == 2) {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
}