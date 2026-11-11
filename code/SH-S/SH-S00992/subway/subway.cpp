#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re(i, n) for(ll i = 1; i <= (n); i++)
#define rr(i, l, r) for(ll i = (l); i <= (r); i++)
#define pb push_back
#define cdub cout<<"Debug: "
#define endl '\n'
const ll M = 5e5 + 9, N = 509, INF = 1e16 + 9;
ll c, n, m, d, q;
ll w[M];
vector<pair<ll, ll>> e[M];
ll dis[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	re(i, m) {
		cin>>w[i];
	}
	re(i, n) {
		re(j, n) {
			dis[i][j] = INF;
		}
	}
	re(i, n) dis[i][i] = 0;
	re(i, n) {
		ll k; cin>>k;
		while(k--) {
			ll a, t;
			cin>>a>>t;
			e[a].emplace_back(i, t);
		}
	}
	re(u, m) {
		for(int i = 0; i < e[u].size(); i++) {
			for(int j = i + 1; j < e[u].size(); j++) {
				dis[e[u][i].first][e[u][j].first] = min(
					dis[e[u][i].first][e[u][j].first], 
					e[u][i].second + e[u][j].second
				);
				dis[e[u][j].first][e[u][i].first] = min(
					dis[e[u][j].first][e[u][i].first], 
					e[u][i].second + e[u][j].second
				);
			}
		}
	}
	re(k, n) {
		re(i, n) {
			re(j, n) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		ll u, v; cin>>u>>v;
		ll ans = INF;
		for(int i = 0; i < e[u].size(); i++) {
			for(int j = 0; j < e[v].size(); j++) {
				ans = min(ans, 
					dis[e[u][i].first][e[v][j].first]
					 + e[u][i].second + e[v][j].second
				);
//				cdub<<e[u][i].first<<" "<<e[v][j].second<<" "<<dis[e[u][i].first][e[v][j].first]<<endl;
			}
		}
		cout<<ans + w[u] + w[v]<<endl;
	}
	return 0;
}

