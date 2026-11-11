#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5010, INF = 0x3f3f3f3f3f3f3f3f;

int sm, T, n, d, x[N], ans, f[N], c[N];

void solve() {
	ans = 0;
	scanf("%lld %lld", &n, &d);
	for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++i) {
		f[i] = 0, c[i] = 1;
		int l = i, r = i + 1, cnt = 1;
		for (int j = i + 1; j <= n; ++j) {
			while(x[j] - x[l] > d) cnt -= c[l++];
			while(r < j && f[r] <= f[l]) cnt += c[r++];
			f[j] = f[l] + 1, c[j] = cnt;
			if(cnt == 2) ++ans;
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &sm, &T);
	while(T--) solve();
	return 0;
}
