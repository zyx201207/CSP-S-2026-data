#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, d, a[200010], dp[10010][10010], cnt[10010][10010];
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		int ans = 0;
		memset(dp, 0x7f7f7f7f, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
			dp[i][i] = 0;
		}
		for(int i = 1; i < n; i++){
			if(a[i + 1] - a[i] <= d) dp[i][i + 1] = 1, cnt[i][i + 1] = 1;
		}
		for(int i = 1; i <= n - 2; i++){
			if(a[i + 2] - a[i] <= d) dp[i][i + 2] = 1, cnt[i][i + 2] = 1;
			else if(a[i + 1] - a[i] <= d && a[i + 2] - a[i + 1] <= d) dp[i][i + 2] = 2, cnt[i][i + 2] = 1;
		}
		for(int len = 4; len <= n; len++){
			for(int i = 1; i <= n - len + 1; i++){
				if(a[i + len - 1] - a[i] <= d) dp[i][i + len - 1] = 1;
				for(int k = 1; k < len; k++){
					dp[i][i + len - 1] = min(dp[i][i + k - 1] + dp[i + k - 1][i + len - 1], dp[i][i + len - 1]);
				}
				int minn = dp[i][i + len - 1];
				for(int k = 2; k < len; k++){
					if(dp[i][i + k - 1] + dp[i + k - 1][i + len - 1] == minn){
						cnt[i][i + len - 1]++;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(cnt[i][j] == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
