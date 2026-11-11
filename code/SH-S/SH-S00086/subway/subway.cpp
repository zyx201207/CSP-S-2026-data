#include<bits/stdc++.h>
typedef long long ll;
const int N = 500 + 5,M = 5e5 + 5;
int w[M],k[N];
std::vector<int> a[N],t[N];
struct EDGE{int v;ll w;};
std::vector<EDGE> g[M];
struct DIS{
	int id;ll dis;
	bool operator<(const DIS &x)const{return dis > x.dis;}
};
ll dis[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int c,n,m,d,q;
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) std::cin >> w[i];
	for (int i = 1;i <= n;i++){
		std::cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1;j <= 2 * k[i];j++){
			if (j % 2 == 1) std::cin >> a[i][(j + 1) / 2];
			else std::cin >> t[i][j / 2];
		}
		for (int j = 1;j <= k[i];j++)
			for (int l = j + 1;l <= k[i];l++){
				g[a[i][j]].push_back({a[i][l],t[i][j] + t[i][l]});
				g[a[i][l]].push_back({a[i][j],t[i][j] + t[i][l]});
			}
	}
	while (q--){
		int x,y;std::cin >> x >> y;
		memset(dis,0x3f,sizeof(dis));
		std::priority_queue<DIS> pq;
		dis[x] = 0;pq.push({x,0});
		while (!pq.empty()){
			DIS H = pq.top();pq.pop();
			int u = H.id;
			if (H.dis != dis[u]) continue;
			for (EDGE vw : g[u]){
				int v = vw.v,w = vw.w;
				if (dis[u] + w < dis[v]){
					dis[v] = dis[u] + w;
					pq.push({v,dis[v]});
				}
			}
		}
		std::cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}
