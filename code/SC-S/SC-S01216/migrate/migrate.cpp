#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e6+5;
const int INF = 1e18;
int C, T, n, d;
int x[MAXN];
int cnt[MAXN], dis[MAXN], vis[MAXN];
vector<int> G[MAXN];

void bfs(int start) {
	fill(cnt + 1, cnt + 1 + n, 0);
	fill(dis + 1, dis + 1 + n, INF);
	fill(vis + 1, vis + 1 + n, 0);
	queue<pair<int, int>> q;
	q.push({start, 0});
	while (!q.empty()) {
		int cur = q.front().first, dist = q.front().second;
		q.pop();
		for (int nxt : G[cur]) {
			if (vis[nxt]) continue;
			if (dis[nxt] < dist + 1) {
				vis[nxt] = 1;
				continue;
			}
			if (dis[nxt] > dist + 1)	dis[nxt] = dist + 1;
			q.push({nxt, dist + 1}), cnt[nxt]++;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)	cin >> x[i];
		for (int i = 1; i <= n; i++)	G[i].clear();
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d)	G[i].push_back(j);
				else	break;
			}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			bfs(i);
			for (int j = 1; j <= n; j++)
				if (cnt[j] == 2)	ans++;
		}
		cout << ans << "\n";
	}






	return 0;
}