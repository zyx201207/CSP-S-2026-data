#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;
int c, t;
int n;
long long d;
long long x[N];
int dp[N][N];
long long cnt[N][N];
long long ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			for (int j = i; j <= n; ++j) {
				dp[i][j] = 0x3f3f3f3f;
				cnt[i][j] = 1;
			}
			dp[i][i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				for (int k = j - 1; k >= i; --k) {
					if (x[j] - x[k] <= d) {
						int a = dp[i][k] + 1;
						if (a < dp[i][j]) {
							dp[i][j] = a;
							cnt[i][j] = cnt[i][k];
						} else if (a == dp[i][j]) {
							cnt[i][j] += cnt[i][k];
						}
					} else {
						break;
					}
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (cnt[i][j] == 2) {
					ans++;
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}
