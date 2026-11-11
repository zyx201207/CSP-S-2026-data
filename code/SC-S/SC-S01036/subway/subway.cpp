#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5, M = 505;
ll w[N];
ll dis[M][M];
struct edge{
	ll first, second;
};
vector<edge> e[M];
ll c, n, m, d, q;
void init(){
	for(int i=1; i<=m; ++i)for(int j=1; j<=m; ++j)dis[i][j] = 1e9+7;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	init();	
	for(int i=1; i<=m; ++i)cin >> w[i];
	for(int i=1; i<=n; ++i){
		int k;
		cin >> k;
		for(int j=1; j<=k; ++j){
			int a, t;
			cin >> a >> t;
			e[a].push_back({i,t});
		}
	}
	for(int i=1; i<=m; ++i){
		for(int j = 0; j < e[i].size(); ++j){
			for(int k = j+1; k < e[i].size(); ++k){
				int xx = min(e[i][j].first,e[i][k].first),yy =  max(e[i][j].first,e[i][k].first);
				dis[xx][yy] = min(dis[xx][yy], e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j){
			int xx = min(i,j),yy = max(i,j);
			for(int k=1; k<=n; ++k){
				int x1=min(i,k),y1=max(i,k);
				int x2 = min(j,k),y2=max(j,k);
				if(dis[xx][yy] > dis[x1][y1] + dis[x2][y2])dis[xx][yy] = dis[x1][y1] + dis[x2][y2];
			}
		}
	for(int i=1; i<=n; ++i)dis[i][i] = 0;
	while(q--){
		int x, y;
		cin >> x >> y;
		ll mn = INT_MAX;
		for(int i = 0; i < e[x].size(); ++i){
			for(int j=0; j < e[y].size(); ++j){
//				cout << e[x][i].second << ' ' << e[y][j].second << '\n';
//				cout << w[x] << ' ' << w[y] << '\n';
				int xx = min(e[x][i].first,e[y][j].first),yy =  max(e[x][i].first,e[y][j].first);
				mn = min(mn, dis[xx][yy] + e[x][i].second + w[x] + e[y][j].second + w[y]);
			}
		}
		cout << mn << '\n';
	}
	return 0;
}