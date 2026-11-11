#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

// n <= 500, 1 <= m <= k[i] <= 500000, 1 <= d <= 20, 1 <= q <= 100000
// tang ti

int n,m,k[505],d,Q,TEST,w[500005];
int dis[505][505];
vector <pair <int,int> > has[500005];
vector <int> a[505],t[505];

signed main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> TEST >> n >> m >> d >> Q;
	memset(dis,0x3f,sizeof dis);
	for (int i = 1;i <= m;++i)
		cin >> w[i];
	for (int i = 1;i <= n;++i){
		cin >> k[i];
		a[i].assign(k[i] + 5,0);
		t[i].assign(k[i] + 5,0);
		for (int j = 1;j <= k[i];++j)
			cin >> a[i][j] >> t[i][j],
			has[a[i][j]].push_back(make_pair(i,j));
	}
//	for (int i = 1;i <= m;++i){
//		cerr << " station " << i << " has subway: \n";
//		cerr << "    ";
//		for (int j = 0;j < has[i].size();++j) cerr << has[i][j].fi << ' '; cerr << '\n';
//		for (int j = 0;j < has[i].size();++j) cerr << has[i][j].se << ' ';
//		cerr << '\n';
//	}
	// 难受，CCF 啥时候搞成 -std=c++17 啊，c++23 都出了还准备用老年机吗
	for (int p = 1;p <= m;++p){
		int s = has[p].size();
		for (int i = 0;i < s;++i) for (int j = i + 1;j < s;++j){
			int x = has[p][i].fi,y = has[p][j].fi;
			int w = t[x][has[p][i].se] + t[y][has[p][j].se];
//			cerr << x << ' ' << y << ' ' << w << '\n';
			dis[x][y] = dis[y][x] = min(dis[x][y],w);
		}
	}
	for (int i = 1;i <= n;++i)
		dis[i][i] = 0;
//	for (int i = 1;i <= n;++i) for (int j = 1;j <= n;++j)
//		cerr << i << ' ' << j << ' ' << dis[i][j] << '\n';
	// 想半天突然想起来保证了 d <= 20
	for (int k = 1;k <= n;++k) for (int i = 1;i <= n;++i) for (int j = 1;j <= n;++j)
		dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while (Q--){
		int u,v; cin >> u >> v;
		int s1 = has[u].size(),s2 = has[v].size();
		int ans = 4e18;
//		cerr << " Que " << u << ' ' << v << '\n';
		for (int i = 0;i < s1;++i) for (int j = 0;j < s2;++j){
			int x = has[u][i].fi,y = has[v][j].fi;
//			cerr << "	" << " check " << x << ' ' << y << ' ' << dis[x][y] << ' ' << t[x][has[u][i].se] << ' ' << t[y][has[v][j].se] << '\n';
//			cerr << "	" << u << ' ' << v << ' ' << has[u][i].se << ' ' << has[v][j].se << '\n';
			ans = min(ans,dis[x][y] + t[x][has[u][i].se] + t[y][has[v][j].se]);
		}
		ans += w[u] + w[v];
		cout << ans << '\n';
	}
}
