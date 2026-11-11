#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int c, t, n, k;
vector<int>g[N];
int h[N];
int vis[N];
bool vi[N];

void bfs(int x) {
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int v : g[t]) {
			if (!vis[v] && vi[v]) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void bfs1(int x) {
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	int mx = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int v : g[t]) {
			if (!vis[v]) {
				q.push(v);
				vis[v] = vis[x] + 1;
			}
		}
	}
}
int mi = 1e18;

void dfs(int x, int sum) {
	if (sum == k) {
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		for (int i = 1; i <= n; i++)
			vi[i] = 0;
		for (int i = 1; i < x; i++)
			vi[h[i]] = 1;
		int ans = 0;
		for (int i = 1; i < x; i++) {
			if (h[i] && !vis[h[i]]) {
				ans++;
				bfs(h[i]);
			}
		}
		if (ans == 2) {
			//	cout << 111 << endl;
			int ma = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					vis[j] = 0;
				}
				if (!vi[i]) {
					bfs1(i);
					for (int j = 1; j < x; j++) {
						if (h[j]) {
							ma = max(ma, vis[h[j]] - 1);
						}
					}
				}

			}
			for (int j = 1; j < x; j++) {

				//		cout << h[j] << " ";
			}
			//	cout << endl;
			mi = min(mi, ma);
		}
		return;
	}
	if (x == n + 1)
		return;
	h[x] = x;
	dfs(x + 1, sum + 1);
	h[x] = 0;
	dfs(x + 1, sum);
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		mi = 1e18;
		for (int i = 1; i <= n; i++)
			h[i] = 0;
		dfs(1, 0);
		cout << mi << "\n";
	}
	return 0;
}