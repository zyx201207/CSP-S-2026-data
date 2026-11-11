#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N = 5e3+10, INF = 1e18;
int c, t, a[N], dp[N][N], cnt[N][N];
vector<int> G1[N];

struct rrr {
	int fi, se, q;
};

void bfs(int n, int d) {
	queue<rrr> q;
	for (int i = 1; i <= n; i++) {
		q.push({i, 0, i});
	}
	while (q.size()) {
		auto t = q.front();
		q.pop();
		for (auto i : G1[t.fi]) {
			//cout << t.q << " " << i << " " << dp[t.q][i] << " " << t.se + 1 << '\n';
			if (dp[t.q][i] > t.se + 1) {
				dp[t.q][i] = t.se + 1;
				cnt[t.q][i] = 1;
				q.push({i, t.se + 1, t.q});
				//cout << "U";
			} else if (dp[t.q][i] == t.se + 1) {
				cnt[t.q][i] += cnt[t.q][t.fi];
			}
			//cout << "Y";
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		vector<PII> qu;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			G1[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] <= d)
					G1[i].push_back(j);
				dp[i][j] = INF;
				cnt[i][j] = 0;
			}
		}
		bfs(n, d);
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2)
					ans++;
				//cout << cnt[i][j] << "&" << dp[i][j] << " ";
			}
			//cout << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
