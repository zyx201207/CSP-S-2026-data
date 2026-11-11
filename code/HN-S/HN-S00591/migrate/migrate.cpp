#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
vector< vector<ll> > dp(5005, vector<ll>(5005, inf));
vector< vector<ll> > tot(5005, vector<ll>(5005, 0));
void work() {
	ll n, d;
	cin >> n >> d;
	vector<ll> dis(n + 5, 0);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			dp[i][j] = inf, tot[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) cin >> dis[i];
	for(int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int sta = i; sta < j; sta++) {
				if(dis[j] - dis[sta] <= d) {
					if(dp[i][sta] + 1 < dp[i][j]) {
						tot[i][j] = 1;
						dp[i][j] = dp[i][sta] + 1;
					} else if(dp[i][sta] + 1 == dp[i][j]) {
						tot[i][j]++;
					}
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(tot[i][j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1, c = 0;
	cin >> c >> T;
	while(T--) {
		work();
	}
	return 0;
}
