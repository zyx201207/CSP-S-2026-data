#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * y;
}
const int N = 2e6 + 7;
ll x[N], d, c, t, n;
ll l[N][2], r[N][2];
ll sl[N], sr[N], dl[N], dr[N];
void solve() {
	n = read(); d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	int rx = 1;
	for (int i = 1; i <= n; i++) {
		while (x[rx] - x[i] <= d && rx <= n) rx++;
		rx--;
		r[i][0] = rx, r[i][1] = max(i, rx - 1);
	}
    int lx = n;
	for (int i = n; i >= 1; i--) {
		while (x[i] - x[lx] <= d && lx >= 1) lx--;
		lx++;
		l[i][0] = lx, l[i][1] = min(i, lx + 1);
	}                               	
//	for (int i = 1; i <= n; i++) {
//		printf("i : %d l[0] : %lld l[1] : %lld r[0] : %lld r[1] : %lld\n", i, l[i][0], l[i][1], r[i][0], r[i][1]);
//	}
	for (int i = 1; i <= n; i++) {
		dl[i] = 0;
		if (l[i][0] == i - 1 && r[i - 1][0] == i)
			dl[i] += dl[i - 1] + 1;
//		printf("%lld ", dl[i]);
	}
//	puts("");
	for (int i = n; i >= 1; i--) {
		dr[i] = 0;
		if (r[i][0] == i + 1 && r[i + 1][0] == i)
			dl[i] += dl[i + 1] + 1;
	}
//	for (int i = 1; i <= n; i++) printf("%lld ", dr[i]);
//	puts("");
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (r[i][1] != i) {
			ll tmp = r[r[i][1]][0];
			while (l[tmp][0] == r[i][1] && tmp >= 1) {
				ans += (dl[i] + 1) * (dr[tmp] + 1), tmp--;
//				printf("(%d, %d) + (%d) * (%d)\n", i, tmp + 1, dl[i], dr[tmp + 1]);
			}
				
		}
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(); t = read();
	while (t--) solve();
	return 0;
}