#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, w[500005], ki, aij, tij, x, y, dis[500005], vis[500005];
vector<int> a[505], t[505];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> ki;
		for (int j = 1; j <= ki; j++) cin >> aij >> tij, a[i].push_back(aij), t[i].push_back(tij);
	}for (int i = 1; i <= q; i++){
		cin >> x >> y;
		memset(vis, 0, sizeof dis), memset(dis, 0x3f, sizeof dis);
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		pq.push({0, x}), dis[x] = 0;
		while (!pq.empty()){
			int f = pq.top().second;
			pq.pop();
			if (vis[f]) continue;
			else vis[f] = 1;
			for (int j = 1; j <= n; j++){
				int pos = -1;
				for (int k = 0; k < a[j].size(); k++) if (a[j][k] == f) pos = k;
				if (pos == -1) continue;
				for (int k = 0; k < a[j].size(); k++) if (a[j][k] != f && dis[a[j][k]] > dis[f] + t[j][k] + t[j][pos])
					pq.push({dis[a[j][k]] = dis[f] + t[j][k] + t[j][pos], a[j][k]});
			}
		}cout << dis[y] + w[x] + w[y] << endl;
	}return 0;
}

