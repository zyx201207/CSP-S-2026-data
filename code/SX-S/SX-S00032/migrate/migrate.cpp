#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
ll inf = 1e18;
ll c, t;
ll n, d;
ll a[N];
ll dp[N];
ll smin;//最小值出现次数
ll mi = inf;
ll ans = 0;

void init() {
	for (int i = 1; i <= n; i++) {
		dp[i] = inf;
	}
	ans = 0;
	mi = inf;
}

void dpp(ll u, ll v) {
	dp[u] = 0;
	for (int i = u + 1; i <= v; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = i - 2; j >= u; j--) {
			if (a[i] - a[j] <= d) {
				dp[i] = min(dp[i], dp[j] + 1);
				if (dp[i] < mi) {
					mi = dp[i];
					smin = 1;
				} else if (dp[i] == mi) {
					smin++;
				}
			}
		}
	}
	if (smin == 2)
		ans++;

}

//void solve1() {
//	ll sum = 0;
//	ll dd = a[n] - a[n - 1];
//	ll o = d / dd;
//	for (int i = n - 1; i >= o; i--) {
//		sum += dd * i;
//	}
//	cout << sum;
//}

void solve() {
	cin >> n >> d;
	init();
	bool flaggg = true;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (i >= 3) {
			if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				flaggg = false;
			}
		}
	}
//	if (flaggg) {
//		solve1();
//	} else {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dpp(i, j);
		}
	}
//	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		solve();
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}