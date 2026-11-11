#include <bits/stdc++.h>
#define ll long long
#define pr pair<ll, ll>
using namespace std;

ll c, n, m, d, q;
ll w[500005];
vector<pr> st[502];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		ll k;
		cin >> k;
		for(int j=1; j<=k; j++){
			ll ta, tt;
			cin >> ta >> tt;
			st[i].push_back({ta, tt});
		}
	}
	ll ans;
	for(int i=1; i<=q; i++){
		ll u, v;
		cin >> u >> v;
		ans = w[u] + w[v];
	}
	// 没时间了 放弃了
	// orz 
}
