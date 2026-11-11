#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5005, inf = 1e18;
ll c, t, n, d;
ll a[N], nxt[N], dis[N][N], cnt_1[N];
inline void read(ll &x) {
	x = 0;
	char ch = getchar();
	bool q = 0;
	while (!isdigit(ch)) {
		if (ch == '-') q = 1;
		ch = getchar();
	}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	if (q) x = -x;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(c), read(t);
	while (t--) {
		read(n), read(d);
		if (c <= 10) {
			for (ll i = 1; i <= n; i++) read(a[i]);
			for (ll i = 1; i <= n; i++) {
				dis[i][i] = 0;
				for (ll j = i + 1; j <= n; j++) {
					dis[i][j] = inf;
				}
			}
			ll l = n - 1, r = n;
			nxt[n] = n;
			while (l >= 1) {
				if (a[r] - a[l] <= d) nxt[l--] = r;
				else r--;
			}
			for (ll i = 1; i <= n; i++) {
				ll temp = i, cnt = 0;
				for (ll j = i + 1; j <= n;) {
					if (temp >= j) dis[i][j++] = cnt;
					else {
						if (temp != nxt[temp]) temp = nxt[temp];
						else break;
						cnt++;
					}
				}
			}
			ll res = 0;
			for (ll j = n; j >= 4; j--) {
				for (ll i = 1; i <= n; i++) cnt_1[i] = 0;
				if (dis[j - 2][j] > n) continue;
				cnt_1[dis[j - 1][j]]++, cnt_1[dis[j - 2][j]]++;
				ll bj = j - 1;
				for (ll i = j - 3; i >= 1; i--) {
					if (dis[i][j] > n) break;
					while (bj && a[i] + d < a[bj]) cnt_1[dis[bj--][j]]--;
					res += (cnt_1[dis[i][j] - 1] == 2);
					cnt_1[dis[i][j]]++;
				}
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}