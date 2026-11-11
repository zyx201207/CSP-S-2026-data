#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e18;
int c, n, m, d, q;

struct node{
	ll v, t;
};

struct nodee{
	ll v, w;
};

bool operator < (nodee x, nodee y){
	return x.w > y.w;
}
vector <node> a[505];
vector <node> dd[500005];
ll dis[500005], bj[500005];
int w[500005];

inline void dij(int qd){
	priority_queue <nodee> q; 
	for(int i = 1;i <= m;i++){
		dis[i] = MAX;
		bj[i] = 0; 
	}
	q.push({qd, 0});
	dis[qd] = 0;
	while(!q.empty()){
		nodee u = q.top();
		q.pop();
		if(bj[u.v]) continue;
		bj[u.v] = 1;
		for(node i : dd[u.v]){
			ll wu = u.w + i.v;
			for(node v : a[i.t]){
				if(v.t + wu < dis[v.v]){
					dis[v.v] = v.t + wu;
					q.push({v.v, dis[v.v]});
				}
			}
		}
	}
}

inline void solve1(){
	while(q --){
		int x, y;
		cin >> x >> y;
		dij(x);
		cout << dis[y] + w[x] + w[y] << "\n";
	}
} 

inline void solve2(){
	ll huan = MAX;
	for(int i = 1;i <= m;i++){
		if(dd[i].size() == 2) huan = min(huan, dd[i][0].v + dd[i][1].v);
	}
	while(q --){
		int x, y;
		cin >> x >> y;
		ll ans = MAX;
		for(node u : dd[x]){
			for(node v : dd[y]){
				if(u.t == v.t) ans = min(ans, u.v + v.v);
				else ans = min(ans, u.v + v.v + w[x] + w[y] + huan);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k --){
			ll v, t;
			cin >> v >> t;
			a[i].push_back({v, t});// 记录地铁路线v出站时间 
			dd[v].push_back({t, i}); // 记录顶点进站时间和站编号 
		}
	}
	if(c == 20 || c == 21) solve2();
	else solve1();
	return 0;
}

