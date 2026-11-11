#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define int long long

using namespace std;

const int N = 5005 + 5;

int c, t, n, d, x[N], l, r, vis[N], dis[N], sum[N], u, ans;
vector <int> g[N];

void dijkstra(int s)
{
	priority_queue < pair <int, int> > q;
	memset(dis, 0x3f, sizeof dis);
	memset(sum, 0, sizeof sum);

	q.push({0, s});
	vis[s] = s, dis[s] = 0;
	
	while (!q.empty()) {
		u = q.top().second;
		q.pop();
		vis[u] = s;
		
		for (auto it : g[u]) {
			if (vis[it] == s) continue;
			if (dis[it] > dis[u] + 1) {
				dis[it] = dis[u] + 1;
				sum[it] = 1;
				q.push({-dis[it], it});
			} else if (dis[it] == dis[u] + 1) {
				sum[it]++;
			}
		}
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;

		for (int i = 1; i <= n; i++) g[i].clear();
		ans = 0;
		
		for (int i = 1; i <= n; i++) cin >> x[i];
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] > d) break;
				g[i].push_back(j);
			}
		}
		
		for (int i = 1; i <= n; i++) {
			dijkstra(i);
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[j - 1] > d) break;
				if (sum[j] == 2) ans++;
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}