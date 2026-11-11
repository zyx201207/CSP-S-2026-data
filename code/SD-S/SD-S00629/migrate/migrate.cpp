#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e4 + 15;
int c, t, n, d, x[MAXN], dp[MAXN][MAXN];
void solve(){
	cin >> n >> d;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n - 1; i++)
		dp[i][i + 1]++;
	for (int i = 1; i <= n - 2; i++)//from i to k to j
		for (int j = i + 2; j <= n; j++)
			for (int k = i + 1; k <= j - 1 && x[j] - x[k] <= d; k++){
				dp[i][j] += dp[i][k];
			}
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			if (dp[i][j] == 2)
				ans++;
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}
