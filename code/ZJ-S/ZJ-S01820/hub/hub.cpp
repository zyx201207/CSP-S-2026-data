#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, u, v, ans, p, st[3010][3010], w[3010];
bool b[3010];
unordered_map<int, unordered_map<int, bool> > mp;
vector<int> a;
struct node {
	int k, st;
};
queue<node> q;
void bfs(int x, int y) {
	memset(b, 0, sizeof(b));
	q.push({x, 0});
	while (!q.empty()) {
		node& cur = q.front();
		q.pop();
		if (cur.k == y) {
			st[x][y] = st[y][x] = cur.st;
			break;
		}
		for (auto& it : mp[cur.k]) {
			if (!b[it.first]) {
				b[it.first] = true;
				q.push({it.first, cur.st + 1});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 1e9;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			mp[u][v] = true;
			mp[v][u] = true;
		}
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				bfs(i, j);
		memset(b, 0, sizeof(b));
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int maxn = -1;
				for (int k = 1; k <= n; k++)
					maxn = max(maxn, min(st[k][i], st[k][j]));
				ans = min(ans, maxn);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}