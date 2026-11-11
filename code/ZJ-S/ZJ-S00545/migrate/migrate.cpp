#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long
#define IX INT_MAX

const int N = 2e6 + 5;
int c , T;
int n;
ll lim , a[N];
pair <int , int> dp[310][310];

inline void dfs(int i , int j , int dep) {
	if (dep > 0) {
		if (dep < dp[i][j].fi) dp[i][j] = make_pair(dep , 1);
		else if (dep == dp[i][j].fi) dp[i][j].se = min(3 , dp[i][j].se + 1);
	}
	for (int k = j + 1;k <= n&&a[k] - a[j] <= lim;k++) dfs(i , k , dep + 1);
}

int main () {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	scanf ("%d%d" , &c , &T);
	while (T--) {
		scanf ("%d%lld" , &n , &lim);
		for (int i = 1;i <= n;i++) scanf ("%lld" , &a[i]);
		if (c == 0||(1 <= c&&c <= 2)) {
			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) dp[i][j] = make_pair(IX , 1);
			for (int i = 1;i <= n;i++) dfs(i , i , 0);
			int ans = 0;
			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) ans += (dp[i][j].se == 2);
			printf ("%d\n" , ans);
		} else if (c == 0||(3 <= c&&c <= 6)) {
			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) dp[i][j] = make_pair(IX , 1);
			for (int d = 2;d <= n;d++) for (int i = 1;i + d - 1 <= n;i++) {
				int j = i + d - 1;
				if (a[j] - a[i] <= lim) dp[i][j] = make_pair(1 , 1);
				for (int k = i + 1;k < j;k++) {
//					int k = upper_bound(a + 1 , a + n + 1 , a[i] + lim) - (a + 1);
					if (dp[i][k].fi != IX&&dp[k][j].fi != IX) {
						int ans = dp[i][k].fi + dp[k][j].fi , way = dp[i][k].se * dp[k][j].se;
						if (ans < dp[i][j].fi) dp[i][j] = make_pair(ans , way);
						else if (ans == dp[i][j].fi) dp[i][j].se += way;
					}
//					k = lower_bound(a + 1 , a + n + 1 , a[j] - lim) - (a + 1) + 1;
//					if (dp[i][k].fi != IX&&dp[k][j].fi != IX) {
//						int ans = dp[i][k].fi + dp[k][j].fi , way = dp[i][k].se * dp[k][j].se;
//						if (ans < dp[i][j].fi) dp[i][j] = make_pair(ans , way);
//						else if (ans == dp[i][j].fi) dp[i][j].se += way;
//					}
				}
			}
			int ans = 0;
			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) ans += (dp[i][j].se == 2);
//			for (int i = 1;i <= n;i++) for (int j = i + 1;j <= n;j++) printf ("%d %d %d %d\n" , i , j , dp[i][j].fi , dp[i][j].se);
			printf ("%d\n" , ans);
		} else if (c == 0||(13 <= c&&c <= 14)) {
			int k = -1;
			for (int i = 1;i <= n;i++) if (a[i] - a[1] <= lim&&a[n] - a[1] <= lim&&i > 2&&i < n - 1) k = i;
			for (int i = 1;i <= n;i++) if (a[i] - a[1] <= lim&&a[n] - a[1] <= lim&&k == -1) k = i;
			ll ans = 0;
			for (int i = 1;i < k - 1&&k + 1 < n;i++) {
				if (a[k + 1] - a[i] <= lim) {					
					int p = upper_bound(a + 1 , a + n + 1 , a[k - 1] + lim) - (a + 1) + 1;
					int p2 = upper_bound(a + 1 , a + n + 1 , a[k + 1]) - (a + 1);
					if (p <= n&&p > k&&p2 <= n&&p2 >= p) ans += (ll)(p2 - p + 1);
				} else {
					int p = upper_bound(a + 1 , a + n + 1 , a[k - 1] + lim) - (a + 1);
					if (p <= n&&p > k) ans += (ll)(p - k);
				}
			}
			printf ("%lld\n" , ans);
		} else if (c == 0||(11 <= c&&c <= 12)) {
			ll d = a[2] - a[1] , ans = 0;
			for (int i = 2;i < n;i++) {
				ll len = d * (ll)i , x = lim / d * d;
				if (x * 2 <= len) continue;
				else {
					ll rem = lim - (len - x);
					if (rem < 0||rem / d > 1) continue;
					ans += (ll)(n - i);
				}
			}
			printf ("%lld\n" , ans);
		}
	}
}
/*
0 3
10 3
0 3 6 7 8 9 10 11 14 17
*/