#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, d, ans, sz[2000005], x[2000005], l[2000005], r[2000005], cnt[2000005], f[2000005], dp[2000005];
bool vis[2000005];
vector<int> g[2000005];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		if(c == 11 || c == 12){
			if(d <= 1 || x[2] - x[1] == 0) cout << "0\n";
			else{
				int ans = 0;
				d = d / (x[2] - x[1]);
				if(d <= 1){
					cout << "0\n";
					continue;
				}
				for(int i = 1; i <= n; i++){
					ans += max(0LL, (n - i - d) / d);
				}
				cout << ans << "\n";
			}
			continue;
		} 
		int ans = 0;
		for(int i = 1; i <= n; i++){
			memset(cnt, 0, sizeof cnt);
			memset(dp, 0x3f, sizeof dp);
			dp[i] = 0;
			cnt[i] = 1;
			for(int j = i + 1; j <= n; j++){
				for(int k = j - 1; k >= i; k--){
					if(x[j] - x[k] > d) break;
					if(dp[k] + 1 < dp[j]){
						dp[j] = dp[k] + 1;
						cnt[j] = cnt[k];
					}
					else if(dp[k] + 1 == dp[j]) cnt[j] += cnt[k];
					else break;
				}
				if(cnt[j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
