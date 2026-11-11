#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int c, n, m, d, q;
int w[N];
vector<pair<int,int> > g[N + 600];
ll p[200][200];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			p[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		while(k--){
			int v, t;
			cin >> v >> t;
			g[i + m].push_back({t, v});
			g[v].push_back({t, i + m});	
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto v : g[i + m]){
			for(auto to : g[v.second]){
				if(to.second != i + m){
					p[i][to.second - m] = p[to.second - m][i] = min(p[i][to.second - m], (v.first + to.first)*1ll);
				}
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
			}
		}	
	}
	for(int i = 1; i <= n; i++){
		p[i][i] = 0;
	}
	while(q--){
		int u, v;
		cin >> u >> v;
		ll ans = 1e18;
		for(auto i : g[u]){
			for(auto j : g[v]){
				ans = min(ans, p[i.second - m][j.second - m] + i.first + j.first);
			}
		}
		cout << ans + w[u] + w[v] << "\n";
	}
}
