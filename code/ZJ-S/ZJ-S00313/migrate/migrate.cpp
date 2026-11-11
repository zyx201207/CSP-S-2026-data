#include <bits/stdc++.h>
#define int long long
#define INF 1e18
using namespace std;

const int N = 2e6 + 10;
int cid, T, n, d, x[N], f[N], dp[N];
int ans;

void cal(int s) {
	dp[s] = 0, f[s] = 1;
	for(int i = s + 1;i <= n;++ i) dp[i] = 2e9, f[i] = 0;
	for(int i = s + 1;i <= n;++ i){
		int p = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
		p = max(s, p);
			for(int j = p;j < i;++ j){
				if(dp[i] > dp[j] + 1) {
					dp[i] = dp[j] + 1;
					f[i] = f[j];
				} else if(dp[i] == dp[j] + 1) f[i] += f[j], f[i] = min(f[i], 3ll);
				else break;
			}
		if(f[i] == 2) ans++;
		if(!f[i]) break;
	}
}

void solve() {
	cin >> n >> d;
	for(int i = 1;i <= n;++ i) cin >> x[i];
	ans = 0;
	for(int i = 1;i <= n;++ i) cal(i);
	cout << ans << "\n";
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> cid >> T;
	while(T--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/