#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 10, INF = 1e9 + 10;
typedef pair<ll,ll> pii;
ll c,n,m,d,q;
ll w[N];
vector<pii> g[N],mp[N],G[N];
ll dijkstra(ll x,ll y) {
	priority_queue<pii,vector<pii>,greater<pii>> q;
	vector<bool> vis(m + 10, false);
	vector<ll> dis(m + 10);
	for(int i = 1; i <= m ; i++) dis[i] = INF;
	q.push({0 , x});
	dis[x] = 0;
	while(q.size()) {
		auto t = q.top();
		q.pop();
		auto ver = t.second;
		if(vis[ver]) continue;
		vis[ver] = true;
		for(auto it : G[ver]) {
			auto fi = it.first , se = it.second;
			if(vis[fi]) continue;
			if(dis[fi] > dis[ver] + se) {
				dis[fi] = dis[ver] + se;
				q.push({dis[fi],fi});
			}
		}
	}
	return dis[y];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin>> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k ;
		cin>> k;
		for(int j = 1; j <= k; j++) {
			ll x, y;
			cin>> x >> y;
			mp[i].push_back({x , y});
			g[x].push_back({i , y});
		}
	}
	for(int x = 1; x <= m; x ++) {
		for(auto it : g[x]) {
			auto fi = it.first, se = it.second;
			for(auto te : mp[fi]) {
				auto fx = te.first, sx = te.second;
				if(fx == x) continue;
				G[fx].push_back({x,se + sx});
				G[x].push_back({fx,se + sx});
			}
		}	
	}
	for(int i = 1; i <= q; i++) {
		ll x,y;
		cin>> x >> y;
		cout<< dijkstra(x,y) + w[x] + w[y] << '\n';
	}
	return 0;
} 
