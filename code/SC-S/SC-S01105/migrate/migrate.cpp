#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int x[2000005];
int dp[23005][23005];//dp[i][j]:从x[i]出发到x[j]的最短路径条数
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; ++i) {
			dp[i][i]=0;
			dp[i][i + 1] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 2; j <= n; ++j) {
				for (int k = j - 1; k >= 1; --k) {
					if (x[j] - x[k] > d) break;
					dp[i][j] += dp[i][k];
					if (dp[i][j] > 2) break;
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				int D = x[j] - x[i];
				if (D > d) break;
				else {
					if (dp[i][j] == 2) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//I LOVE CCF
	//CCF nb
	//乞求CCF多给点分 orz orz orz
	//许愿米提亚，芙宁娜不歪 十连三金
	return 0;
}