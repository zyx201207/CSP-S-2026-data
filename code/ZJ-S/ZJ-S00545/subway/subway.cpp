#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long

const ll inf = (1ll << 60);
const int N = 5e5 + 5;
const int M = 510;
int c , n , m , q , d;
ll w[N] , dist[M][M];
vector <pair <int , ll>> path[N] , edges[M];
set <pair <ll , int>> st;

inline void dijkstra(int s) {
	dist[s][s] = 0;
	for (int i = 1;i <= n;i++) if (dist[s][i] < inf) st.insert(make_pair(dist[s][i] , i));
	while (!st.empty()) {
		ll cur = st.begin()->fi , u = st.begin()->se;
		st.erase(st.begin());
		if (cur == inf) break;
		for (auto v : edges[u]) {
			if (dist[s][v.fi] > dist[s][u] + v.se) {
				dist[s][v.fi] = dist[s][u] + v.se;
				st.insert(make_pair(dist[s][v.fi] , v.fi));
			}
		}
	}
}

int main () {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	scanf ("%d%d%d%d%d" , &c , &n , &m , &d , &q);
	for (int i = 1;i <= m;i++) scanf ("%lld" , &w[i]);
	for (int i = 1;i <= n;i++) {
		int l;
		scanf ("%d" , &l);
		for (int j = 1;j <= l;j++) {
			int a;
			ll t;
			scanf ("%d%lld" , &a , &t);
			path[a].push_back(make_pair(i , t));			
		}
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) dist[i][j] = inf;
	for (int i = 1;i <= n;i++) dist[i][i] = 0;
	for (int i = 1;i <= m;i++) for (auto x : path[i]) for (auto y : path[i]) {
		if (x.fi != y.fi) {
			dist[x.fi][y.fi] = min(dist[x.fi][y.fi] , x.se + y.se);
			dist[y.fi][x.fi] = min(dist[y.fi][x.fi] , x.se + y.se);
		}
	}
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) if (i != j&&dist[i][j] < inf) edges[i].push_back(make_pair(j , dist[i][j]));			
	for (int i = 1;i <= n;i++) dijkstra(i);
	while (q--) {
		int x , y;
		scanf ("%d%d" , &x , &y);
		ll ans = inf;
		for (auto l : path[x]) for (auto r : path[y]) if (dist[l.fi][r.fi] < inf) ans = min(ans , l.se + r.se + dist[l.fi][r.fi]);
		printf ("%lld\n" , ans + w[x] + w[y]);
	}
}