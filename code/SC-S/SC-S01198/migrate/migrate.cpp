#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL maxn = 2e6 + 5;
LL c, T, len, n, d, a[maxn], x[maxn], ans = 0;
LL vis[maxn], pre[maxn], nxt[maxn], cnt[maxn];
void solve() {
	for (LL l = 1; l <= n; l++) {
		for (LL i = 1; i <= n; i++)
			vis[i] = pre[i] = nxt[i] = cnt[i] = 0;
		vis[l] = 1; LL lst = l;
		for (LL i = l + 1; i <= n; i++)
			if (x[i] - x[lst] > d)
				vis[i - 1] = 1, lst = i - 1;
		for (LL i = l, now = 0; i <= n; i++) {
			if (vis[i]) now = i;
			pre[i] = now;
		}
		for (LL i = n, now = 0; i >= l; i--) {
			if (vis[i]) now = i;
			nxt[i] = now;
		}
		for (LL i = l; i <= n; i++) {
			if (vis[i] || nxt[nxt[i] + 1] == 0) continue;
			if (x[nxt[nxt[i] + 1]] - x[i] <= d) cnt[i]++;
		}
		for (LL i = l; i <= n; i++)
			cnt[i] += cnt[i - 1];
		for (LL i = l; i <= n; i++) {
			if (vis[i])
				ans += (cnt[pre[i - 1]] == 1);
			else {
				if (pre[pre[i] - 1] == 0) continue;
				LL tot = cnt[pre[pre[i] - 1]];
				for (LL j = pre[pre[i] - 1] + 1; j < pre[i]; j++)
					tot += ((x[i] - x[j]) <= d);
				ans += (tot == 1);
			}
		}
	}
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> len >> d;
		for (LL i = 1; i <= len; i++)
			cin >> a[i];
		n = ans = 0;
		for (LL i = 1; i <= len; i++) {
			if (a[i] - x[n] > d) {
				solve();
				n = 0;
			}
			x[++n] = a[i];
		}
		if (n) solve();
		cout << ans << '\n';
	}
	return 0;
}