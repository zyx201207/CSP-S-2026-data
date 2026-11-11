#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c, n, m, d, q;
short mv[500010];
short plat[500010][510];
ll dist[500010], vis[500010];

short get_plat(ll station, ll line) {
	if (plat[station][line] == 0) {
		plat[station][line] = mv[station] + 1;
		mv[station]++;
	}
	return plat[station][line];
}

struct node {
	ll v, w;
	bool operator<(const node& other) const {
		return w > other.w;
	}
};
vector<node> edge[500010*25];

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	 
	for (ll i=1; i<=m; i++) {
		ll wi; cin >> wi;
		edge[i*25].push_back(node{i*25+1, wi});
		edge[i*25+1].push_back(node{i*25, wi});
	}
	for (ll i=1; i<=n; i++) {
		//printf("input line %lld\n", i);
		ll ki, a, t; cin >> ki;
		vector<ll> v;
		for (int j=0; j<ki; j++) {
			cin >> a >> t;
			v.push_back(a);
			edge[a*25+1].push_back(node{a*25+2+get_plat(a, i), t});
			edge[a*25+2+get_plat(a, i)].push_back(node{a*25+1, t});
		}
		
		for (int j=0; j<v.size(); j++) {
			for (int k=0; k<v.size(); k++) {
				if (j != k) {
					// station=v[j], v[k] ; line = i
					edge[v[j]*25+2+get_plat(v[j], i)].push_back(node{v[k]*25+2+get_plat(v[k], i), 0});
					edge[v[k]*25+2+get_plat(v[k], i)].push_back(node{v[j]*25+2+get_plat(v[j], i), 0});
					//printf("connect %lld %lld\n", v[j], v[k]);
				}
			}
		}
	}
	
	
	for (int qq=0; qq<q; qq++) {
		memset(dist, 0x3f, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		priority_queue<node> pq;
		
		ll x, y; cin >> x >> y;
		dist[x*25] = 0;
		pq.push(node{x*25, 0});
		
		while (!pq.empty()) {
			node cur = pq.top(); pq.pop();
			if (vis[cur.v]) continue;
			vis[cur.v] = true;
			
			//printf("cur sta=%lld type=%lld w=%lld\n", cur.v/25, cur.v%25, cur.w);
			
			if (cur.v == (y*25)) break;
			
			edge[x*25].push_back(node{cur.v, cur.w});
			edge[cur.v].push_back(node{x*25, cur.w});
			
			for (const node& j : edge[cur.v]) {
				if (cur.w + j.w < dist[j.v]) {
					dist[j.v] = cur.w + j.w;
					pq.push(node{j.v, dist[j.v]});
				}
			}
		}
		
		cout << dist[y*25] << '\n';
	}
	return 0;
}
