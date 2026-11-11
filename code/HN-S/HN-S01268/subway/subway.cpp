#include <bits/stdc++.h>

using namespace std;

const int N = 501000;
const int M = 30010;

int c, n, m, d, q;
int w[N];
long long dp[600][600];
vector<pair<int, int>> e[N], e2[600];
struct Node {
	int p;
	long long len;
	bool operator > (Node x) const {
		return len > x.len;
	}
};
priority_queue<Node, vector<Node>, greater<Node>> Q;
bool flag[600];

int main() {
	freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		int len;
		scanf("%d", &len);
		for (int j = 1; j <= len; j++) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(make_pair(m + i, v));
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) dp[i][j] = 1ll << 59;
	for (int i = 1; i <= m; i++) {
		for (auto j : e[i]) {
			for (auto k : e[i]) {
				dp[j.first - m][k.first - m] = min(dp[j.first - m][k.first - m], j.second * 1ll + k.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == (1ll << 59)) continue;
			e2[i].push_back(make_pair(j, dp[i][j]));
		}
	}
	for (int i = 1; i <= n; i++) {
		Q.push({i, 0});
		while (!Q.empty()) {
			Node t = Q.top();
			Q.pop();
			if (flag[t.p]) continue;
			flag[t.p] = true;
			dp[i][t.p] = t.len;
			for (auto j : e2[t.p]) if (!flag[j.first]) Q.push({j.first, t.len + j.second});
		}
		for (int j = 1; j <= n; j++) flag[j] = false;
	}
	for (int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		long long ans = 1ll << 59;
		for (auto j : e[l]) {
			for (auto k : e[r]) {
				ans = min(ans, dp[j.first - m][k.first - m] + j.second + k.second);
			}
		}
		printf("%lld\n", ans + w[l] + w[r]);
	}
	return 0;
} 
