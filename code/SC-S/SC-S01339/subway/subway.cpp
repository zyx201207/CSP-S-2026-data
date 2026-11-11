#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
//#define i128 __int128_t
const int N = 1500 + 5, M = 505;
int n, m, d, q;
int w[N];
int mxd;
vector<int> a[M], t[M];

vector<pair<int, int> > g[N * M];
int gd[M];
int getid(int u, int d){
	return d * (m + 1) + u;
}
int dist[N * M];
int dij(int st, int ed){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	fill(dist, dist + getid(m, mxd) + 1, inf);
	dist[st] = 0;
	pq.push({dist[st], st});
	while(!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();
		if(u == ed)return dist[u];
		if(dist[u] != d)continue;
		for(auto &[v, w] : g[u]){
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[ed];
}
bitset<N> vis[25];
bitset<N> tmp;
signed main(){
//	ios;
//    freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    int _c; cin >> _c;
	cin >> n >> m >> d >> q;
//	cout << q << "qq\n";
	for(int i = 1;i <= m;i ++)cin >> w[i];
	for(int i = 1;i <= n;i ++){
		int nsz; cin >> nsz;
//		cout << nsz << "\n";
		tmp.reset();
		a[i].resize(nsz + 1); t[i].resize(nsz + 1);
		for(int j = 1;j <= nsz;j ++){
			cin >> a[i][j] >> t[i][j];
			tmp[a[i][j]] = 1;
		}
		for(int j = 0;j <= d;j ++){
			if((tmp & vis[j]).count())continue;
			gd[i] = j;
			vis[j] |= tmp;
			break;
		}
	}
	for(int i = 1;i <= n;i ++){
//		cout << gd[i] << "\n";
	}
	mxd = *max_element(gd + 1, gd + n + 1) + 1;
//	cout << mxd << "\n";
	for(int i = 1;i <= n;i ++){
		int nsz = a[i].size() - 1;
		for(int j = 1;j <= nsz;j ++){
			int id = a[i][j];
//			
			g[getid(id, gd[i])].emplace_back(getid(id, mxd), t[i][j]);
			g[getid(id, mxd)].emplace_back(getid(id, gd[i]), t[i][j]);
			
			if(j < nsz){
				g[getid(id, gd[i])].emplace_back(getid(a[i][j + 1], gd[i]), 0);
				g[getid(a[i][j + 1], gd[i])].emplace_back(getid(id, gd[i]), 0);
			}
//			if(j > 1){
//				g[getid(a[i][j - 1], gd[i])].emplace_back(getid(id, gd[i]), 0);
//			}
		}
	}
	for(int i = 1;i <= q;i ++){
		int u, v; cin >> u >> v;
		int stu = getid(u, mxd), edv = getid(v, mxd);
//		cout << stu << " " << edv << "\n";
		cout << dij(stu, edv) + w[u] + w[v] << "\n";
	}
    return 0;
}
// g++ std.cpp -o std