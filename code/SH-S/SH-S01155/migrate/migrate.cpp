#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;
ll c, T, n, d, x[N];
struct node{
	int len, sum;
}dp[5010][5010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> T;
	while (T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++ i)
			cin >> x[i];
		
		// 1~10 样例点可过  11+开始数组越界 
		ll ans = 0;
		for (int l = 1; l < n; ++ l) {
			for (int i = 1; i + l <= n; ++ i) {
				int j = i + l;
				dp[i][j].len = n;
				if (x[j] - x[i] <= d) dp[i][j].len = 1;
				dp[i][j].sum = 1;
				for (int lj = j - 1; lj >= i; -- lj) {
					if (x[j] - x[lj] > d) break;
					if (dp[i][j].len > dp[i][lj].len + 1) {
						dp[i][j].len = dp[i][lj].len + 1;
						dp[i][j].sum = dp[i][lj].sum;
					}
					else if (dp[i][j].len == dp[i][lj].len + 1)
						dp[i][j].sum += dp[i][lj].sum;
				}
				if (dp[i][j].sum == 2) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
