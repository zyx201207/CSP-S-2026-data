// CSP RP++
// luv wsj
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int M = 5e5, N = 500;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int C, n, m, d, Q;
ll dis[N + 5][N + 5], w[M + 5];
vector<pii> T[M + 5], g[N + 5];
bitset<N + 5> vis;

template<typename T>
inline void chmin(T& a, const T b){ a = min(a, b); }
template<typename T>
inline void chmax(T& a, const T b){ a = max(a, b); }

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> C >> n >> m >> d >> Q;
//	cout << "N" << endl;
	for(int i = 1; i <= m; ++ i) cin >> w[i];
//	cout << "w" << endl;
	for(int i = 1, k, a, t; i <= n; ++ i){
		cin >> k;
		while(k --){
			cin >> a >> t;
			T[a].emplace_back(i, t);
		}
	}
//	cout << "k" << endl;
//	cout << "INPUT" << endl;
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; ++ i) dis[i][i] = 0;
	for(int i = 1, u, v; i <= m; ++ i) for(const auto& p1 : T[i]){
		u = p1.first;
		for(const auto& p2 : T[i]){
			v = p2.first;
			const ll w = p1.second + p2.second;
			if(u == v) continue;
			chmin(dis[u][v], w);
		}
	}
	for(int k = 1; k <= n; ++ k) for(int x = 1; x <= n; ++ x) for(int y = 1; y <= n; ++ y) chmin(dis[x][y], dis[x][k] + dis[k][y]);
//	cout << "GRAPH" << endl;
//	cout << "DIJ" << endl;
	int u, v;
	ll ans;
	while(Q --){
		cin >> u >> v;
		ans = INF;
		for(const auto& p1 : T[u]) for(const auto& p2 : T[v]) chmin(ans, w[u] + w[v] + p1.second + p2.second + dis[p1.first][p2.first]);
		cout << ans << '\n';
	}
}

