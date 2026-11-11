#include <bits/stdc++.h>
const int maxn = 1005;
long long dp[maxn][maxn], sum[maxn];
int c, t;
int n; 
long long d, x[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::cin >> c >> t;
	while (t--) {
		std::cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			std::cin >> x[i];
		}
		long long cnt = 0;
		for (int i = 1; i <= n; i++) { //枚举起点 task2 i = 1, 2各加了一次 
			memset(dp, 0, sizeof(dp));
			dp[i][0] = 1;
			for (int z = 1; z <= n; z++) { //距离 
				memset(sum, 0, sizeof(sum));
				for (int j = i; j <= n; j++) {
					sum[j] = sum[j - 1] + dp[j][z - 1];
				}
				int l = i;
				for (int j = i + 1; j <= n; j++) { // 这个 
					while ((x[j] - x[l]) > d)
						l++;
					dp[j][z] = sum[j - 1] - sum[l - 1];
				}
			}
			for (int j = i + 1; j <= n; j++) {
				for (int z = 1; z <= n; z++) {
					if (dp[j][z] > 0){
						if (dp[j][z] == 2)
							cnt++;
						break;
					}
				}
			}
		}
		std::cout << cnt << "\n";
	}
}
