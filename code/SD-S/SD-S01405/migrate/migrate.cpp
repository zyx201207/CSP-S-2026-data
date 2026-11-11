#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2E6 + 10;

int n;
i64 d;
i64 a[N];
int b[N], ok[N];
int dp[N][2];

void solve() {
	cin >> n >> d;
	
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i ++) {
		int lo = i, ro = n;
		while (lo <= ro) {
			int mid = lo + ro >> 1;
			if (a[mid] - a[i] <= d) lo = mid + 1;
			else ro = mid - 1;
		}
		b[i] = lo - 1;
	}

	memset(ok, 0, 4 * (n + 1));
	for (int i = 1; i <= n; i ++ )
		if (i + 1 < b[i] && b[i] < b[b[i]]) {
			if (b[b[i] - 1] == b[b[i]] && b[b[i] - 2] < b[b[i]]) {
				if (a[b[i] - 1] - a[i - 1] <= d) ok[i] = 1;
				else ok[i] = 2;
			} else if (b[b[i] - 1] < b[b[i]]) ok[i] = 3;
		} else if (i < b[i] && b[i] < b[b[i]]) ok[i] = 3;
		
	memset(dp, 0, 8 * (n + 1));
	i64 res = 0;
	for (int i = n; i >= 1; i -- ) {
		if (b[i] == i) continue;
		if (b[i] == i + 1) {
			dp[i][0] = dp[i + 1][0] + b[i] - i;
			dp[i][1] = dp[i + 1][1];
			res += dp[i][1];
			continue;
		}
		int t = b[b[i] - 1] - b[b[i] - 2];
		if (a[b[i] - 1] - a[i - 1] <= d) t = 0;
		if (ok[i] == 3) {
			if (ok[b[i]] == 1) {
				dp[i][0] = b[i] - i + b[b[i]] - b[b[i] - 1];
				dp[i][1] = t;
			} else {
				dp[i][0] = dp[b[i]][0] - (b[b[i]] - b[i]) + b[i] - i + b[b[i]] - b[b[i] - 1];
				dp[i][1] = dp[b[i]][1] + t;
			}
		} else if (ok[i] == 2 || ok[i] == 1) {
			dp[i][0] = b[i] - i;
			dp[i][1] = dp[b[i]][0] - (b[b[i]] - b[i]) + t;
		} else {
			dp[i][0] = b[i] - i + b[b[i]] - b[b[i] - 1];
			dp[i][1] = t;
		}
		res += dp[i][1] - t + b[b[i] - 1] - b[b[i] - 2];
	}
	
	cout << res << '\n';
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while (t -- ) solve();
	
	return 0;
}
