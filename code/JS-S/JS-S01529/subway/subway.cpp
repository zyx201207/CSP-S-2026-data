#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

void dij(vector<ll>& dis1, const vector<vector<pair<int, ll>>>& u, vector<vector<pair<int, ll>>>& v, int s){
	struct node{
		bool f;
		int x;
		ll d;
		bool operator < (const node& p) const {
			return d > p.d;
		}
	};

	vector<ll> dis2(u.size(), INF);
	priority_queue<node> pq;
	pq.push({0, s, dis2[s] = 0});

	while(!pq.empty()){
		node cur = pq.top();
		pq.pop();

		if(cur.f){
			if(cur.d != dis1[cur.x])
				continue;

			for(auto p : v[cur.x]){
				ll nd = dis1[cur.x] + p.second;

				if(nd < dis2[p.first])
					pq.push({0, p.first, dis2[p.first] = nd});
			}
		}
		else{
			if(cur.d != dis2[cur.x])
				continue;

			for(auto p : u[cur.x]){
				ll nd = dis2[cur.x] + p.second;

				if(nd < dis1[p.first])
					pq.push({1, p.first, dis1[p.first] = nd});
			}
		}
	}
}

void bfs(vector<ll>& dis1, const vector<vector<pair<int, ll>>>& u, vector<vector<pair<int, ll>>>& v, int s){
	struct node{
		bool f;
		int x;
	};

	vector<ll> dis2(u.size(), INF);
	queue<node> q;
	q.push({0, s});
	dis2[s] = 0;

	while(!q.empty()){
		node cur = q.front();
		q.pop();

		if(cur.f){
			for(auto p : v[cur.x]){
				ll nd = dis1[cur.x] + p.second;

				if(nd < dis2[p.first])
					q.push({0, p.first}), dis2[p.first] = nd;
			}
		}
		else{
			for(auto p : u[cur.x]){
				ll nd = dis2[cur.x] + p.second;

				if(nd < dis1[p.first])
					q.push({1, p.first}), dis1[p.first] = nd;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	vector<ll> w(m + 1);
	for(int i = 1; i <= m; i++)
		cin >> w[i];

	vector<vector<pair<int, ll>>> u(n + 1);
	vector<vector<pair<int, ll>>> v(m + 1);
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;

		u[i].resize(k);
		for(int j = 0; j < k; j++){
			int a, t;
			cin >> a >> t;

			u[i][j] = {a, t};
			v[a].push_back({i, t});
		}
	}

	vector<vector<ll>> dis(n + 1, vector<ll>(m + 1, INF));
	if(12 <= c && c <= 19){
		for(int i = 1; i <= n; i++)
			bfs(dis[i], u, v, i);
	}
	else{
		for(int i = 1; i <= n; i++)
			dij(dis[i], u, v, i);
	}

	while(q--){
		int x, y;
		cin >> x >> y;

		ll ans = INF;
		for(pair<int, ll> p : v[x])
			ans = min(ans, dis[p.first][y] + p.second);

		cout << ans + w[x] + w[y] << '\n';
	}

	return 0;
}