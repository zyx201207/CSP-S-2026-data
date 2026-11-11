#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5, M = 505;
const ll inf = 1e18;
int C0,n,m,d,q,x,y;
int k[N],w[N];
vector <int> a[N],t[N],E[N];
ll dis[M][M]; 
unordered_map<int,int> mp[N];
struct node{
	int u,bl;
	ll w;
	bool operator < (const node &lyh) const {
		return w > lyh.w;
	}
};
void dijstra (int s){
	priority_queue <node> q;
	for (int i = 1; i <= k[s]; i++){
		q.push ((node){a[s][i], s, 0});
	}
	while (!q.empty()){
		auto U = q.top(); q.pop();
		if (U.w != dis[s][U.bl]) continue;
		for (auto v : E[U.u]){
			ll cst = t[U.bl][mp[U.bl][U.u]] + t[v][mp[v][U.u]];
			if (U.w + cst < dis[s][v]){
				dis[s][v] = U.w + cst;
				for (int i = 1; i <= k[v]; i++){
					q.push ((node){a[v][i], v, dis[s][v]});
				}
			}
		}
	}
}
void solve(){
	cin >> C0 >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].resize (k[i] + 1);
		t[i].resize (k[i] + 1);
		for (int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
	    	E[a[i][j]].push_back (i);
	    	mp[i][a[i][j]] = j; 
		}
	}
	for (int i = 1; i <= n; i++){
		dis[1][i] = (1 == i ? 0ll : inf);
	}
	dijstra (1);
	for (int i = 2; i <= n; i++){
		dis[i][1] = dis[1][i];
		for (int j = 2; j <= n; j++){
			dis[i][j] = abs (dis[1][j] - dis[1][i]);
		}
	}
	while (q--){
		cin >> x >> y;
		ll bas = w[x] + w[y], ans = inf;
		for (auto u : E[x]){
			for (auto v : E[y]){
				ans = min (ans, t[u][mp[u][x]] + t[v][mp[v][y]] + dis[u][v]);
			}
		}
		cout << ans + bas << '\n';
	}
} 
int main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0; 
}
