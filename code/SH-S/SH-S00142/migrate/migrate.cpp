#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+10;
struct node {
	int v, w;
	bool operator < (const node &o) const {
		return w > o.w;
	}
};
priority_queue<node> pq;
int c, t, n, d, ans, x[N], vis[N], dis[N], cnt[N][N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		vector<int> g[N];
		memset(cnt, 0, sizeof(cnt));
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i < n; i++)
			for (int j = i+1; j <= n; j++)
			{
				if (x[j]-x[i] > d) break;
				g[i].push_back(j);
			}
		for (int b = 1; b < n; b++) {
			memset(dis, 0x7f, sizeof(dis));
			memset(vis, 0, sizeof(vis));
			pq.push((node){b, 0});
			dis[b] = 0;
			while (!pq.empty()) {
				int u = pq.top().v;
				pq.pop();
				if (vis[u]) continue;
				vis[u] = 1;
				for (int i = 0; i < g[u].size(); i++)
				{
					int v = g[u][i];
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						cnt[b][v] = 1;
						pq.push((node){v, dis[v]});
					}
					else if (dis[v] == dis[u] + 1) cnt[b][v]++;
				}
			}
		}
		for (int i = 1; i < n; i++)
			for (int j = i+1; j <= n; j++)
				if (cnt[i][j] == 2) {
					cout << i << " " << j << "\n";
					ans++;
				}
		cout << ans << "\n";
	}
	return 0;
}
