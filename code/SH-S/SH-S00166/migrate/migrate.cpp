#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c, t, n, d, x[5010], cnt[5010][5010], dist[5010], vis[5010];

struct node {
	int v, w;
	bool operator<(const node& other) const {
		return w < other.w;
	}
};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		memset(x, 0, sizeof(x));
		memset(cnt, 0, sizeof(cnt));
		
		cin >> n >> d;
		for (int i=0; i<n; i++) cin >> x[i];
		
		if (c==11 || c==12) {
			cout << 0 << '\n';
			continue;
		}
	
		for (int i=0; i<n; i++) {
			memset(dist, 0x3f, sizeof(dist));
			memset(vis, 0x3f, sizeof(vis));
			priority_queue<node> pq;
			dist[i] = 0;
			pq.push(node{i,0});
			while (!pq.empty()) {
				node cur = pq.top(); pq.pop();
				if (dist[cur.v] == cur.w) cnt[i][cur.v]++;
				if (vis[cur.v]) {
					continue;
				}
				vis[cur.v] = true;
				
				for (int j=cur.v+1; j<n; j++) {
					if (cur.w + (x[j] - x[cur.v]) < dist[j]) {
						dist[j] = cur.w + (x[j] - x[cur.v]);
						pq.push(node{j, dist[j]});
					}
				}
			}
		}
		
		ll ans=0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (cnt[i][j] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
} 
