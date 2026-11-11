#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 5e5 + 510;
int w[N];
int dis[N], vis[N];
vector<PII> g[N];
priority_queue<PII, vector<PII>, greater<PII>> q;

void dij(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push({0, s});
	while(q.size()) {
		auto t = q.top();
		q.pop();
		int id = t.second;
		if(vis[id]) continue;
		vis[id] = 1;
		for(auto i : g[id]) {
			int j = i.second;
			if(!vis[j] && dis[j] > dis[id] + i.first) {
				dis[j] = dis[id] + i.first;
				q.push({dis[j], j});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[a].push_back({t, m+i});
			g[m+i].push_back({t, a});
		}
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		dij(l);
		int ans = w[l] + w[r] + dis[r];
		cout << ans << '\n';
	}
	return 0;
} 
