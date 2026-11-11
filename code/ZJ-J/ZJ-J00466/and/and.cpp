#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N], dp[N];
int sum = INT_MAX;
int ans = 0;
void dfs(int x, int zhi, int last) {
	if(x == m + 1) {
		ans = max(ans, zhi);
		return;
	}
	for(int i = last + 1; i <= n - (m - x); i++) {
		dfs(x + 1, zhi & a[i], i);
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum &= a[i];
	}
	sort(a + 1, a + n + 1);
	dp[0] = INT_MAX;
	int ma = 0;
	if(m == n - 1) {
		dfs(1, INT_MAX, 0);
		cout << ans << "\n";
	} else if(m * n <= 1e9) {
		for(int i = 1; i <= n; i++) {
			for(int j = m; j >= 1; j--) {
				dp[j] = max(dp[j], (dp[j - 1] & a[i]));
			}
		}
		cout << dp[m];
	} else {
		ans = INT_MAX;
		sort(a + 1, a + n + 1, greater<int>());
		for(int i = 1; i <= m; i++) {
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}