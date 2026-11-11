#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int c, T, n, k, u[maxn], v[maxn];
vector<int> e[maxn];
bool vis[maxn];
int dis[maxn];

bool check(int mask) {
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		int p = mask & (1 << (u[i] - 1));
		int q = mask & (1 << (v[i] - 1));
		if(p && q) cnt++;
	}
	return cnt >= k - 2;
}

void bfs(int mask) {
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		vis[i] = 0;
		if(mask & (1 << (i - 1))) q.push(i), dis[i] = 0, vis[i] = 1;
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int y : e[x]) {
			if(vis[y]) continue;
			dis[y] = dis[x] + 1;
			vis[y] = 1;
			q.push(y);
		}
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
			e[u[i]].emplace_back(v[i]);
			e[v[i]].emplace_back(u[i]);
		}
		int res = n;
		if(k == 2) {
			for(int i = 1; i <= n; i++) {
				for(int j = i + 1; j <= n; j++) {
					int mask = (1 << (i - 1)) | (1 << (j - 1));
					bfs(mask);
					int mx = 0;
					for(int p = 1; p <= n; p++) mx = max(mx, dis[p]);
					res = min(res, mx);
				}
			}
		}
		else {
			for(int i = 3; i < (1 << n); i++) {
				if(__builtin_popcount(i) != k) continue;
				if(!check(i)) continue;
				bfs(i);
				int mx = 0;
				for(int j = 1; j <= n; j++) mx = max(mx, dis[j]);
				res = min(res, mx);
			}
		}
		cout << res << "\n";
	}
	return 0;
}