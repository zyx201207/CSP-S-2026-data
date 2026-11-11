#include<bits/stdc++.h>
const int N = 1e5 + 5;
using namespace std;
int c, n, m, d, q, w[N], a[505][N], t[505][N], x, y, k[505], vis[N], flag;
vector<int> mp[N];
int bfs() {
	queue<int> q;
	q.push(x);
	int sum = 0, ans = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		sum = sum + t[1][1];
		if (u == y) {
			return sum;
		}
		for (int v : mp[u]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}
int bfs1() {
	queue<pair<int, int> > q;
	q.push({0, x});
	int sum = 0, ans = 0;
	while (q.size()) {
		int uu = q.front().first;
		int u = q.front().second;
		q.pop();
		sum = sum + t[uu][u];
		if (u == y) {
			return sum;
		}
		for (int v : mp[u]) {
			if (!vis[v]) {
				q.push({u, v});
				vis[v] = 1;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		if (w[i] != w[i - 1]) {
			flag = 1; 
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			if (t[i][j] != t[i - 1][j] || t[i - 1][j] != t[i][j - 1] || t[i][j] != t[i][j - 1]) {
				flag = 1;
			}
			mp[i].push_back(a[i][j]);
			mp[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= q; i++) {
		memset(vis, 0, sizeof vis);
		cin >> x >> y;
		if (!flag) {
			int p = bfs();
			cout << p + w[x] + w[y] << '\n';
		} else {
			int p = bfs1();
			cout << p + w[x] + w[y] << '\n';
		}
	}
	return 0;
}
