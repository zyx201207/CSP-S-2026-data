#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, dis[1500005], vis[1500005];
struct node {
	int id, w;
	bool operator < (const node &a) const {
		return w > a.w; 
	}
};
vector <node> v[1500005];
void Dijk(int x) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue <node> q;
	q.push({x, 0});
	dis[x] = 0;
	while(!q.empty()) {
		int t = q.top().id;
		q.pop();
		if(vis[t]) continue;
		vis[t] = 1;
		for(int j = 0; j < v[t].size(); j++) {
			node i = v[t][j];
			if(dis[i.id] > dis[t] + i.w) {
				dis[i.id] = dis[t] + i.w;
				q.push({i.id, dis[i.id]});
			}
		}
	}
	return ;
}
map <int, int> mp;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		v[i + n * m + n * m + m + m].push_back({i + n * m + n * m + m, x});
		v[i + n * m + n * m + m].push_back({i + m * n + m + n * m + m, x});
	}
	for(int i = 1; i <= n; i++) {
		int k, lst = -1;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			if(mp.count(x)) {
				v[mp[x]].push_back({x + i * m + n * m, 0});
				v[x + i * m].push_back({mp[x], 0});
				mp[x] = x + i * m + n * m;
			} else mp[x] = x + i * m + n * m;
			v[x + i * m].push_back({x + n * m + n * m + m, y});
			v[x + n * m + n * m + m].push_back({x + i * m, y});
			v[x + i * m].push_back({x + i * m + n * m, y});
			v[x + i * m + n * m].push_back({x + i * m, y});
			if(lst != -1) {
				v[lst].push_back({x + i * m, 0});
				lst = x + i * m;
			} else lst = x + i * m;
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		Dijk(x + n * m + m * n + m + m);
		cout << dis[y + n * m + n * m + m + m] << "\n";
	}
	return 0;
} 
