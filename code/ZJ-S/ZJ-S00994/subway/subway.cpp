#include <bits/stdc++.h>
using namespace std;
#define yuandian 1000000
#define pii pair<int,int>
int c, n, m, d, q, jinzhan[500010], a[501][500010], t[501][500010], h[1001010], nxt[601010], to[601010], w[601010], cnt = 0, s, e, dis[1001010];
bool vis[1001010];
void addedge(int u, int v, int t) {
	cnt++;
	w[cnt] = t;
	to[cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		scanf("%d", &jinzhan[i]);
	} for(int i = 1; i <= n; i++) {
		int k;
		for(int j = 1; j <= k; j++) {
			cin >> a[i][j];
			addedge(yuandian + i, a[i][j], 1);
			addedge(a[i][j], yuandian + i, 1);
			cin >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++) {
		memset(dis, -1, sizeof(dis));
		cin >> s >> e;
		priority_queue<pii,vector<pii >,greater<pii > > pq;
		pii tmp;
		tmp.first = 0, tmp.second = s;
		pq.push(tmp);
		dis[s] = 0;
		vis[s] = 1;
		while(!pq.empty()) {
			pii u = pq.top();
			pq.pop();
			if(vis[u.second]) {
				continue;
			}
			dis[u.second] = u.first;
			vis[u.second] = 1;
			for(int i = h[u.second]; i; i = nxt[i]) {
				int v = to[i], t = w[i];
				if(!vis[v]) {
					if(dis[v] == -1) {
						pii tmpp;
						tmpp.first = u.first + t, tmpp.second = v;
						pq.push(tmpp);
					}
				}
			}
		}
		cout << jinzhan[s]+jinzhan[e]+dis[e] * t[1][1];
	}
	return 0;
} 
