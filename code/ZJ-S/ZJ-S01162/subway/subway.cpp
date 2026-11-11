#include<bits/stdc++.h>
#define ll long long
#define ull long long unsigned
using namespace std;
const int N = 505;//line
const int M = 5e5+5;//node
struct state {
	int node;
	ull cost;
	state(int n, ull d): node(n), cost(d) {}
	bool operator < (const state other) const {
		return this->cost < other.cost;
	}
};
struct rway {
	int line;
	ull cost;
};
int c, n, m, d, q, x, y;
int get_in[M], k[M];
vector<int>a[N], t[N];
vector<rway>g[M];
ull dis[N];//underground
//bitset<N>vis, theZeroAAAA = 0;

priority_queue<state>pq;
int work() {
	cin >> x >> y;
	for(int i = 1; i <= m; ++i) {
		dis[i] = 1e18 + 8;
	}

	dis[x] = 0;

	int u, v, l;
	ull w;
	for(unsigned int i = 0; i < g[x].size(); ++i) { //line
		l = g[x][i].line;
		for(int j = 0; j < k[l]; ++j) { //node_index
			v = a[l][j];
			if(x == v)continue;
//			wx = 1e18+8;
//			for(rway line : g[x])if(line.line == l)wx = line.t;
//			if(wx == (ull)1e18+8)cout << "BUG\n";
			w = g[x][i].cost + t[l][j];
			dis[v] = w;
			pq.emplace(v, dis[x] + w);
		}
	}

	while(!pq.empty() ) {
		v = pq.top().node;
		w = pq.top().cost;
		pq.pop();

//		cout << v.node << '\t';

//		for(int i = 1; i <= m; ++i)cout << dis[i] << ' ';
//		cout << '\n';

		if(dis[v] < w)continue;//past

		u = v;//from u(v) -> v
		for(unsigned int i = 0; i < g[u].size(); ++i) { //line
			l = g[u][i].line;
			for(int j = 0; j < k[l]; ++j) { //node_index
				v = a[l][j];
				if(u == v)continue;

//				wx = 1e18+8;
//				for(rway line : g[x])if(line.line == l)wx = line.t;
//				if(wx == (ull)1e18+8)cout << "BUG\n";

				w = g[u][i].cost + t[l][j];
				if(dis[u] + w < dis[v] ) {
					dis[v] = dis[u] + w;
					pq.emplace(v, w);
				}
			}
		}
	}
	cout << get_in[x] + get_in[y] + dis[y] << '\n';
	return 0;
}

queue<int>qq;
int workB() {
	cin >> x >> y;
	
	for(int i = 1; i <= m; ++i) {
		dis[i] = 0;//vis
	}

	int u, v, l, flag = 0;

	qq.push(x);
	while(!qq.empty() ) {
		u = qq.front();
		qq.pop();
		for(unsigned int i = 0; i < g[u].size(); ++i) {
			l = g[u][i].line;
			
			for(int j = 0; j < k[i]; ++j) {
				v = a[i][j];
				if(dis[v])continue;
				dis[v] = dis[u] + 1;
				if(u == y) {
					flag = 1;
					break;
				}//for-v
			}
			if(flag)break;//for-line
		}
		if(flag)break;//while
	}
	ull w = get_in[x] + get_in[y] + dis[y] * t[1][0] * 2;
	cout << w << '\n';
	return 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		cin >> get_in[i];
	}

	int v;
	ull w;
	for(int i = 1; i <= n; ++i) {
		cin >> k[i];
		a[i].reserve(k[i]);
		t[i].reserve(k[i]);
		for(int j = 1; j <= k[i]; ++j) {
			cin >> v >> w;
			g[v].push_back( {i, w} );
			a[i].push_back(v);
			t[i].push_back(w);
		}
	}

//	for(int i = 1; i <= m; ++i)cout << get_in[i] << ' ';
//	cout << '\n';
//	for(int i = 1; i <= m; ++i) {
//		for(int j : g[i])cout << j << ' ';
//		cout << '\n';
//	}
	while(q--) {
		if(12 <= c || c <= 19)work();
		else work();
	}
	return 0;
}
//test3 fail!!!
