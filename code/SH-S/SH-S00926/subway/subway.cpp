#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll N = 1e3 + 5;
const ll BN = 2e4 + 5;
ll c, m, n, d, q;
ll w[N];
ll dis[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> m >> n >> d >> q;
	for(ll i=1; i<=n; i++) cin >> w[i];
	if(c >= 12 && c <= 19){
		delete dis;
		vector<ll> mp[BN];
		ll T;
		for(ll i=1; i<=m; i++){
			ll k;
			cin >> k;
			vector<ll> a(k+1);
			for(ll j=1; j<=k; j++){
				cin >> a[j] >> T;
			}
			for(ll j=1; j<=k; j++){
				for(ll id=j+1; id<=k; id++){
					ll u = a[j], v = a[id];
					mp[u].push_back(v);
					mp[v].push_back(u);
				}
			}
		}
		for(ll i=1; i<=q; i++){
			ll x, y;
			cin >> x >> y;
			queue<ll> q;
			ll vis[BN] = {}, dis[BN] = {};
			q.push(x);
			vis[x] = 1;
			while(q.size()){
				ll r = q.front();
				q.pop();
				if(vis[r]) continue;
				vis[r] = 1;
				if(r == y){
					cout << dis[r] * 2 * T << endl;
					break;
				}
				for(ll j=0; j<mp[r].size(); j++){
					ll v = mp[r][j];
					if(vis[v]) continue;
					dis[v] = dis[r] + 1;
					q.push(v);
				}
			}
		}
		return 0;
	}
	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=n; j++) dis[i][j] = 1e9;
		dis[i][i] = 0;
	}
	for(ll i=1; i<=m; i++){
		ll k;
		cin >> k;
		vector<pii> line(k+1);
		for(ll j=1; j<=k; j++){
			ll a, t;
			cin >> a >> t;
			line[j] = {a, t};
		}
		for(ll j=1; j<=k; j++){
			for(ll id=j+1; id<=k; id++){
				ll u = line[j].first, v = line[id].first;
				ll t1 = line[j].second, t2 = line[id].second;
				dis[u][v] = dis[v][u] = min(dis[u][v], w[u] + w[v] + t1 + t2);
			}
		}
	}
	for(ll k=1; k<=n; k++){
		for(ll u=1; u<=n; u++){
			if(u == k) continue;
			for(ll v=1; v<=n; v++){
				if(v == u || v == k) continue;
				dis[u][v] = dis[v][u] = min(dis[u][v], dis[u][k] + dis[k][v] - 2 * w[k]);
			}
		}
	}
	for(ll i=1; i<=q; i++){
		ll x, y;
		cin >> x >> y;
		cout << dis[x][y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
