#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
const int inf = 1e18;
int c, T, n, d, x[N];
int dis[N], ans, dp[N], cnt[N];
vector<int> g[N];

void solve() {
	cin>>n>>d;
	for(int i = 1; i <= n; i++) g[i].clear();
	ans = 0;

	for(int i = 1; i <= n; i++) cin>>x[i];

	for(int u = 1; u <= n; u++) {
		for(int v = u + 1; v <= n; v++) {
			if((__int128) x[v] - x[u] <= (__int128)d) {
				g[u].push_back(v);
			} else {
				break;
			}
		}
	}

	for(int u = 1; u <= n; u++) {
		for(int i = u; i <= n; i++) dp[i] = inf, cnt[i] = 0;
		dp[u] = 0;
		cnt[u] = 1;
		for(int v = u; v <= n; v++) {

			for(auto j : g[v]) {
				if(dp[j] > dp[v] + 1) {
					dp[j] = dp[v] + 1;
					cnt[j] = cnt[v];
				} else if(dp[j] == dp[v] + 1) {
					cnt[j] += cnt[v];
				}
			}

			if(v > u && cnt[v] == 2) ans++;
		}
	}

	cout<<ans<<"\n";
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
