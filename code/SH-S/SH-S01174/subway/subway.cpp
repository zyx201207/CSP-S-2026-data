#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 510, maxm = 5e5 + 10;
int c, n, m, d, q;
int w[maxm];
vector<pair<int, int> > map_[maxn+maxm];
int dis[maxn+maxm];
map<pair<int,int>,int> dp;

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> w[i];
	for(int i = 1;i<=n;i++){
		int k; cin >> k;
		while(k--){
			int a, t; cin >> a >> t;
			map_[a].push_back({t, i+m});
			map_[i+m].push_back({t, a});
		}
	}
	while(q--){
		fill(dis, dis+n+m+1, 1e18);                     
		int x, y; cin >> x >> y;
		if(dp.find({x,y}) != dp.end()) {
			cout << dp[{x,y}] + w[x] + w[y] << endl; continue;
		}
		if(dp.find({y,x}) != dp.end()) {
			cout << dp[{y,x}] + w[x] + w[y] << endl; continue;
		}
		priority_queue<pair<int, int> > pq;
		pq.push({0, x});
		dis[x] = 0;
		while(!pq.empty()){
			pair<int, int> tmp = pq.top(); pq.pop();
			int t = tmp.first, u = tmp.second;
			if(dis[u] < t) continue;
			for(pair<int, int> p : map_[u]){ 
				int v = p.second, w = p.first;
				if(dis[v]>dis[u]+w){
					dis[v] = dis[u]+w;
					pq.push({dis[v], v});
				}
			}
		}
		for(int i = 1;i<=n+m;i++){
			dp[{x,i}] = dis[i];
			dp[{i,x}] = dis[i];
		}
		cout << dis[y] + w[x] + w[y] << endl;
	}
}

