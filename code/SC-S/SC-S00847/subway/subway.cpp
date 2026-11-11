#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N = 505, M = 1005;
LL c, n, m, d, q;
LL statim[N];
struct stu{
	LL stat, _time;
};
vector <stu> line[N];

priority_queue < pair<LL, LL>, vector< pair<LL, LL> >, greater<pair<LL, LL> >  >pq;
bool vis[M]; 
LL dis[M];

void djstl(){
	while(!pq.empty()){
		pair<LL, LL> cur = pq.top();
		pq.pop();
		LL d = cur.first;
		LL u = cur.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(auto &e:line[u]){
			LL v = e.stat;
			LL w = e._time;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(LL i = 1; i<=M; i++){
		dis[i] = INT_MAX;
	}
	for(LL i = 1; i<=m; i++) cin >> statim[i];
	for(LL i = 1; i<=n; i++){
		LL x;
		cin >> x;
		while(x--){
			LL St, T;
			cin >> St >> T;
			line[i+m].push_back({St, T});
			line[St].push_back({i+m, T});
		}
	}
	
	
	while(q--){
		LL u, v;
		cin >> u >> v;
		for(LL i = 1; i<=M; i++){
			dis[i] = INT_MAX;
			vis[i] = false;
		} 
		dis[u] = 0;
		pq.push({0, u});
		djstl();
		LL ans = ( max(dis[v], dis[u]) - min(dis[v], dis[u]) ) + statim[u] + statim[v];
		cout << ans << endl;
	}
	return 0;
} 