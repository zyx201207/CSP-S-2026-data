#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Inf = 0x3f3f3f3f3f3f3f3fll;
const int N = 510;
int c, t, n, dp[N][N], cnt[N][N];
ll ans, m, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --) {
		cin >> n >> m;
		memset(dp, 0x3f, sizeof(dp)); 
		for(int i = 1; i <= n; i ++) {
			cin >> a[i];
			dp[i][i] = 0;
			cnt[i][i] = 1;
		}
		ans = 0;
		for(int l = 2; l <= n; l ++) {
			for(int i = 1, j = l; j <= n; i ++, j ++) {
				for(int k = i + 1; k <= j; k ++) {
					if(a[k] - a[i] > m) break;
					if(1 + dp[k][j] < dp[i][j]) {
						dp[i][j] = 1 + dp[k][j];
						cnt[i][j] = cnt[k][j];
					}
					else if(1 + dp[k][j] == dp[i][j]) cnt[i][j] += cnt[k][j];
				}
				cnt[i][j] = min(cnt[i][j], 3);
				if(dp[i][j] < Inf && cnt[i][j] == 2) ++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
