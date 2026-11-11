/*
小明从到达 i 地铁站后，分两种情况：
- 如果打算换线，要先走到门厅(会花费 w[i] 的时间)，然后再走到要换乘的第 $j$ 条地铁线路(会花费 t[i][j])。
  在这种情况下，能换线的站 k 满足 (a[l][idx[k] - 1] == j)(idx 表示 k 在 a[i] 中的位置, 1 <= l <= n) 
  
- 不换线，就没有花费。 
c, n, m, d, q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。

w[i] 从第 i 个地铁站的地铁口走到站厅需要的时间。

中 a[i][j] 表示第 i 条线路经过的第 j 个地铁站，t[i][j] 表示从 a[i][j] 地铁站的站厅走到第 i 条线路的站台需要的时间。
*/ 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
ll c, n, m, d, q;
vector<ll> w;
vector<vector<ll>> a, t;
void solve(){
	ll x, y;
	cin >> x >> y;
	vector<vector<ll>> dist(m + 1, vector<ll>(n + 1, INF));
	priority_queue<array<ll, 3>> pq; // pq.top[0] = d; pq.top[1] = pos, pq.top[2] = station;
	for (int i = 1;i <= n;i ++){
		ll idx = lower_bound(begin(a[i]), end(a[i]), x) - begin(a[i]);
		if (idx == 0 || idx >= a[i].size()) continue;
		dist[x][i] = w[x] + t[i][idx];
		pq.push({-dist[x][i], x, i});
	}
	while (!pq.empty()){
		array<ll, 3> top = pq.top();
		ll d = -top[0], p = top[1], s = top[2];
		pq.pop();
		if (dist[p][s] != d) continue;
		for (int i = 1;i <= n;i ++){
			ll idx = lower_bound(begin(a[i]), end(a[i]), p) - begin(a[i]);
			
//			cout << "a[i]:";
//			for (int j = 1;j < a[i].size();j ++) cout << a[i][j] << ' ';
//			cout << '\n';
			
			if (idx == 0 || idx >= a[i].size() - 1) continue;
			if (i == s){
				if (dist[a[i][idx + 1]][i] > dist[p][i]) {
					dist[a[i][idx + 1]][i] = dist[p][i];
					
					pq.push({-dist[a[i][idx + 1]][i], a[i][idx + 1], i});
				}
			}
			else{
				if (dist[a[i][idx + 1]][i] > dist[p][s] + w[p] + t[i][idx]) {
					dist[a[i][idx + 1]][i] = dist[p][s] + w[p] + t[i][idx];
					pq.push({-dist[a[i][idx + 1]][i], a[i][idx + 1], i});
				}
			}
		}
	}
//	for (int i = 1;i <= m;i ++) cout << dist[i] << ' ';
//	cout << '\n';
	ll res = INF;
	for (auto tmp : dist[y]) res = min(res, tmp);
	cout << res << '\n';
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	w.assign(m + 1, 0); a.assign(n + 1, vector<ll>(0)); t.assign(m + 1, vector<ll>(0));
	for (int i = 1;i <= m;i ++) cin >> w[i];
	for (int i = 1;i <= n;i ++) {
		int k;
		cin >> k;
		a[i].assign(k + 1, 0); t[i].assign(k + 1, 0);
		for (int j = 1;j <= k;j ++) cin >> a[i][j] >> t[i][j];
	}
	while (q --) solve();
	return 0;
}

/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3

*/