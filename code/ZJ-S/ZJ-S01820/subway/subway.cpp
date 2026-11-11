#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500010], k, goal;
long long ans = 8e18;
struct unit {
	int a, t;
};
struct node {
	int k;
	vector<unit> st;
} a[510], b[500010];
void dfs(int k, long long sum) {
	if (k == goal) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < b[k].k; i++) {
		auto& cur = b[k].st[i];
		for (int j = cur.t + 1; j < a[cur.a].k; j++) {
			dfs(a[cur.a].st[j].a, sum + a[cur.a].st[cur.t].t + a[cur.a].st[j].t);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		a[i].k = k;
		int t1, t2;
		for (int j = 0; j < k; j++) {
			cin >> t1 >> t2;
			b[t1].k++;
			b[t1].st.push_back({i, j});
			a[i].st.push_back({t1, t2});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		goal = y;
		ans = 8e18;
		dfs(x, 0);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}