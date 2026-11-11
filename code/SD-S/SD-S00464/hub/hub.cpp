#include <bits/stdc++.h>

#define rep(i, start, end) for (int i = start; i <= end; i++)
#define rev(i, start, end) for (int i = start; i >= end; i--)

using namespace std;

const int N = 1000010;

int n, k;
vector<int> g[N], p;
vector<int> st;

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
} 

int bfs() {
	queue<pair<int, int>> q;
	vector<int> dis(n + 1, 0x3f3f3f3f);
	 
	rep(i, 1, n) {
		if (st[i]) {
			q.push({i, 0});
			dis[i] = 0; 
		}
	}
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		
		for (auto e : g[t.first]) {
			if (dis[e] == 0x3f3f3f3f) {
				q.push({e, t.second + 1});
				dis[e] = t.second + 1;
			}
		}
	}
	
	int mx = 0;
	rep(i, 1, n) mx = max(mx, dis[i]);
	return mx;
} 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	 
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	 
	int c, _;
	cin >> c >> _;
	
	while (_ -- ) {
		cin >> n >> k;
		
		vector<pair<int, int>> edges(n + 1);
		
		rep(i, 2, n) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			edges[i] = {u, v};
		}
		
		int res = 0x3f3f3f3f;
		
		for (int mask = 0; mask < 1 << n; mask++) {
			if (__builtin_popcount(mask) != k) continue;
			
			st.assign(n + 1, 0);
			for (int i = 0; i < n; i++) {
				if (mask >> i & 1) {
					st[i + 1] = true;
				}
			}
			
			p.assign(n + 1, 0);
			iota(p.begin() + 1, p.end(), 1);
			
			int cnt = k - 1;
			
			for (int i = 2; i <= n; i++) {
				if (st[edges[i].first] && st[edges[i].second]) {
					int u = edges[i].first, v = edges[i].second;
					if (find(u) != find(v)) {
						p[find(u)] = find(v);
						cnt -- ;
					}
				}
			}
			
			if (cnt >= 2) continue;
			
			res = min(res, bfs());
		} 
		cout << res << '\n';
		
		rep(i, 1, n) g[i].clear();
	}
	
	return 0;
} 
