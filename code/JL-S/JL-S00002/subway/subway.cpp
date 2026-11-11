#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q;
int w[500115];
struct node{
	int u, dist;
	bool operator < (const node &other)const{
		return this->dist > other.dist;
	}
};
void solve1(){
	vector<vector<pair<int, int>>> G(m + n + 1);
	for (int i = 1; i <= n; i++){
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++){
			int a, t;
			scanf("%lld%lld", &a, &t);
			G[m + i].push_back({a, t});
			G[a].push_back({m + i, t});
		}
	}

	auto dijkstra = [&](int st){
		priority_queue<node> Q;
		vector<int> dis(n + m + 1, 1e9 + 7);
		dis[st] = 0;
		Q.push({st, 0});
		while (!Q.empty()){
			node p = Q.top();
			Q.pop();
			
			int u = p.u, d = p.dist;
			if (dis[u] < d)continue;
			// cout << u << "->";
			for (pair<int, int> r : G[u]){
				int v = r.first, y = r.second;
				// cout << u << ' ' << v << ' ' << endl;
				// cout << dis[v] << ' ' << dis[u] << ' ' << y << endl;
				if (dis[v] > dis[u] + y){
					dis[v] = dis[u] + y;
					Q.push({v, dis[v]});
				}
			}
		}
		// puts("");
		return dis;
	};
	while (q--){
		int x, y;
		scanf("%lld%lld", &x, &y);
		vector<int> res = dijkstra(x);
		
		// puts("");
		int ans = res[y] + w[x] + w[y];
		printf("%lld\n", ans);
	}
}
void solve2(){
	int T = 0;
	vector<vector<pair<int, int>>> G(m + n + 5);
	for (int i = 1; i <= n; i++){
		int k;
		scanf("%lld", &k);
		for (int j = 1; j <= k; j++){
			int a, t;
			scanf("%lld%lld", &a, &t);
			T = t;
			G[m + i].push_back({a, t});
			G[a].push_back({m + i, t});
		}
	}
	auto bfs = [&](int st){
		vector<int> dis(m + n + 5, 2e14 + 1031);
		vector<bool> vis(m + n + 5, false);
		dis[st] = 0, vis[st] = true;
		queue<int> Q;
		Q.push(st);
		while (!Q.empty()){
			int u = Q.front();
			Q.pop();
			for (pair<int, int> r : G[u]){
				int v = r.first;
				if (!vis[v]){
					dis[v] = dis[u] + 1;
					Q.push(v);
					vis[v] = true;
				}
			}
		}
		return dis;
	};
	vector<vector<int>> D(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++){
		vector<int> dd = bfs(m + i);
		
		for (int j = 1; j <= n; j++){
			D[i][j] = dd[m + j];
		}
	}
	while (q--){
		int x, y;
		int cnt = 2e14 + 1031;
		scanf("%lld%lld", &x, &y);
		for (pair<int, int> R : G[x]){
			for (pair<int, int> M : G[y]){
				int rr = R.first, qq = M.first;
				cnt = min(cnt, D[rr - m][qq - m]);
			}
		}
		printf("%lld\n", cnt * T + 2 * T + w[x] + w[y]);
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	if (n <= 200)solve1();
	else solve2();
}
