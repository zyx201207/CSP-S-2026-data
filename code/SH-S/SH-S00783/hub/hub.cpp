#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 101;
ll c, t, n, k, d[N][N], ans = 0x7f7f7f7f;
void init(){
	n = k = 0;
	memset(d, 0x7f, sizeof(d));
	ans = 0x7f7f7f7f;
}
void dfs(ll x){
	if (x == k){
		ll now = 0;
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (ll tt = 1;tt <= t;tt++){
		init();
		cin >> n >> k;
		for (ll i = 1;i < n;i++){
			ll u, v;
			cin >> u >> v;
			d[u][v] = d[v][u] = 1;
		}
		for (ll kk = 1;kk <= n;kk++){
			for (ll i = 1;i <= n;i++){
				for (ll j = 1;j <= n;j++){
					d[i][j] = min(d[i][j], d[i][kk] + d[kk][j]);
				}
			}
		}
		dfs(1);
	}
	return 0;
}
