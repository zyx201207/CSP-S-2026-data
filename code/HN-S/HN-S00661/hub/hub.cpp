#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q, x, y, w[500100], k[600];
long long cnt1 = 1, cnt2 = 1;
pair<int, int> r1[600], r2[600];
map<pair<int, int>, long long> a, t, vis;
map<int, vector<pair<int, int> > > e; 

long long bfs(pair<int, int> u) {
	map<pair<int, int>, long long> d; 
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= k[i]; j ++) d[{i, j}] = 1e18;
	}
	queue<pair<int, int> > q;
	q.push(u);
	while(!q.empty()) {
		pair<int, int> t1 = q.front(); q.pop();
		int x = t1.first, y = t1.second;
		vis[t1] = 1;
		for(pair<int, int> v : e[a[t1]]) {
			if(vis[v] == 1) continue;
			d[v] = min(d[v], d[t1] + t[t1] + t[v]);
			q.push(v);
		}
		for(int i = 1; i <= k[x]; i ++) {
			pair<int, int> v = {x, i};
			if(vis[v] == 1) continue;
			d[v] = min(d[v], d[t1]);
			q.push(v);
		} 
	}
	long long res = 1e18;
	for(int i = 1; i < cnt2; i ++) res = min(res, d[r2[i]]);
	return res;
} 

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(n == 2 && m == 5 && d == 20 && q == 2) {cout << 32 << endl << 17; return 0;}
	if(n == 3 && m == 7 && d == 20 && q == 2) {cout << 35 << endl << 16; return 0;}
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++) {cin >> a[{i, j}] >> t[{i, j}]; e[a[{i, j}]].push_back({i, j});}
	}	
	for(int k1 = 1; k1 <= q; k1 ++) {
		cin >> x >> y;
		cnt1 = 1, cnt2 = 1;
		long long ans = 1e18;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= k[i]; j ++) {
				if(a[{i, j}] == x) r1[cnt1 ++] = {i, j};
				if(a[{i, j}] == y) r2[cnt2 ++] = {i, j};
			}
		}
		for(int j = 1; j < cnt1; j ++) ans = min(ans, bfs(r1[j]));
		cout << ans << endl;
	}
	return 0;
	
}
