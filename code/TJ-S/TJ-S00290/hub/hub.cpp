#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1007;
ll ccc, T, n, k;
vector <ll> a[N];
ll col[N];
ll dfs(ll u){
	col[u] = 0;
	for (ll v : a[u]){
		if (col[v] == 1) dfs(v);
	}
}
ll dfs2(ll u){
	for (ll v : a[u]){
		if (col[v] != -1) continue;
		col[v] = col[u] + 1;
		dfs2(v);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> ccc >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 0; i < n; i++) a[i].clear();
		ll x, y;
		for (int i = 1; i < n; i++){
			cin >> x >> y; x--, y--;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		ll ans = 4e18;
		for (ll t = 1; t < (1 << n); t++){
			for (int i = 0; i < n; i++) col[i] = -1;
			ll sum = 0;
			for (int i = 0; i < n; i++){
				if ((t >> i) & 1) col[i] = 1, sum++;
			}
			if (sum != k) continue;
			sum = 0;
			for (int i = 0; i < n; i++){
				if (col[i] == 1){
					sum++;
					if (sum > 2) break;
					dfs(i);
				}
			}
			if (sum > 2) continue;
			for (int i = 0; i < n; i++){
				if (col[i] == 0) dfs2(i);
			}
			ll maxx = -1;
			for (int i = 0; i < n; i++){
				maxx = max(maxx, col[i]);
			}
			ans = min(ans, maxx);
		}
		cout << ans << "\n";
	}
	return 0;
}

