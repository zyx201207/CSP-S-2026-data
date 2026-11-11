#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;
const int N = 2e6 + 10;
int c, T, n, lft[N];
ll d, arr[N];
ll dis[5005][5005], dp[5005][5005];
ll mind[5005 * 4], sum[5005];
ll posl[5005], posr[5005];
inline void solve() {
	scanf("%d %lld", &n, &d);
	int pos = 1;
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &arr[i]);
		while (pos < i && arr[i] - arr[pos] > d) pos ++;
		lft[i] = pos;
	}
	ll ans = 0;
	for (int st = 1; st <= n; st ++) {
		//cerr << "st: " << st << "\n";
		dis[st][st] = 0;
		dp[st][st] = 1;
		for (int i = 0; i <= n; i ++)
			posl[i] = 0, posr[i] = 0;
		posl[0] = st; posr[0] = st;
		sum[st] = 1;
		sum[st - 1] = 0;
		//printf("st: %d\n", st);
		for (int i = st + 1; i <= n; i ++) {
			//cerr << "i: " << i << "\n";
			//printf("i: %d\n", i);
			dis[st][i] = inf;
			dp[st][i] = 0;
			sum[i] = sum[i - 1];
			if (lft[i] > i - 1) continue;
			dis[st][i] = dis[st][max(st, lft[i])] + 1;
			if (dis[st][i] > inf) continue;
			if (!posl[dis[st][i]]) {
				posl[dis[st][i]] = i;
				posr[dis[st][i]] = i;
			} else {
				posr[dis[st][i]] = i;
			}
			ll L = max(posl[dis[st][i] - 1], (ll)max(lft[i], st));
			ll R = min(posr[dis[st][i] - 1], (ll)i - 1);
			if (L <= R)
				dp[st][i] = sum[R] - sum[L - 1];
			if (dp[st][i] == 2) {
				ans ++;
			}
			sum[i] += dp[st][i];
		}
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d %d", &c, &T);
	while (T--) solve();
	return 0;
}
