/*
对于任意对点 i, j(i < j), 如果 |x_i - x_j| <= d 则在 i, j 之间建边。

0 1
5 3
-3 0 2 3 4

2
*/ 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1e7;
vector<ll> x, d, t; // x 表示横坐标，d 表示距离，t 表示路径数 
vector<bool> vis;
vector<vector<ll>> G;
void solve(){
	ll n, dis, cnt = 0;
	cin >> n >> dis;
	x.assign(n + 1, 0);  G.assign(n + 1, vector<ll>(0)); 
	for (int i = 1;i <= n;i ++) cin >> x[i];
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= n;j ++){
			if (i == j) continue;
			if (abs(x[i] - x[j]) <= dis) {
//				cout << "edges:" << i << ' ' << j << '\n';
				G[i].push_back(j);
			}
		}
	}
	for (int s = 1;s <= n;s ++){ // 进行调试型修改 
		d.assign(n + 1, INF); t.assign(n + 1, 0); vis.assign(n + 1, false);
		d[s] = 0, t[s] = 1, vis[s] = true;
		queue<int> q;
		q.push(s);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			for (auto v : G[u]){
				if (d[v] > d[u] + 1) d[v] = d[u] + 1, t[v] = t[u];
				else if (d[v] == d[u] + 1) t[v] += t[u];
				if (vis[v]) continue;
				vis[v] = true;
				q.push(v);
			}
		}
		if (s == 5){
//			cout << "s == 5, t == 1 : " << t[1] << '\n';
		}
		for (int i = 1;i <= n;i ++) if (t[i] == 2) {
			cnt ++;
//			cout << "combination:" << s << " to " << i << '\n';
		}
	}
	cout << cnt / 2 << '\n';
	return;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false); 
	int c, t;
	cin >> c >> t;
	while (t --) solve();
	return 0;
}