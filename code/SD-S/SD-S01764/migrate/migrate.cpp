#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 5003;
int c, t, n, d, x[N], dp[N][N], sum[N][N], ans;
struct Node {
	int v, w;
	bool operator < (const Node &t) const {
		return w > t.w;
	}
};
priority_queue<Node> que;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			dp[i][i] = 0;
			sum[i][i] = 1;
			que.push({i, 0});
			while (!que.empty()) {
				Node w = que.top();
				que.pop();
				if (w.w > dp[i][w.v]) continue;
				for (int j = w.v + 1; j <= n && x[j] - x[i] <= d; j++) {
					if (dp[i][j] > dp[i][w.v] + 1) {
						dp[i][j] = dp[i][w.v] + 1;
						sum[i][j] = sum[i][w.v];
						que.push({j, dp[i][j]});
					} else if (dp[i][j] == dp[i][w.v] + 1) sum[i][j] = max(sum[i][j], sum[i][w.v] + 1);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (sum[i][j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
} 
