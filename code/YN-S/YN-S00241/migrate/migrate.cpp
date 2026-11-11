#include <bits/stdc++.h>
using namespace std;
int c, t;
long long dp[2000006], a[2000006], ans;
long long n, d;

//void dfs(long long s) {
//	if(a[id+1]-a[id]<=s){
//		s-=a[id+1]-a[id];
//		dp[id]=min(dfs(s-a[id+1]-a[id]),);
//		id++;
//	}
//}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		dp[0] = 2000000000000000018;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= j; k++) {
				if (a[k + 1] - a[k] <= d && j != 1) {
					dp[j] = min(dp[j - 1], dp[j - 2] + a[j + 1] - a[j]);
					if (dp[j - 1] == dp[j - 2] + a[j + 1] - a[j])
						ans++;
				} else if (a[k + 1] - a[k] <= d && j == 1) {
					dp[j] = dp[j - 2] + a[j + 1] - a[j];
				}
			}
		}
		cout << dp[n] << endl;
		for (int j = 1; j <= n; j++) {
			dp[i] = 0;
			a[j] = 0;
		}
//		dfs(d);
	}
	return 0;
}