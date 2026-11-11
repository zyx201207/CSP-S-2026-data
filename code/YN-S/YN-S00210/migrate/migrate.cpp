#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
long long x[N], d, cnt[N], dis[N];
int n, t, c, ans;
bool vis[N];
vector<int>e[N];

void bfs(int s) {
	queue<int>q;
	q.push(s);
	cnt[s] = 1, dis[s] = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		if (vis[u])
			continue;
		vis[u] = true;
		for (int v : e[u]) {
			if (v >= s)
				continue;
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1, cnt[v] = cnt[u];
				q.push(v);
			} else if (dis[v] == dis[u] + 1) {
				cnt[v] += cnt[u];
			}
		}
	}
	for (int i = 1; i < s; i++) {
		ans += (cnt[i] == 2);
	}
}

void solve() {
	cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i++)
		e[i].clear();
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		for (int j = i - 1; j >= 1; j--) {
			if (x[i] - x[j] > d)
				break;
			e[i].push_back(j), e[j].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		memset(dis, 0x3f, sizeof(dis));
		bfs(i);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
		solve();
	return 0;
}