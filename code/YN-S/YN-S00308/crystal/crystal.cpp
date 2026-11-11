#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int maxn = 1e6;
ull  maxx, cf[maxn], m, m1, v, num, dp[maxn];
ll  n,  yuan[maxn];

ull fin(ll startt) {
	ull v = 0, RE = 0;
	ll yuaan = startt;
	ull cnt = 0;
	while (1) {
		if (cf[startt - 1] + v + RE <= m && startt > 0) {
			RE = RE + cf[startt - 1];
			v += RE;
			cnt++;
			startt--;
		} else {
			break;
		}

	}
	dp[yuaan] = cnt;
	return v;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	m1 = m;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &yuan[i]);
	}
	sort(yuan + 1, yuan + n + 1);
	for (ll i = 1; i <= n - 1; i++) {
		cf[i] = yuan[i + 1] - yuan[i];

	}
//======================================================================
	for (ll i = 2; i <= n; i++) {
		if (((v  + (dp[i - 1]*cf[i - 1])) <= m) && dp[i - 1]) {
			dp[i] = dp[i - 1] + 1;
			v += (dp[i - 1] * cf[i - 1]);
		} else {
			v = fin(i);
		}

		maxx = max(maxx, dp[i] + 1);

	}
//============================================================================
//	for (int i = 1; i <= n; i++) {
//		printf("%lld ", cf[i]);
//	}
	if (maxx <= 1) {
		cout << 0;
		return 0;
	}
	cout << maxx;
	return 0;
}