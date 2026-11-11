#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXM = 5e5 + 5;
int c, n, m, d, r;
int w[MAXM];
int mp[1005][1005];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(mp, -1, sizeof(mp));
	
	cin >> c >> n >> m >> d >> r;
	
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
	}
	
	for (int u = 1; u <= n; u ++) {
		int k, v, t;
		cin >> k;
		for (int i = 1; i <= k; i ++) {
			cin >> v >> t;
			mp[u][v] = t;
			mp[v][u] = t;
		}
	}
	
	while (r --) {
		int x, y;
		cin >> x >> y;
		queue<pair<int, int> > q;
		q.push({x, w[x] + w[y]});
		while(!q.empty()) {
			auto t = q.front();
			q.pop();
			int u = t.first, time = t.second;
			if (u == y) {
				cout << time << "\n";
				break;
			}
			for (int v = 1; v <= m; v ++) {
				if (mp[u][v] != -1) {
					q.push({v, time + mp[u][u] + mp[u][v]});
				}
			}
		}
	}
	
	return 0;
}
