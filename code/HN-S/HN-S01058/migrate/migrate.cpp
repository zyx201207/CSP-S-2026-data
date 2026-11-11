#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>
#define file(s)	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
const int N = 5010;
int c, T, n;
ll d, x[N], cnt[N], dis[N];
bool vis[N];
vector<int> g[N];
void dij(int s) {	
	for (int i = 1; i <= n; ++i)	vis[i] = 0, cnt[i] = 0, dis[i] = 1e9;
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dis[s] = 0;
	cnt[s] = 1;
	q.push({dis[s], s});
	while (!q.empty()) {
		PII t = q.top();
		q.pop();
		int u = t.second;
		if (vis[u])	continue;
		vis[u] = 1;
		for (int v : g[u]) {
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push({dis[v], v});
			} else if (dis[v] == dis[u] + 1)	cnt[v]++;
		}
	}
}
signed main() {
	file(migrate);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)	cin >> x[i];
		for (int t = 1; t <= n; ++t)	g[t].clear();
		for (int i = 1; i <= n; ++i)	for (int j = i + 1; j <= n; ++j)	if (abs(x[i] - x[j]) <= d)	g[i].push_back(j);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			dij(i);
			for (int j = i + 1; j <= n; ++j)	if (cnt[j] == 2)	ans++;
		} 
		cout << ans << "\n";
	}
	return 0;
} 
//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
