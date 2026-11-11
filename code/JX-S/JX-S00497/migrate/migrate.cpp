#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5009;
ll c, t;
ll n, d;
ll x[maxn];
ll dp[maxn][maxn];
ll cnt[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		memset(dp, 0x3f, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		for(ll i = 1; i <= n; ++i)cin >> x[i];
		for(ll i = 1; i <= n; ++i)dp[i][i] = 0;
		for(ll i = 1; i <= n; ++i){
			for(ll j = i + 1; j <= n; ++j){
				if(x[j] - x[i] <= d){
					dp[i][j] = 1;
				}
				else break;
			}
		}
		for(ll k = 1; k <= n; ++k){
			for(ll i = 1; i < k; ++i){
				for(ll j = k + 1; j <= n; ++j){
					if(dp[i][k] + dp[k][j] <= dp[i][j]){
						if(dp[i][k] + dp[k][j] < dp[i][j]){
							dp[i][j] = dp[i][k] + dp[k][j];
							cnt[i][j] = 1;
						}else{
							++cnt[i][j];
						}
					}
				}
			}
		}
		ll ans = 0;
		for(ll i = 1; i <= n; ++i){
			for(ll j = i + 1; j <= n; ++j){
				if(dp[i][j] == 1)continue;
				if(cnt[i][j] == 2){
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/














