#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct p{
	int v;
	ll w;
};
vector<p> vc[501005];
struct pqz{
	int id;
	ll dis;
	bool operator < (const pqz &a) const{
		return dis > a.dis;
	}
};
int c, n, m, d, q, k[505];
ll w[500005], dis[50005];
bool f[50005];
int Dijk(int s, int t){
	priority_queue<pqz> pq;
	memset(dis, 0x3f, sizeof dis);
	memset(f, 0, sizeof f);
	dis[s] = 0;
	pq.push({s, 0});
	while(!pq.empty()){
		int x = pq.top().id, d = pq.top().dis; pq.pop();
		if(f[x]) continue;
		if(x == t) return dis[t];
		f[x] = 1;
		for(auto i : vc[x]){
			if(dis[i.v] < dis[x] + i.w) continue;
			dis[i.v] = dis[x] + i.w;
			if(!f[i.v]) pq.push({i.v, dis[i.v]});
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a, w;
			cin >> a >> w;
			vc[a].push_back({m + i, w});
			vc[m + i].push_back({a, w});
		}
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << Dijk(a, b) + w[a] + w[b] << '\n';
	}
	return 0;
}
/*

如果可以的话请问你能恨我吗 
如果可以的话请问你要恨我吗
如果可以的话请问你会恨我吗
如果可以的话太阳要升起来了
——久眯 & 诗岸 《太平天》 
*/
